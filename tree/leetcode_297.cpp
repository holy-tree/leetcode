/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)
            return "n";
        return to_string(root->val) + "|" + serialize(root->left) + "|" + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 1)
            return NULL;

        TreeNode* rt;
        int index = 0;
        while(data[index] != '|')
            index++;
        rt = new TreeNode(atoi(data.substr(0, index).c_str()));
        
        stack<TreeNode*> st;
        st.push(rt);

        for(int i = data.find('|')+1; i < data.size(); i++){
            TreeNode* node;
            int j = 0;
            while(data[j+i] != '|' && j+i < data.size())
                j++;
            string temp = data.substr(i, j);
            if(temp != "n")
                node = new TreeNode(atoi(temp.c_str()));
            else
                node = new TreeNode(1001);
            i = i + j;

            TreeNode* root = st.top();


            if(!root->left){
                root->left = node;
                
                if(node->val != 1001)
                    st.push(node);
            }
            else if(!root->right){
                root->right = node;
                st.pop();
                if(node->val != 1001)
                    st.push(node);
            }
            
        }
        
        delete_leaf(rt);
        
        return rt;
    }
    void delete_leaf(TreeNode* root){
        if(root->left->val == 1001)
            root->left = NULL;
        if(root->right && root->right->val == 1001)
            root->right = NULL;
        if(root->left)
            delete_leaf(root->left);
        if(root->right)
            delete_leaf(root->right);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
