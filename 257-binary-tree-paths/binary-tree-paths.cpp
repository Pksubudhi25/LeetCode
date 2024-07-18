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
    
    void Paths(TreeNode* root,string path,vector<string>& V )
    {
        if(!root )return ;

        path+=to_string(root->val);
        
        if(!root->left && !root->right)              
            V.push_back(path);
        
        path+="->";
        Paths(root->left,path,V);
        Paths(root->right,path,V);

    }



    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> V;
        Paths(root,"",V);
        return V;
    }
};