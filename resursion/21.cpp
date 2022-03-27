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
//时间复杂度O(n+m)
//空间复杂度O(n+m)

//循环  耗时短
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* list;
        if(!list1)
            return list2;
        if(!list2)
            return list1;
        if(list1->val <= list2->val)
            list = list1;
        else{
            ListNode* temp = list1;
            list1 = list2;
            list2 = temp;
            list = list1;
        }
            
        while(list2){
            if(list2->val >= list1->val && (!list1->next || list2->val <= list1->next->val) ){
                ListNode* temp = list2;
                list2 = list2->next;
                temp->next = list1->next;
                list1->next = temp;
            }
            else
                list1 = list1->next;
        }

        return list;


    }
};

//递归  耗时较长
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1)
            return list2;
        if(!list2)
            return list1;
        if(list1->val <= list2->val){
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        else{
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};



