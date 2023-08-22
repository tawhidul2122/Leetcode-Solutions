// https://leetcode.com/problems/maximum-depth-of-binary-tree

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
  int maxDepth(TreeNode *root) {
    int depth = 0;
    depth = findMaxDepth(root, depth);

    return depth;
  }

 private:
  int findMaxDepth(TreeNode *node, int depth) {
    if (node == nullptr) {
      return depth;
    }

    ++depth;
    return std::max(findMaxDepth(node->left, depth),
                    findMaxDepth(node->right, depth));
  }
};

