/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: The node where the cycle begins. 
     *           if there is no cycle, return null
     */
    ListNode *detectCycle(ListNode *head) {
        // write your code here
        if (head == NULL || head->next == NULL)
            return NULL;
        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *start = head;
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow ->next;
            if (fast == slow)
                break;
        }
        if (fast == NULL || fast->next == NULL)
            return NULL;
        while (fast != start) {    // 此处每次只前进一步
            fast = fast->next;
            start = start->next;
        }
        return start;
    }
};




