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
     * @param ListNode l1 is the head of the linked list
     * @param ListNode l2 is the head of the linked list
     * @return: ListNode head of linked list
     */
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // write your code here
        ListNode *tempHead = new ListNode(0);
        ListNode *tail = tempHead;
        ListNode *r = NULL;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                r = l1;
                l1 = l1->next;
            }
            else {
                r = l2;
                l2 = l2->next;
            }
            r->next = NULL;
            tail->next = r;
            tail = r;
        }
        if (l1 != NULL)
            tail->next = l1;
        if (l2 != NULL)
            tail->next = l2;
        ListNode *ret = tempHead->next;
        delete tempHead;
        return ret;
    }
};
