/*

Sort a linked list in O(n log n) time using constant space complexity.

Example 1:

Input: 4->2->1->3
Output: 1->2->3->4
Example 2:

Input: -1->5->3->4->0
Output: -1->0->3->4->5

*/

// keypoints:
// 1. time complexity: O(nlogn), which means choises are: quick sort, merge sort, heap sort;
//    list can't reach by index, so merge sort is better choise
// 2. in order to use merge sort, we need two sorted list, which means split and sort
// 3. choose mid-point as break point by using slow and fast pointers, 
//    usig prev pointer to get the tail of left side list
// 4. when sublists only has one node, they could be sorted
//    using recursive to get sorted list
// 5. first recursive, then merge
// 6. merge two sorted list is travil, we can create a new list or use old one, both works


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
    ListNode* sortList(ListNode* head) {
        // insert sort is travial, which we did before
        // try merge sort
        
        // empty or single node, return head
        if (!head || !head->next)
            return head;
        
        // first, find mid-point of list
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = head;
        
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // split list into two parts:
        prev->next = nullptr;
        
        // sort left and right parts
        ListNode* left = sortList(head);
        ListNode* right = sortList(slow);
        
        return merge(left, right);
    }
                     
    // notice: left and right are sorted sublist
    ListNode* merge(ListNode* left, ListNode* right) {
        
        if (!left || !right)
            return left ? left : right;
        
        // create head of new list as return value
        //ListNode* deamon = new ListNode(0);
        //ListNode* cur = deamon;
        
        // since new list head must be one of left and right
        // instead of create new node, compare and decide the right head pointer
        ListNode* head;
        if (left->val <= right->val) {
            head = left;
            left = left->next;
        } else {
            head = right;
            right = right->next;
        }
        
        // use cur and leave head untouched
        ListNode* cur = head; 
        while (left && right) {
            
            if (left->val <= right->val) {
                // link left to new list
                cur->next = left;
                // left parts move forward
                left = left->next;
            } else {
                cur->next = right;
                right = right->next;
            }
            
            // move pointer of new list forward
            cur = cur->next;
        }
        
        // now left or right is null
        // add non-null node to cur node of new list
        cur->next = left ? left : right;
        
        return head;
    }
};
