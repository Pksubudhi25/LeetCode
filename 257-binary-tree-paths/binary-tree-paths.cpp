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
    
    void pathFinder(TreeNode*root, string currentPath, vector<string>& res){
        if(!root) return;
        if(root->left == NULL &&  root->right==NULL){
            currentPath += to_string(root->val);
            res.push_back(currentPath);
            return;
        }

        currentPath += to_string(root->val)+"->";
        
        if(root->left) pathFinder(root->left,currentPath,res);
        if(root->right) pathFinder(root->right,currentPath,res);
        
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        pathFinder(root,"",res);
        return res;
    }
};