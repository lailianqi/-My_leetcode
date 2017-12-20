#include <climits>
#include <string>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
// LeetCode的解法
// https://discuss.leetcode.com/topic/13869/java-solution-with-3-steps/2
// https://discuss.leetcode.com/topic/13869/java-solution-with-3-steps/20
// https://discuss.leetcode.com/topic/13869/java-solution-with-3-steps/11
class Solution {
  public:
    void reorderList(ListNode *head) {
        ListNode *helper = new ListNode(0);
        helper->next = head;
        ListNode *walker = helper;
        ListNode *runner = helper;
        while (runner && runner->next) {
            walker = walker->next;
            runner = runner->next->next;
        }
        ListNode *tail = reverse(walker->next);
        walker->next = NULL;
        merge(head, tail);
    }
    ListNode *reverse(ListNode *head) {
        ListNode *temp = NULL;
        ListNode *curNode = head;
        while (curNode) {
            ListNode *curNext = curNode->next;
            curNode->next = temp;
            temp = curNode;
            curNode = curNext;
        }
        return temp;
    }
    void merge(ListNode *x, ListNode *y) {
        while (y != NULL) {
            ListNode *xn = x->next;
            ListNode *yn = y->next;
            x->next = y;
            y->next = xn;
            x = xn;
            y = yn;
        }
    }
};