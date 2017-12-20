#include <iostream>
#include <string>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
  public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode *p = head;
        ListNode *pre;
        int i;
        for (i = 0; i < k && p != NULL; i++) {
            pre = p;
            p = p->next;
        }
        if (i < k) {
            return head;
        }
        pre->next = NULL;
        ListNode *current = reverseKGroup(p, k);
        ListNode *q = ReverseLink(head);
        head->next = current;
        return q;
    }
    //递归的写法
    ListNode *swapPairs(ListNode *head) {
        if ((head == NULL) || (head->next == NULL))
            return head;
        ListNode *p = head->next;
        head->next = swapPairs(p->next);
        p->next = head;
        return p;
    }
    //递归反转列表
    ListNode *ReverseLink(ListNode *head) {
        if (head->next == NULL) {
            return head;
        }
        ListNode *current = head->next;
        ListNode *newNode = ReverseLink(current);
        current->next = head;
        head->next = NULL;
        return newNode;
    }
    //暂时无法用这个方法写
    // ListNode *reverseKGroup(ListNode *head, int k) {
    //     ListNode *current = head;
    //     int counter = 0;
    //     while (current) {
    //         ListNode *p = current;
    //         counter = 1;
    //         while (p && counter < k) {
    //             p = p->next;
    //             counter++;
    //         }
    //         ListNode *temp = current;
    //         current = p->next;
    //         p->next = NULL;
    //         // ListNode *headNode = ReverseLink(current);
    //     }
    // }
};

void test() {
    Solution s;
    ListNode L1(2);
    ListNode L2(4);
    ListNode L3(3);
    L1.next = &L2;
    L2.next = &L3;
    L3.next = NULL;
    ListNode *p = s.reverseKGroup(&L1, 2);
    while (p) {
        cout << p->val << " ";
        p = p->next;
    }
}