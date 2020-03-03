/*

Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed) in the linked list where tail connects to. If pos is -1, then there is no cycle in the linked list.

Note: Do not modify the linked list.

 

Example 1:

Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.


Example 2:

Input: head = [1,2], pos = 0
Output: tail connects to node index 0
Explanation: There is a cycle in the linked list, where tail connects to the first node.


Example 3:

Input: head = [1], pos = -1
Output: no cycle
Explanation: There is no cycle in the linked list.


 

Follow-up:
Can you solve it without using extra space?

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
    ListNode *detectCycle(ListNode *head) {
        // keypoints:
        // 1. find meet node
        // 2. find cycle begin node
        
        // big picture:
        // meeting node must between a and c since fast only trave this range
        // head         cycle begin          meeting node
        // #-------a--------#--------b--------#
        //                  |                 |
        //                  |_________c_______|
        
        // prove: fast will catch slow if cycle exist
        // slow: move distance   a + x(b+c) + b
        // fast: move diatabce 2(a + x(b+c) + b)
        // if fast catch slow:
        // 2(a+ x(b+c) + b) = a + x(b+c) + b + y(b+c)
        // y(b+c) is cycles fast moves to catch slow
        // --> a+b = (y-x)(b+c) = n(b+c). n = y-x
        
        // does a+b = n(b+c) satified ?
        // suppose a+b+c = len
        // b = n(b+c) -a = n(len-a) - a = n*len - (n+1)*a > 0
        // -->  len > n+1/n * a
        // if a = 0, b > 0, satisfied
        // if a >= 1, if cycle exist, len = a +b +c >= 2, satisfied
        // if cycle exist, fast are sure to catch slow
        
        // How to find cycle begin node ? aka solve a ?
        // a+b = n(b+c)
        // let fast start from head, move a steps
        // let slow start from meeting node(b), move c steps and m cycles(m(b+c))
        // if they meet at cycle begin, their move steps satisfied: a = m(b+c) + c ?
        // since a+b = n(b+c), we know a = (n-1)(b+c) +c = m(b+c) + c, proved
        // fast and slow must meet at cycle begin
        
        if (!head)
            return head;
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast)
                break;
        }
        
        if (!fast || !fast->next)
            return nullptr;
        
        fast = head;
        while (fast && slow) {
            
            // notice: juadge then update, or will miss the first meet node
            if (fast == slow)
                return fast;
            
            fast = fast->next;
            slow = slow->next;
        }
        
        return nullptr;
        
    }
};
