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
    bool isSymmetric(TreeNode* root) {
        // vector<int> vt;
        // ldr(root, vt);
        // if(vt.size() % 2 == 0)
        //     return false;
        // for(int i = 0; i < vt.size()/2; i++){
        //     if(vt[i] != vt[vt.size()-i-1])
        //         return false;
        // }
        // return true;
        return isSymmetric1(root->left, root->right);
    }
    bool isSymmetric1(TreeNode* root1, TreeNode* root2){
        if(!root1 && !root2)
            return true;
        if((root1 && !root2) || (!root1 && root2))
            return false;
        if(root1->val != root2->val)
            return false;
        return isSymmetric1(root1->left, root2->right) && isSymmetric1(root1->right, root2->left);
    }
    // void ldr(TreeNode* root, vector<int>& vt){
    //     if(root->left)
    //         ldr(root->left, vt);
    //     vt.push_back(root->val);
    //     if(root->right)
    //         ldr(root->right, vt);
    // }
};
