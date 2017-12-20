#include <string>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
//一次成功 自己的第一种解法
class Solution {
  public:
    ListNode *oddEvenList(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *oddNode = head, *evenNode = head->next, *oddHead = evenNode,
                 *current = evenNode->next;
        int counter = 1;
        while (current) {
            ListNode *&p = counter & 1 ? oddNode : evenNode;
            p->next = current;
            p = p->next;
            current = current->next;
            counter++;
        }
        oddNode->next = oddHead;
        evenNode->next = NULL;
        return head;
    }
};

// leetcode的解法 非常的聪明
// https://discuss.leetcode.com/topic/34292/simple-o-n-time-o-1-space-java-solution
class Solution_0 {
  public:
    ListNode *oddEvenList(ListNode *head) {
        if (head == NULL) {
            return head;
        }
        ListNode *odd = head, *even = head->next, *evenHead = even;
        while (even && even->next) {
            odd->next = odd->next->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        return head;
    }
};