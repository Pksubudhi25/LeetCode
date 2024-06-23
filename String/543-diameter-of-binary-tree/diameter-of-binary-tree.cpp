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
    // Optimized function to calculate the diameter of the tree
pair<int, int> diameter_and_height(TreeNode* node) {
    if (!node) return {0, 0};  // {diameter, height}

    // Recursively find the diameter and height of the left subtree
    pair<int, int> left = diameter_and_height(node->left);
    // Recursively find the diameter and height of the right subtree
    pair<int, int> right = diameter_and_height(node->right);

    // Current node's height is 1 + max of left height and right height
    int current_height = 1 + max(left.second, right.second);

    // Diameter passing through the current node
    int current_diameter = left.second + right.second;

    // Maximum diameter so far is the maximum of current diameter, left diameter, and right diameter
    int max_diameter = max(current_diameter, max(left.first, right.first));

    return {max_diameter, current_height};
}

// Function to calculate the diameter of the binary tree
int diameterOfBinaryTree(TreeNode* root) {
    return diameter_and_height(root).first;
}
};