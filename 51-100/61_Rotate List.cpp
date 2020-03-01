/*
Given a linked list, rotate the list to the right by k places, where k is non-negative.

Example 1:

Input: 1->2->3->4->5->NULL, k = 2
Output: 4->5->1->2->3->NULL
Explanation:
rotate 1 steps to the right: 5->1->2->3->4->NULL
rotate 2 steps to the right: 4->5->1->2->3->NULL
Example 2:

Input: 0->1->2->NULL, k = 4
Output: 2->0->1->NULL
Explanation:
rotate 1 steps to the right: 2->0->1->NULL
rotate 2 steps to the right: 1->2->0->NULL
rotate 3 steps to the right: 0->1->2->NULL
rotate 4 steps to the right: 2->0->1->NULL
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
    ListNode* rotateRight(ListNode* head, int k) {
        
        // corner case
        if (k == 0 || !head)
            return head;
        
        // k may bigger than head.size()
        // whole list rotate will not change list order
        // if k > n, only needs to handle h%n part
        // ordered three steps:
        // 1. get current node as return value (use last->next)
        // 2. last point to NULL
        // 3. end node point to original head
        int n = 1;
        ListNode* end = head;
        while (end->next) {
            end = end->next;
            n++;
        }
        
        k = k % n;
        if (k == 0)
            return head;
        
        // end point to head
        end->next = head;
        
        // locate k-1_th node
        ListNode* last = head;
        for (int i = 1; i <= n-k-1; i++)
            last = last->next;
        
        // current node
        ListNode* curr = last->next;

        // last point to null
        last->next = nullptr;
        
        return curr;
    }
};
