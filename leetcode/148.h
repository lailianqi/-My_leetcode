#include <string>
// Sort a linked list in O(n log n) time using constant space complexity.
// You are here!
// Your runtime beats 59.05 % of cpp submissions.

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
//自己写的答案，空间使用了O(lgn)
class Solution {
  public:
    ListNode *sortList(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *helper = new ListNode(0);
        helper->next = head;
        ListNode *walker = helper;
        ListNode *runner = helper;
        while (runner && runner->next) {
            walker = walker->next;
            runner = runner->next->next;
        }
        ListNode *tail = sortList(walker->next);
        walker->next = NULL;
        ListNode *newHead = sortList(head);
        return mergeTwoLists(newHead, tail);
    }
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
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

// LeetCode的答案
// https://discuss.leetcode.com/topic/40030/share-my-c-concise-solutions-easy-to-understand
class Solution {
  public:
    ListNode *sortList(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *slow = head;
        ListNode *fast = head->next;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // divide the list into two parts
        fast = slow->next;
        slow->next = NULL;

        return merge(sortList(head), sortList(fast));
    }
    // merge使用了额外的空间但不是堆上面创建的
    ListNode *merge(ListNode *l1, ListNode *l2) {
        ListNode dump(0);
        ListNode *cur = &dump;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        if (l1 != NULL)
            cur->next = l1;
        else
            cur->next = l2;
        return dump.next;
    }
};