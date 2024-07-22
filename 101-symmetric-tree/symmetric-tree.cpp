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
    // Function to check if
    // two subtrees are symmetric
    bool isSymmetricUtil(TreeNode* root1,TreeNode* root2){
        // Base Case
        // If both halves are null it is symmetric
        // If only one half is null it is not symmetric
        // Check if either subtree is NULL
        if(root1 == NULL || root2 == NULL)
             // If one subtree is NULL, the other
            // must also be NULL for symmetry
            return root1 == root2;
        
        // Check if the data in the current nodes is equal
        // and recursively check for symmetry in subtrees
        return((root1->val == root2->val) && isSymmetricUtil(root1->left,root2->right) && isSymmetricUtil(root1->right,root2->left));
    }
    bool isSymmetric(TreeNode* root) {
            // An empty tree is
            // considered symmetric
        if(!root) return true;

        // Call the utility function
        // to check symmetry of subtrees
        return isSymmetricUtil(root->left,root->right);
    }
};