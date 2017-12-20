#include <string>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

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