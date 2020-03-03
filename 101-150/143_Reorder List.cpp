/*

Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You may not modify the values in the list's nodes, only nodes itself may be changed.

Example 1:

Given 1->2->3->4, reorder it to 1->4->2->3.
Example 2:

Given 1->2->3->4->5, reorder it to 1->5->2->4->3.

*/


// keypoints: split into two lists then relink
// three steps:
// 1. find mid node, split into two parts
// 2. reverse second part
// 3. insert reversed second part into first part

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
    void reorderList(ListNode* head) {
        // first thought: double pointer
        // three steps:
        // 1. find mid node, split into two parts
        // 2. reverse second part
        // 3. insert reversed second part into first part
        
        if (!head)
            return;
        
        // find mid-point, slow point to mid
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        // spilt into two parts [begin, mid], [mid->next, end]
        ListNode* cur = slow->next; // mid->next
        slow->next = nullptr; // begin->mid
        
        // reverse list  
        ListNode* prev = nullptr;
        while (cur) {
            ListNode* next = cur->next;
            cur->next = prev;
            
            prev = cur;
            cur = next;
        }
        
        // notice: prev pointer is the head pointer of reversed list
        
        // insert reversed list
        // since head not change, we use head directly
        while (head && prev) {
            // insert from reversed list
            ListNode* next = head->next;
            ListNode* next_reserve = prev->next;
            head->next = prev;
            prev->next = next;
            
            head = next;
            prev = next_reserve;
        }
        
    }
};
