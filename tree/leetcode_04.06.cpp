/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        vector<TreeNode*> vt;
        inorderSuccessor1(vt, root);
        for(int i = 0; i < vt.size(); i++){
            if(vt[i] == p && i != vt.size()-1)
                return vt[i+1];
        }
        return NULL;
    }
    void inorderSuccessor1(vector<TreeNode*>& vt, TreeNode* root){
        if(root->left)
            inorderSuccessor1(vt, root->left);
        vt.push_back(root);
        if(root->right)
            inorderSuccessor1(vt, root->right);
    }

};
