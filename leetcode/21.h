#include <iostream>
using namespace std;
//   Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    //创建了新的节点，如果占用旧的节点速度更快
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *result = new ListNode(0);
        ListNode *tempNext = result;
        ListNode *p = l1, *q = l2;
        int sum = 0;
        while (p != NULL && q != NULL) {
            if (p->val < q->val) {
                sum = p->val;
                p = p->next;
            } else {
                sum = q->val;
                q = q->next;
            }
            ListNode *nextNode = new ListNode(sum);
            tempNext->next = nextNode;
            tempNext = tempNext->next;
        }
        ListNode *temp;
        if (p != NULL) {
            temp = p;
        } else {
            temp = q;
        }
        while (temp) {
            ListNode *nextNode = new ListNode(temp->val);
            tempNext->next = nextNode;
            tempNext = tempNext->next;
            temp = temp->next;
        }
        return result->next;
    }
    //采用递归的写法
    ListNode *mergeTwoLists1(ListNode *l1, ListNode *l2) {
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;

        if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l2->next, l1);
            return l2;
        }
    }
};