#include <string>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
//最愚蠢的解法,时间复杂率太高
class Solution {
  public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // return intersectionNode(headA, headB);
        if (headA == NULL || headB == NULL)
            return NULL;
        ListNode *p = headA;
        while (p) {
            ListNode *q = headB;
            while (q) {
                if (p == q) {
                    return q;
                }
                q = q->next;
            }
            p = p->next;
        }
        return NULL;
    }
    ListNode *intersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL)
            return NULL;
        if (headA == headB) {
            return headA;
        }
        ListNode *left = intersectionNode(headA->next, headB);
        if (left)
            return left;
        ListNode *right = intersectionNode(headA, headB->next);
        if (right)
            return right;
        return NULL;
    }
};
// leetcode的答案
// https://discuss.leetcode.com/topic/28067/java-solution-without-knowing-the-difference-in-len
class Solution_0 {
  public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL)
            return NULL;
        ListNode *p = headA;
        ListNode *q = headB;
        while (p != q) {
            p = p == NULL ? headB : p->next;
            q = q == NULL ? headA : q->next;
        }
        return p;
    }
};