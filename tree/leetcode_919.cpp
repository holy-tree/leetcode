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
class CBTInserter {
public:
    TreeNode* root;
    queue<TreeNode*> q;
    CBTInserter(TreeNode* root) {
        this->root = root;
    }
    
    int insert(int val) {
        if(q.empty())
            q.push(this->root);
        while(!q.empty()){
            TreeNode* temp = q.front();
            if(!temp->left){
                temp->left = new TreeNode(val);
                return temp->val;
            }
            else if(!temp->right){
                temp->right = new TreeNode(val);
                return temp->val;
            }
            else{
                q.pop();
                q.push(temp->left);
                q.push(temp->right);
            }
        }
        return 0;
    }
    
    TreeNode* get_root(){
        return root;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */
