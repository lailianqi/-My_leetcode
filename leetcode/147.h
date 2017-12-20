#include <string>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
// You are here!
// Your runtime beats 52.33 % of cpp submissions.
class Solution {
  public:
    ListNode *insertionSortList(ListNode *head) {
        ListNode *result = new ListNode(0);
        ListNode *p = head;
        while (p) {
            ListNode *pre = result;
            ListNode *q = result->next;
            ListNode *temp = p->next;
            while (q && p->val > q->val) {
                pre = q;
                q = q->next;
            }
            p->next = pre->next;
            pre->next = p;
            p = temp;
        }
        return result->next;
    }
};