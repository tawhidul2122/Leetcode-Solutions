// https://leetcode.com/problems/binary-tree-inorder-traversal

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
public class Solution {
    List<Integer> result = new ArrayList<Integer>();
 
    public List<Integer> inorderTraversal(TreeNode root) {
        if(root !=null){
            helper(root);
        }
 
        return result;
    }
 
    public void helper(TreeNode p){
        if(p.left!=null)
            helper(p.left);
 
        result.add(p.val);
 
        if(p.right!=null)
            helper(p.right);
    }
}