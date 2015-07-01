/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param head: The head of linked list with a random pointer.
     * @return: A new head of a deep copy of the list.
     */
    RandomListNode *copyRandomList(RandomListNode *head) {
        // write your code here
        if (head == NULL)
            return head;
        RandomListNode *p = head;
        while (p != NULL) {
            RandomListNode *temp = new RandomListNode(p->label);
            temp->next = p->next;
            p->next = temp;
            p = p->next->next;
        }
        p = head;
        while (p != NULL) {
            if (p->random != NULL)              // **************************************
                p->next->random = p->random->next;
            p = p->next->next;
        }
        p = head;
        RandomListNode *rhead = NULL;
        RandomListNode *rtail = NULL;
        while (p != NULL) {
            RandomListNode *temp = p->next;
            p->next = p->next->next;
            p = p->next;
            if (rhead == NULL) {
                rhead = rtail = temp;
            }
            else {
                rtail->next = temp;
                rtail = rtail->next;
            }
            rtail->next = NULL;
        }
        return rhead;
    }
};

