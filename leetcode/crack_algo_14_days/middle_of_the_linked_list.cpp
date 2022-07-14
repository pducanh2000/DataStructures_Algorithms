//https://leetcode.com/problems/middle-of-the-linked-list/

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
    ListNode* middleNode(ListNode* head) {
        ListNode* traverse;
        traverse = head;
        int count=1;
        while(traverse->next != nullptr){
            traverse = traverse->next;
            count++;
        }
        int middle = count/2;
        traverse = head;
        while(middle>0){
            traverse = traverse->next;
            middle--;
        }
        return traverse;
    }
};
