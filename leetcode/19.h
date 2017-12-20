#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *result = new ListNode(0);
        result->next = head;
        ListNode *p = head, *q = head, *pre = result;
        while (q && n) {
            q = q->next;
            n--;
        }
        while (p && q) {
            pre = p;
            p = p->next;
            q = q->next;
        }
        pre->next = p->next;
        return result->next;
    }
};