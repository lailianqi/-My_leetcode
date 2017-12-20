#include <string>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//自己的写法  最好的一次的运行时间是9ms
class Solution {
  public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *result = new ListNode(0);
        result->next = head;
        ListNode *p = head, *pre = result;
        int counter = 1;
        while (p && p->next) {
            if (p->val == p->next->val) {
                counter++;
            } else if (counter == 1) {
                pre = p;
            } else {
                pre->next = p->next;
                counter = 1;
            }
            p = p->next;
        }
        if (counter > 1) {
            pre->next = NULL;
        }
        return result->next;
    }
};
//自己写法的改进版的解法 模仿leetcode的写法 比较简洁
class Solution_0 {
  public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *result = new ListNode(0);
        result->next = head;
        ListNode *p = head, *pre = result;
        while (p) {
            while (p->next && p->val == p->next->val) {
                p = p->next;
            }
            if (pre->next == p) {
                pre = p;
            } else {
                pre->next = p->next;
            }
            p = p->next;
        }
        return result->next;
    }
};
//递归版 leetcode的写法
class Solution_1 {
  public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head)
            return NULL;
        if (!head->next)
            return head;
        ListNode *p = head->next;
        if (head->val != p->val) {
            head->next = deleteDuplicates(p);
            return head;
        } else {
            while (p && p->val == head->val) {
                p = p->next;
            }
            return deleteDuplicates(p);
        }
    }
};