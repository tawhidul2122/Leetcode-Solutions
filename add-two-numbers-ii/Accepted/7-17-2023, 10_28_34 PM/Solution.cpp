// https://leetcode.com/problems/add-two-numbers-ii

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> v1, v2;
        ListNode* cur = l1;
        while(cur){
            v1.insert(v1.begin(), cur->val);
            cur = cur->next;
        }
        
        cur = l2;
        while(cur){
            v2.insert(v2.begin(), cur->val);
            cur = cur->next;
        }
        int newSize = max(v1.size(), v2.size()) + 1;
        v1.resize(newSize);
        v2.resize(newSize);
        for(int i = 0; i < newSize-1; i++){
            v1[i] += v2[i];
            if(v1[i] >= 10){
                v1[i]-=10;
                v1[i+1]++;
            }
        }
        ListNode* head = new ListNode();
        cur = head;
        int idx = newSize-1;
        while(idx >= 0 && v1[idx] == 0){
            idx--;
        }
        for(; idx >= 0; idx--){
            cur->val = v1[idx];
            if(idx > 0){
                cur->next = new ListNode();
                cur = cur->next;
            }
        }
        
        return head;
    }
};