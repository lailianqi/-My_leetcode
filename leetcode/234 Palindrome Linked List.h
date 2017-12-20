#include <string>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
//自己的答案 代码有点长
class Solution {
  public:
    bool isPalindrome(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return true;
        ListNode *helper = new ListNode(0);
        helper->next = head;
        ListNode *walker = helper, *runner = helper, *pre = NULL;
        while (runner && runner->next) {
            pre = walker;
            walker = walker->next;
            runner = runner->next->next;
        }
        if (runner == NULL) {
            pre->next = NULL;
        }
        ListNode *tail = walker->next;
        walker->next = NULL;
        tail = reverse(tail);
        return isEqual(head, tail);
    }
    ListNode *reverse(ListNode *head) {
        ListNode *temp = NULL;
        ListNode *curNode = head;
        while (curNode) {
            ListNode *curNext = curNode->next;
            curNode->next = temp;
            temp = curNode;
            curNode = curNext;
        }
        return temp;
    }
    bool isEqual(ListNode *head1, ListNode *head2) {
        while (head1 && head2) {
            if (head1->val != head2->val) {
                return false;
            }
            head1 = head1->next;
            head2 = head2->next;
        }
        return head1 == NULL && head2 == NULL;
    }
};