/*

Given a singly linked list, determine if it is a palindrome.

Example 1:

Input: 1->2
Output: false
Example 2:

Input: 1->2->2->1
Output: true
Follow up:
Could you do it in O(n) time and O(1) space?

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
    bool isPalindrome(ListNode* head) {
        // split into two parts, then reverse one and compare
        if (!head)
            return true;
        
        // use slow and fast pointer to find mid-point
        ListNode* slow = head;
        ListNode* fast = head;
        
        // if we set slow as mid-point, must check fast->next->next
        // if we set prev of slow as mid-point, may not need check fast->next->next
        while (fast && fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // point cur to mid-point
        ListNode* cur = slow->next;
        slow->next = nullptr;
        
        ListNode* prev = nullptr;
        while (cur) {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        
        // prev hold the head of reversed list
        while (head && prev) {
            // cout << head->val << " " << prev->val << endl;
            if (head->val != prev->val)
                return false;
            head = head->next;
            prev = prev->next;
        }
        
        return true;
    }
};
