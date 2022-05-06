/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head)
            return head;
        if(!head->next)
            return head;
        
        ListNode* fast = head;
        ListNode* mid = head;
        ListNode* temp;
        while(fast){
            fast = fast->next;
            if(fast)
                fast = fast->next;
            temp = mid;
            mid = mid->next;
        }
        temp->next = nullptr;

        return mergeList(sortList(head), sortList(mid));
    }
    ListNode* mergeList(ListNode* list1, ListNode* list2){
        if(!list1)
            return list2;
        if(!list2)
            return list1;
        if(list1->val <= list2->val){
            list1->next = mergeList(list1->next, list2);
            return list1;
        }
        else{
            list2->next = mergeList(list1, list2->next);
            return list2;
        }
    }
};
