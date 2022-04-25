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
    void flatten(TreeNode* root) {
        if(!root)
            return;
        vector<TreeNode*> nodes;
        preorder(root, nodes);
      
        int size = nodes.size();
        TreeNode* node = root;
        for(int i = 1; i < size; i++){
            node->left = nullptr;
            node->right = nodes[i];
    
            node = node->right;
        }
    }
    void preorder(TreeNode* root, vector<TreeNode*>& nodes){
        nodes.push_back(root);
        if(root->left)
            preorder(root->left, nodes);
        if(root->right)
            preorder(root->right, nodes);
    }
};
