// https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> qNode;
        queue<int> qLevel;
        int maxLevel = 0, maxSum = INT_MIN;
        int lastLevel = 1, lastSum = 0;
        TreeNode* node;
        
        qNode.push(root);
        qLevel.push(lastLevel);
        
        while(!qNode.empty()){
            node = qNode.front();
            // cout << node->val << endl;
            qNode.pop();
            
            lastLevel = qLevel.front();
            qLevel.pop();
            
            lastSum += node->val;
            
            if(node->left){
                qNode.push(node->left);
                qLevel.push(lastLevel+1);
            }
            
            if(node->right){
                qNode.push(node->right);
                qLevel.push(lastLevel+1);
            }
            
            //clean up before entering new level
            if(lastLevel != qLevel.front()){
                if(lastSum > maxSum){
                    maxSum = lastSum;
                    maxLevel = lastLevel;
                }
                lastSum = 0;
            }
        }
        
        return maxLevel;
    }
};
