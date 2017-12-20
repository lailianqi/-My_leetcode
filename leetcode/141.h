#include <climits>
#include <string>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
//第一种方法，自己的写得，改变了原始值，并不好。
class Solution {
  public:
    bool hasCycle(ListNode *head) {
        if (head == NULL)
            return false;
        ListNode *p = head;
        while (p && p->val != INT_MAX) {
            p->val = INT_MAX;
            p = p->next;
        }
        if (p == NULL)
            return false;
        return true;
    }
};
// LeetCode得解法
// https://discuss.leetcode.com/topic/12516/o-1-space-solution
class Solution_0 {
  public:
    bool hasCycle(ListNode *head) {
        if (head == NULL)
            return false;
        ListNode *walker = head;
        ListNode *runner = head;
        while (runner && runner->next) {
            walker = walker->next;
            runner = runner->next->next;
            if (walker == runner) {
                return true;
            }
        }
        return false;
    }
};