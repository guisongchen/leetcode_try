/*
Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:

Given n will always be valid.

Follow up:

Could you do this in one pass?
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 
// keypoints:
// use one loop to solve this: consider using two pointer
// 1. next pointer is N-1 steps after cur pointer
// 2. then cur and next pointer move step by step
// 3. when next pointer reach end, cur pointer is Nth node from end of list

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* cur = head;
        ListNode* next = head;
        
        // move next pointer n steps after cur
        // notice n is always valid, so we don't check next pointer here
        for (int i = 1; i < n; ++i) { // start from i = 1 here
            next = next->next;
        }
        
        // move step by step, until next reach end
        
        // corner case: remove first node
        if (!next->next)
            return head->next;
        
        ListNode* prev = cur;
        while (next->next) {
            prev = cur;
            cur = cur->next;
            next = next->next;
        }
        
        // delete N-th node from end of list
        prev->next = cur->next;
        
        return head;
    }
};
