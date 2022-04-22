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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)
            return ans;

        queue<TreeNode*> q;

        q.push(root);
        int num = 1;
        int newnum;
        while(!q.empty()){
            vector<int> vt;
            newnum = 0;
            while(num--){
                TreeNode* node = q.front();
                vt.push_back(node->val);
                q.pop();
                if(node->left){
                    q.push(node->left);
                    newnum++;
                }
                if(node->right){
                    q.push(node->right);
                    newnum++;
                }
            }
            num = newnum;
            ans.push_back(vt);
        }

        return ans;

    }
};
