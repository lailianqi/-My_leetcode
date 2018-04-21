#include <queue>
#include <string>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.size() == 0)
            return NULL;
        return MergeSort(lists, 0, lists.size() - 1);
    }
    ListNode *MergeSort(vector<ListNode *> &lists, int left, int right) {
        if (left < right) {
            int i = (left + right) / 2;
            ListNode *l1 = MergeSort(lists, left, i);
            ListNode *l2 = MergeSort(lists, i + 1, right);
            return Merge(l1, l2);
        }
        return lists[left];
    }
    ListNode *Merge(ListNode *l1, ListNode *l2) {
        return mergeTwoLists(l1, l2);
    }
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
};

// 优先队列的堆的解法 自己第二遍刷的时候参照LeetCode的解法写的
// https://leetcode.com/problems/merge-k-sorted-lists/discuss/10528/A-java-solution-based-on-Priority-Queue
// https://leetcode.com/problems/merge-k-sorted-lists/discuss/10527/Difference-between-Priority-Queue-and-Heap-and-C++-implementation

// LeetCode上类似的解法
// https://leetcode.com/problems/merge-k-sorted-lists/discuss/10858/C++-solution-using-min_heap-easy-understanding
class Solution_0 {
  public:
    struct comp {
        bool operator()(const ListNode *l1, const ListNode *l2) {
            return l1->val > l2->val;
        }
    };
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        priority_queue<ListNode *, vector<ListNode *>, comp> q;
        ListNode *result = new ListNode(0);
        ListNode *current = result;
        for (auto &element : lists) {
            if (element != nullptr) {
                q.push(element);
            }
        }
        while (!q.empty()) {
            current->next = q.top();
            q.pop();
            current = current->next;
            if (current->next) {
                q.push(current->next);
            }
        }
        return result->next;
    }
};