#include <string>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
//自己的第一种写法，就是直接遍历
// leetcode上采用的类似的写法
// https://discuss.leetcode.com/topic/17916/8ms-c-iterative-and-recursive-solutions-with-explanations/2
// https://discuss.leetcode.com/topic/13268/in-place-iterative-and-recursive-java-solution
class Solution {
  public:
    ListNode *reverseList(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *p = head, *q = NULL;
        while (p) {
            ListNode *temp = p->next;
            p->next = q;
            q = p;
            p = temp;
        }
        return q;
    }
};
//下面是我采用递归的写法
// leetcode上采用的类似的写法
// https://discuss.leetcode.com/topic/17916/8ms-c-iterative-and-recursive-solutions-with-explanations/2
//
class Solution_0 {
  public:
    ListNode *reverseList(ListNode *head) { return helper(head); }
    ListNode *helper(ListNode *head) {
        if (!head || !(head->next))
            return head;
        ListNode *node = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return node;
    }
};