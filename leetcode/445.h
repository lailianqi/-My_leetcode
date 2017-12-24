#include <string>
#include <stack>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
//直接使用stack 比较简单 leetcode的解法是一样的
// https://discuss.leetcode.com/topic/65279/easy-o-n-java-solution-using-stack
class Solution {
  public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        stack<int> stack1, stack2;
        ListNode *result = new ListNode(0);
        while (l1) {
            stack1.push(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            stack2.push(l2->val);
            l2 = l2->next;
        }
        int sum = 0;
        while (!stack1.empty() || !stack2.empty() || sum) {
            if (!stack1.empty()) {
                sum += stack1.top();
                stack1.pop();
            }
            if (!stack2.empty()) {
                sum += stack2.top();
                stack2.pop();
            }
            result->val = sum % 10;
            sum = sum / 10;
            ListNode *head = new ListNode(0);
            head->next = result;
            result = head;
        }
        return result->next;
    }
};