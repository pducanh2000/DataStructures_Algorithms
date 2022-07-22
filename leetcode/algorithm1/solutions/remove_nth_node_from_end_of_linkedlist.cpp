//https://leetcode.com/problems/remove-nth-node-from-end-of-list/
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* traversal;
        traversal = head;
        int count = 1;
        if (head->next == nullptr && n==1){
            return nullptr;
        }
        while(traversal->next != nullptr){
            traversal = traversal->next;
            count ++;
        }
        int k = count -n;
        if (k==0){
            return head->next;
        }
        traversal = head;
        while(--k){
            traversal = traversal->next;
        }
	ListNode *tmp = traversal->next; 
        traversal->next = traversal->next->next;
	delete(tmp);
        return head;
    }
};

// Update an effcient solution using two pointers  
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* curr = new ListNode();
        curr->next = head;
        ListNode* fast = curr;
        ListNode* slow = curr;

        int k = n;

        while(k--){
            fast = fast->next;
        }

        while(fast->next != NULL){
            slow = slow->next;
            fast = fast->next;
        }

        slow->next = slow->next->next;

        return curr->next;

    }
};
// A Cleancode C++ recursive solution O(n)
int Count=0;
ListNode* removeNthFromEnd(ListNode* head, int n) {
	if(!head)return nullptr;
    head->next=removeNthFromEnd(head->next,n);
    Count++;
    if(Count==n){
        if(head->next)return head->next;
        return nullptr;
    }
    return head;
}
