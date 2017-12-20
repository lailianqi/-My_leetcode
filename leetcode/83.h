#include <string>
#include <climits>
using namespace std;
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *result = new ListNode(INT_MAX);
        result->next = head;
        ListNode *p = head, *pre = result;
        while (p) {
            if (pre->val != p->val) {
                pre = p;
            }
            p = p->next;
        }
        pre->next = NULL;
        return result->next;
    }
};