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
     * @param n: An integer.
     * @return: The head of linked list.
     */
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // write your code here
        ListNode *tempHead = new ListNode(0);
        tempHead->next = head;
        ListNode *q = tempHead;
        ListNode *p = tempHead;
        while (n --)
            p = p->next;
        while (p->next != NULL) {
            p = p->next;
            q = q->next;
        }
        ListNode *temp = q->next;
        q->next = q->next->next;
        delete temp;
        head = tempHead->next;
        delete tempHead;
        return head;
    }
};

