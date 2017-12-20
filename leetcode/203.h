#include <string>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
//自己的答案和下面leetcode的答案差不多一样，借助了额外空间辅助
class Solution {
  public:
    ListNode *removeElements(ListNode *head, int val) {
        ListNode *result = new ListNode(0);
        result->next = head;
        ListNode *pre = result;
        ListNode *p = head;
        while (p) {
            if (p->val == val) {
                pre->next = p->next;
            } else {
                pre = p;
            }
            p = p->next;
        }
        return result->next;
    }
};
// Leetcode的写法
//下面是递归的写法
// https://discuss.leetcode.com/topic/12580/3-line-recursive-solution/10?page=1
class Solution_0 {
  public:
    ListNode *removeElements(ListNode *head, int val) {
        if (head == NULL) {
            return NULL;
        }
        ListNode *next = removeElements(head->next, val);
        if (head->val == val) {
            return next;
        }
        head->next = next;
        return head;
    }
};

//参考递归答案后自己的改进版
class Solution_1 {
  public:
    ListNode *removeElements(ListNode *head, int val) {
        if (head == NULL) {
            return NULL;
        }
        if (head->val == val) {
            return removeElements(head->next, val);
        }
        head->next = removeElements(head->next, val);
        return head;
    }
};