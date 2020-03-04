/*

Reverse a singly linked list.

Example:

Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL
Follow up:

A linked list can be reversed either iteratively or recursively. Could you implement both?

*/

// keypoints:
// 1. create a newHead pointer as return pointer
//   --> this pointer will move from newHead to head to tail then return
// 2. from head to tail, move node ahead of newHead one by one
//   --> notice newHead also move from head to tail
// 3. head of original list also move from head to tail
//   --> when head point to tail(nullptr), finish and return
// 4. unlike swap nodes, we only need to link head->next to newHead
// 5. since head and newHead update each iteration, won't worry we will lost


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
        
        ListNode* newHead = nullptr;
        while (head) {
            // save to update head pointer
            ListNode* next = head->next; 
            
            // reverse
            head->next = newHead;
            
            // update pointer of new and old list
            newHead = head;
            head = next;
        }
        
        return newHead;
    }
};
