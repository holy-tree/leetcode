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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return resursion(new TreeNode(preorder[0]), preorder, inorder);
    }
    TreeNode* resursion(TreeNode* root, vector<int>& preorder, vector<int>& inorder){
        if(preorder.size() == 1 && inorder.size() == 1)
            return new TreeNode(preorder[0]);
        int i = 0;
        while(inorder[i] != preorder[0])
            i++;
        if(i > 0){
            vector<int> vt1;
            vt1.assign(preorder.begin()+1, preorder.begin()+1+i);
            vector<int> vt2;
            vt2.assign(inorder.begin(), inorder.begin()+i);
            root->left = resursion(new TreeNode(preorder[1]), vt1, vt2);
        }
        if(i < preorder.size()-1){
            vector<int> vt3;
            vt3.assign(preorder.begin()+i+1, preorder.end());
            vector<int> vt4;
            vt4.assign(inorder.begin()+i+1, inorder.end());
            root->right = resursion(new TreeNode(preorder[i+1]), vt3, vt4);
        }
        return root;
    }
};
