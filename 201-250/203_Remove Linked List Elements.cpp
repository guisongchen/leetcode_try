/*

Remove all elements from a linked list of integers that have value val.

Example:

Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5

*/

// keypoints: use deamon node to protect head(in case head is removed)

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
    ListNode* removeElements(ListNode* head, int val) {
        
        // in case head is null
        if (!head)
            return head;
        
        // now head is sure valid
        ListNode deamon(0);
        deamon.next = head; // use deamon next to track head, whereeven head switched
        ListNode* prev = &deamon;
        
        while (prev) {
            if (prev->next && prev->next->val == val) {
                prev->next = prev->next->next;
            } else {
                prev = prev->next;
            }
        }
        
        return deamon.next;
    }
};
