/*
Reverse a linked list from position m to n. Do it in one-pass.

Note: 1 ≤ m ≤ n ≤ length of list.

Example:

Input: 1->2->3->4->5->NULL, m = 2, n = 4
Output: 1->4->3->2->5->NULL
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
// 1. use deamon node in case reverse from head
// 2. how to reverse?
//    -> deamon  head  1    2    3    null
//    -> deamon  1    head  2    3    null
//    -> deamon  2     1   head  3    null
//    -> deamon  3     2    1   head  null

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        // first: locate m, then reverse from m to n
        // keypoint is set the start node as end node, then add note
        // in such way we reverse the pointer without switch value
        
        // since head may be swaped, use deamon to track the original head
        ListNode* deamon = new ListNode(0);
        deamon->next = head;
        
        // locate m, use the prev node of m-th node here, so iter m-2 times        
        // note: must use deamon here, if we use prev = head, which means m >=2
        // when m = 1, it will be problem
        ListNode* prev = deamon;
        for (int i = 0; i < m-1; i++) {
            prev = prev->next;
        }
        
        
        
        // big picture:
        //         _______________
        //    ____|_______        |
        //   |    |       |       |
        //   |    |       v       v
        //  prev cur    next   next->next
        //   |    |       |       |
        //   1    2       3       4   5
        //        ^
        //        |_______| 
        //
        //
        
        // locate start node (aka m-th node)
        ListNode* cur = prev->next;
        for (int i = 1; i <= n-m; i++) {
            // first break, then reverse link
            
            // break next node (by link cur and next->next)
            ListNode* next = cur->next;
            cur->next = next->next;
            
            // reverse link of next node
            // note: we must use prev->next NOT cur
            // beacuse prev->next is update every time
            // we only change the "next" pointer of node, not node itself
            next->next = prev->next;
            
            // update cur(aka next operate target)
            prev->next = next;  
        }
        
        return deamon->next;
        
    }
};
