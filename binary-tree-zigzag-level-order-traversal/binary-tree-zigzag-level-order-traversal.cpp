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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> results;
        // base case
        if(root == nullptr) return results;
        bool isLefttoRight = true;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> levelResult;
            int currQSize = q.size();
            for(int i = 0; i < currQSize; i++){
                TreeNode* tempNode = q.front();
                q.pop();
                levelResult.push_back(tempNode->val);
                if(tempNode->left) q.push(tempNode->left);
                if(tempNode->right)q.push(tempNode->right);
            }
            if(!isLefttoRight) 
                reverse(levelResult.begin(), levelResult.end());
            results.push_back(levelResult);
            isLefttoRight = !isLefttoRight;
        }
        return results;
    }
};