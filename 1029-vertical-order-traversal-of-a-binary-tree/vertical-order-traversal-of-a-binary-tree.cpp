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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // Map to store nodes based on
        // vertical and level information
        map<int, map<int, multiset<int>>> nodes;
        // Queue for BFS traversal, each
        // element is a pair containing node
        // and its vertical and level information
        queue<pair<TreeNode*,pair<int,int>>> bfs;
        bfs.push({root,{0,0}});
        // BFS traversal
        while(!bfs.empty())
        {
            // Retrieve the node and its vertical
            // and level information from
            // the front of the queue
            auto p = bfs.front();
            bfs.pop();
            TreeNode* temp = p.first;
            // Extract the vertical and level information
            // x -> vertical
            int x = p.second.first;
            // y -> level
            int y = p.second.second;
            // Insert the node value into the
            // corresponding vertical and level
            // in the map
            nodes[x][y].insert(temp->val);
            if(temp->left){
                bfs.push({temp->left,{x-1,y+1}});
            }
            if(temp->right){
                bfs.push({temp->right,{x+1,y+1}});
            }
        }
        vector<vector<int>> ans;
        for(auto p:nodes){
               // Insert node values
                // into the column vector
            vector<int> col;
            for(auto q: p.second){
                col.insert(col.end(),q.second.begin(),q.second.end());
            }
            // Add the column vector
            // to the final result
            ans.push_back(col);
        }
        return ans;
    }
};