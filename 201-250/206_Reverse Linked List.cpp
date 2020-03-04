/*

Reverse a singly linked list.

Example:

Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL
Follow up:

A linked list can be reversed either iteratively or recursively. Could you implement both?

*/

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
    ListNode* reverseList(ListNode* head) {
        // old trick, use deamon node
        if (!head)
            return head;
        
        ListNode* prev = nullptr;
        while (head) {
            // re-link between prev and cur
            ListNode* next = head->next; 
            head->next = prev;
            // update
            prev = head;
            head = next;
        }
        
        return prev;
    }
};
