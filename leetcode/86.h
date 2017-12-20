#include <string>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/*
Given a linked list and a value x, partition it such that all nodes less than x
come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two
partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
*/
//自己写的 写的并不简洁
class Solution {
  public:
    ListNode *partition(ListNode *head, int x) {
        ListNode *result = new ListNode(0);
        result->next = head;
        ListNode *p = head, *pre = result, *lessP = result;
        while (p) {
            if (p->val < x) {
                if (pre == lessP) {
                    pre = p;
                    lessP = pre;
                    p = p->next;
                } else {
                    ListNode *temp = p;
                    pre->next = p->next;
                    p = p->next;
                    temp->next = lessP->next;
                    lessP->next = temp;
                    lessP = lessP->next;
                }
            } else {
                pre = p;
                p = p->next;
            }
        }
        return result->next;
    }
};

class Solution_0 {
  public:
    ListNode *partition(ListNode *head, int x) {
        ListNode *lessResult = new ListNode(0);
        ListNode *moreResult = new ListNode(0);
        ListNode *p = head, *p1 = lessResult, *p2 = moreResult;
        while (p) {
            if (p->val < x) {
                p1->next = p;
                p1 = p1->next;
            } else {
                p2->next = p;
                p2 = p2->next;
            }
            p = p->next;
        }
        p2->next = NULL;
        p1->next = moreResult->next;
        return lessResult->next;
    }
};