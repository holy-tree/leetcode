/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        // vector<ListNode*> vt;
        // ListNode* node = head;
        // while(node){
        //     if(find(vt.begin(), vt.end(), node) != vt.end())
        //         return true;
        //     vt.push_back(node);
        //     node = node->next;
        // }
        // return false;
        unordered_set<ListNode*> seen;
        while (head != nullptr) {
            if (seen.count(head)) {
                return true;
            }
            seen.insert(head);
            head = head->next;
        }
        return false;
    }
};
