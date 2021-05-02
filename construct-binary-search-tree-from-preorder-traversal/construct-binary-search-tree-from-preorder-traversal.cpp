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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.empty()) return nullptr;
        int rootValue = preorder[0];
        vector<int> smaller, greater;
        for(int i = 1; i < (int) preorder.size(); i++){
            if(preorder[i] < rootValue) smaller.push_back(preorder[i]);
            else greater.push_back(preorder[i]);
        }
        
        TreeNode* root = new TreeNode(rootValue);
        root->left = bstFromPreorder(smaller);
        root->right = bstFromPreorder(greater);
        return root;
    }
};