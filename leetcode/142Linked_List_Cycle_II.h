#include <climits>
#include <string>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
// LeetCode的答案
// https://discuss.leetcode.com/topic/5284/concise-o-n-solution-by-using-c-with-detailed-alogrithm-description/2
class Solution {
  public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL)
            return NULL;
        ListNode *walker = head;
        ListNode *runner = head;
        ListNode *entry = head;
        while (runner && runner->next) {
            walker = walker->next;
            runner = runner->next->next;
            if (walker == runner) {
                while (walker != entry) { // found the entry location
                    walker = walker->next;
                    entry = entry->next;
                }
                return entry;
            }
        }
        return NULL;
    }
};

// 二刷---------------
class Solution {
  public:
    ListNode *detectCycle(ListNode *head) {
        auto slow = head, faster = head, entry = head;
        while (faster && faster->next) {
            slow = slow->next;
            faster = faster->next->next;
            if (slow == faster) {
                while (entry != slow) {
                    entry = entry->next;
                    slow = slow->next;
                }
                return entry;
            }
        }
        return NULL;
    }
};