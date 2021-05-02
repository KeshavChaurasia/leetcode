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
    void rangeSumBSTHelper(TreeNode* node, int low, int high, int & rangeSum){
        // check if the node is null
        if(node == nullptr) return;
        if(node->val >= low && node->val <= high) rangeSum += node->val;
        rangeSumBSTHelper(node->left, low, high, rangeSum);
        rangeSumBSTHelper(node->right, low, high, rangeSum);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        int rangeSum = 0;
        rangeSumBSTHelper(root, low, high, rangeSum);
        return rangeSum;
    }
};