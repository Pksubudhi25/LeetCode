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
    bool isValidBST(TreeNode* root) {
        return util(root, LLONG_MIN, LLONG_MAX); // Use LLONG_MIN and LLONG_MAX
    }
    
    bool util(TreeNode* root, long long mini, long long maxi) {
        if (!root) return true; // Base case: Null nodes are valid
        if (root->val <= mini || root->val >= maxi) // Check BST condition
            return false;
        // Recurse for left and right subtrees with updated ranges
        return util(root->left, mini, root->val) && 
               util(root->right, root->val, maxi);
    }
};