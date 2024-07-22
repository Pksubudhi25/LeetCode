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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        int ans = 0;
        queue<pair<TreeNode*, unsigned long long>> q; // Use unsigned long long for positions
        q.push({root, 0});

        while (!q.empty()) {
            int size = q.size();
            unsigned long long mmin = q.front().second; // The minimum position in the current level
            unsigned long long first, last;

            for (int i = 0; i < size; i++) {
                unsigned long long cur_pos = q.front().second - mmin;
                TreeNode *node = q.front().first;
                q.pop();
                
                if (i == 0) first = cur_pos; // First node's position in the level
                if (i == size - 1) last = cur_pos; // Last node's position in the level
                
                if (node->left)
                    q.push({node->left, 2 * cur_pos + 1}); // Position for left child
                if (node->right)
                    q.push({node->right, 2 * cur_pos + 2}); // Position for right child
            }

            ans = max(ans, int(last - first + 1)); // Calculate the width of the current level
        }

        return ans;
    }
};