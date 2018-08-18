#include <climits>
#include <string>
using namespace std;
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *result = new ListNode(INT_MAX);
        result->next = head;
        ListNode *p = head, *pre = result;
        while (p) {
            if (pre->val != p->val) {
                pre->next = p;
                pre = p;
            }
            p = p->next;
        }
        pre->next = NULL;
        return result->next;
    }
};

// 二刷的时候写的
class Solution_0 {
  public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == nullptr) {
            return head;
        }
        ListNode *prev = head, *p = head->next;
        while (p) {
            if (prev->val != p->val) {
                prev->next = p;
                prev = p;
            }
            p = p->next;
        }
        prev->next = nullptr;
        return head;
    }
};