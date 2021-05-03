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
    void inOrderTraversal(TreeNode* root, vector<int> & nums){
        if(root == nullptr) return;
        inOrderTraversal(root->left, nums);
        nums.push_back(root->val);
        inOrderTraversal(root->right, nums);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> nums;
        inOrderTraversal(root, nums);
        for(int i = 0; i < nums.size(); i++){
            if(i == k-1) return nums[i];
        }
        return -1;
    }
};