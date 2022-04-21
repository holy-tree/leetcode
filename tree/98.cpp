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
    bool isValidBST(TreeNode* root) {
        vector<int> vt;
        dfs(root, vt);
        for(int i = 1; i < vt.size(); i++){
            if(vt[i] <= vt[i-1])
                return false;
        }
        return true;
    }
    void dfs(TreeNode* root, vector<int>& vt){    
        if(root->left)
            dfs(root->left, vt);
        vt.push_back(root->val);
        if(root->right)
            dfs(root->right, vt);
    }
};
