#include <iostream>
using namespace std;
//  Definition for singly-linked list.
struct ListNode {
      int val;
      ListNode *next;
      ListNode() {}
      ListNode(int x) : val(x), next(NULL) {}
      friend istream &operator>>(istream &is, ListNode &list) {
            is >> list.val;
            return is;
      }
      friend ostream &operator<<(ostream &os, ListNode &list) {
            ListNode *L = &list;
            while (L != NULL && L->next != NULL) {
                  os << L->val << "->";
                  L = L->next;
            }
            os << L->val;
            return os;
      }
};

class Solution {
    public:
      ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
            if (l1 == NULL)
                  return l2;
            if (l2 == NULL)
                  return l1;
            ListNode *p = l1, *q = l2, *pNode = NULL, *resList = NULL,
                     *pNext = NULL;
            int up = 0;
            while (p != NULL && q != NULL) {
                  pNext = new ListNode(p->val + q->val + up);
                  up = pNext->val / 10;
                  pNext->val = pNext->val % 10;
                  if (resList == NULL) {
                        resList = pNode = pNext;
                  } else {
                        pNode->next = pNext;
                        pNode = pNext;
                  }
                  p = p->next;
                  q = q->next;
            }
            ListNode *notEmptyList; // 存储未空的点
            if (p != NULL) {
                  notEmptyList = p;
            } else {
                  notEmptyList = q;
            }
            while (notEmptyList != NULL) {
                  pNext = new ListNode(notEmptyList->val + up);
                  up = pNext->val / 10;
                  pNext->val = pNext->val % 10;
                  pNode->next = pNext;
                  pNode = pNext;
                  notEmptyList = notEmptyList->next;
            }
            if (up > 0) {
                  pNext = new ListNode(up);
                  pNext->next = NULL;
                  pNode->next = pNext;
            }
            return resList;
      }
      ListNode *addTwoNumbers2(ListNode *l1, ListNode *l2) {
            ListNode *result = new ListNode(0);
            ListNode *tempNext = result;
            ListNode *p = l1, *q = l2;
            int sum = 0;
            while (p != NULL || q != NULL || sum) {
                  sum += ((p ? p->val : 0) + (q ? q->val : 0));
                  ListNode *nextNode = new ListNode(sum % 10);
                  sum /= 10;
                  tempNext->next = nextNode;
                  tempNext = tempNext->next;
                  p = p ? p->next : p;
                  q = q ? q->next : q;
            }
            return result->next;
      }
};

void test() {
      Solution s;
      ListNode L1(2);
      ListNode L2(4);
      ListNode L3(3);
      L1.next = &L2;
      L2.next = &L3;
      L3.next = NULL;

      ListNode L4(5);
      ListNode L5(6);
      ListNode L6(4);
      L4.next = &L5;
      L5.next = &L6;
      L6.next = NULL;
      // cout << L1 << " " << L4;
      cout << *(s.addTwoNumbers2(&L1, &L4)) << endl;
}

/*
Coordinate operator+(const Coordinate &coor)

{

Coordinate temp;

temp.m_iX = this0>m_iX+coor.m_iX;

temp.m_iY= this0>m_iY+coor.m_iY;

return temp;

}

这种情况下，函数的参数里面，第一个参数其实是隐藏了一个当前this的。

而对于输出运算符重载来说

friend ostream& operator<<(ostream &out, const Coordinate
&coor);来说，第一个参数必须是ostream，即其不能是this指针，

所以当对<<重载时，就要使用友元函数的形式。
*/