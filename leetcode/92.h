#include <string>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    *ListNode(int x) : val(x), next(NULL) {}
};

/*
Reverse a linked list from position m to n. Do it in-place and in one-pass.
For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,
return 1->4->3->2->5->NULL.
*/
class Solution {
  public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (head == NULL)
            return NULL;
        ListNode *result = new ListNode(0), *p = head;
        result->next = head;
        ListNode *pre = result;
        int lengMToN = n - m;
        while (p && --m) {
            pre = p;
            p = p->next;
        }
        ListNode *cur = p;
        ListNode *curThen = cur->next;
        for (int i = 0; i < lengMToN; i++) {
            cur->next = curThen->next;
            curThen->next = pre->next;
            pre->next = curThen;
            curThen = cur->next;
        }
        return result->next;
    }
};