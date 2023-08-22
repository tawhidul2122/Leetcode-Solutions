// https://leetcode.com/problems/clone-graph

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return node;
        
        unordered_map<Node*, Node*> old2new;
        
        old2new[node] = new Node(node->val);
        
        queue<Node*> q;
        
        //visit the old graph
        q.push(node);
        
        while(!q.empty()){
            Node* cur = q.front(); q.pop();
            
            for(Node* nei : cur->neighbors){
                if(old2new.find(nei) != old2new.end()){
                    //create the edge
                    old2new[cur]->neighbors.push_back(old2new[nei]);
                    continue;
                }
                old2new[nei] = new Node(nei->val);
                //visit the old graph
                q.push(nei);
                //create the edge
                old2new[cur]->neighbors.push_back(old2new[nei]);
            }
        }
        
        return old2new[node];
    }
};