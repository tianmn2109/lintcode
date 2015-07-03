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
     * @return: head node
     */
    ListNode *deleteDuplicates(ListNode *head) {
        // write your code here
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *p = head->next;
        ListNode *prev = head;
        while (p != NULL) {
            ListNode *r = p;
            p = p->next;
            if (prev->val == r->val) {
                prev->next = p;
                delete r;
            }
            else {
                prev = r;
            }
        }
        return head;
    }
};

