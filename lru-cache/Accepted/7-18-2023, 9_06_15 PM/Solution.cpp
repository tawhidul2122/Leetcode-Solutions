// https://leetcode.com/problems/lru-cache

class DLinkedNode{
public:
    int key;
    int value;
    DLinkedNode *prev, *post;
    DLinkedNode() : key(0), value(0), prev(NULL), post(NULL) {};
    DLinkedNode(int k, int v){
        this->key = k;
        this->value = v;
        this->prev = NULL;
        this->post = NULL;
    };
};

class LRUCache {
public:
    map<int, DLinkedNode*> cache; //from key to node
    int count, capacity;
    DLinkedNode *head, *tail;

    void addNode(DLinkedNode* node){
        //add to head
        node->prev = head;
        node->post = head->post;

        head->post->prev = node;
        head->post = node;
    };

    void removeNode(DLinkedNode* node){
        DLinkedNode *prev = node->prev, *post = node->post;

        // node->prev = NULL; //this will set prev to NULL?
        // node->post = NULL;

        prev->post = post;
        post->prev = prev;

    };

    void moveToHead(DLinkedNode* node){
        removeNode(node);
        addNode(node);
    };

    DLinkedNode* popTail(){
        DLinkedNode* node = tail->prev;
        removeNode(node);
        return node;
    };
    
    LRUCache(int capacity) {
        this->count = 0;
        this->capacity = capacity;
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->post = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        DLinkedNode* node = cache[key];
        if(node == NULL){
            return -1;
        }
        moveToHead(node);
        return node->value;
    }
    
    void put(int key, int value) {
        DLinkedNode* node = cache[key];
        if(node == NULL){
            node = new DLinkedNode(key, value);
            cache[key] = node;
            addNode(node);
            ++count;
            if(count > capacity){
                DLinkedNode* last = popTail();
                cache.erase(cache.find(last->key));
                --count;
            }
        }else{
            node->value = value;
            moveToHead(node);
        }
    }
};
