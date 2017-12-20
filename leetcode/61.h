#include <string>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
//自己的写法，不够简洁
class Solution {
  public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == NULL || head->next == NULL || k == 0) {
            return head;
        }
        ListNode *result = new ListNode(0);
        result->next = head;
        ListNode *p = head, *pre = result;
        int length = 0;
        while (p) {
            p = p->next;
            pre = pre->next;
            length++;
        }
        k = k % length;
        pre->next = head;
        p = head;
        int t = length - k;
        while (--t) {
            p = p->next;
        }
        result->next = p->next;
        p->next = NULL;
        return result->next;
    }
};

class Solution_0 {
  public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == NULL)
            return head;
        ListNode *p = head;
        int length = 1;
        while (p->next) {
            length++;
            p = p->next;
        }
        k = k % length;
        p->next = head;
        p = head;
        int kth = length - k;
        while (--kth) {
            p = p->next;
        }
        head = p->next;
        p->next = NULL;
        return head;
    }
};