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
    int ans = -1000000;
    int maxPathSum(TreeNode* root) {
        getMax(root);
        return ans;
    }
    int getMax(TreeNode* root){
        if(!root)
            return 0;
        int left = getMax(root->left);
        left = left > 0 ? left : 0;
        int right = getMax(root->right);
        right = right > 0 ? right : 0;
        ans = max(ans, left + right + root->val);
        return max(left+root->val, right+root->val);
    }
};
