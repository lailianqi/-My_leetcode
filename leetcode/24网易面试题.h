#include <string>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
// 第一遍自己的代码 现在看来真烂
class Solution {
  public:
    ListNode *swapPairs(ListNode *head) {
        if (head == NULL) {
            return head;
        }
        ListNode *pre = new ListNode(0);
        ListNode *p1 = head;
        ListNode *p2 = head->next;
        pre->next = head;
        ListNode *result = pre;
        int count = 2;
        while (p2) {
            if (count == 2) {
                pre->next = p2;
                p1->next = p2->next;
                p2->next = p1;
                p1 = pre->next;
                p2 = p1->next;
                count = 0;
            }
            pre = p1;
            p1 = p2;
            p2 = p2->next;
            count++;
        }
        return result->next;
    }
    //递归的写法
    ListNode *swapPairs1(ListNode *head) {
        if ((head == NULL) || (head->next == NULL))
            return head;
        ListNode *p = head->next;
        head->next = swapPairs1(p->next);
        p->next = head;
        return p;
    }
    //最基本的写法
    ListNode *swapPairs2(ListNode *head) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *current = dummy;
        while (current->next != NULL && current->next->next != NULL) {
            ListNode *first = current->next;
            ListNode *second = current->next->next;
            first->next = second->next;
            current->next = second;
            current->next->next = first;
            current = current->next->next;
        }
        return dummy->next;
    }
};

// 这里是我第二遍的时候添加的解法
// https://leetcode.com/problems/swap-nodes-in-pairs/discuss/11019/7-8-lines-C++-Python-Ruby

class Solution_0 {
  public:
    ListNode *swapPairs(ListNode *head) {
        ListNode **pp = &head, *a, *b;
        while ((a = *pp) && (b = a->next)) {
            a->next = b->next;
            b->next = a;
            *pp = b; // 这句话纯粹为了head指向原先的第二个节点
            pp = &(a->next);
        }
        return head;
    }
};

// 第二遍的写法 网易的面试中碰到了 这是在网易面试中的写法
class Solution_1 {
  public:
    ListNode *swapPairs(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *newHead = new ListNode(-1);
        newHead->next = head;
        auto pre = newHead, cur1 = head, cur2 = head->next;
        while (cur1 && cur2) {
            auto temp = cur2->next;
            pre->next = cur2;
            cur2->next = cur1;
            cur1->next = temp;
            pre = cur1;
            cur1 = temp;
            cur2 = temp ? temp->next : NULL;
        }
        return newHead->next;
    }
};

// 这里用递归的写法写
class Solution_2 {
  public:
    ListNode *swapPairs(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        auto first = head, second = head->next;
        auto next = swapPairs(second->next);
        second->next = first;
        first->next = next;
        return second;
    }
};