//https://leetcode.com/problems/merge-two-sorted-lists
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1==nullptr) return list2;
        if (list2==nullptr) return list1;
        
        ListNode* ans;
        if(list1->val < list2->val){
            ans= list1;
            list1 = list1->next;
        }
        else{
            ans = list2;
            list2 = list2->next;
        }
        ListNode* traversal = ans;
        while(list1 && list2){
            if(list1->val < list2->val){
                traversal->next = list1;
                list1 = list1->next;
            }
            else{
                traversal->next = list2;
                list2 = list2->next;
            }
            traversal = traversal->next;
        }
        if (list1){
            traversal->next = list1;
        }
        else{
            traversal->next = list2;
        }
       
        return ans;
    }
};
