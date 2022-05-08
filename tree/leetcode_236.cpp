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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int l = findNode(root->left, p, q);
        int r = findNode(root->right, p, q);
        if(l == 1 && r == 1)
            return root;
        if((root == p || root == q) && (l == 1 || r == 1))
            return root;
        if(l == 2)
            return lowestCommonAncestor(root->left, p, q);
        if(r == 2)
            return lowestCommonAncestor(root->right, p, q);
        return NULL;
    }
    int findNode(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root)
            return 0;
        if(root == p || root == q)
            return findNode(root->left, p, q) + findNode(root->right, p, q) + 1;
        return findNode(root->left, p, q) + findNode(root->right, p, q);
    }
};
