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
    bool pathSumRecursion(TreeNode* root,int curSum,int targetSum){
        if(root == NULL ) return false;
        // If current node is a leaf node check whether currrent sum equals to target sum
        if(root->left == NULL && root->right == NULL)
        {
            return curSum + root->val == targetSum;
        }

        return (pathSumRecursion(root->left,curSum+root->val,targetSum) || pathSumRecursion(root->right,curSum+root->val,targetSum));
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        // Initially the curSum is 0
        return pathSumRecursion(root,0,targetSum);
    }
};