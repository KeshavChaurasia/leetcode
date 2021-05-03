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
class BSTIterator {
    queue<int>  inorderElements;
public:
    void inorder(TreeNode* root){
        // base case
        if(root == nullptr) return;
        inorder(root->left);
        inorderElements.push(root->val);
        inorder(root->right);
    } 
    BSTIterator(TreeNode* root) {
        this->inorder(root);
    }
    
    int next() {
        if(!inorderElements.empty()){
            int temp = inorderElements.front();
            inorderElements.pop();
            return temp;
        } else {
            return -1;
        }
    }
    
    bool hasNext() {
        if(!inorderElements.empty()) return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */