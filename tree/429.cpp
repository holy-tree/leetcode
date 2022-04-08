/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;

        if(root == NULL)
            return ans;

        queue<Node*> que;
        que.push(root);
        ans.push_back(vector<int>{root->val});

        if(root->children.empty())
            return ans;

        int n;
        while(!que.empty()){
            n = que.size();
            vector<int> temp;
            for(int i = 0; i < n; i++){
                Node* node = que.front();
                que.pop();
                for(Node* n : node->children){
                    temp.push_back(n->val);
                    if(!n->children.empty())
                        que.push(n);
                }
            }
            ans.push_back(temp);
        }


        return ans;



    }
};
