#include <string>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
//自己的原始的解法
class Solution {
  public:
    void deleteNode(ListNode *node) {
        if (node == NULL || node->next == NULL) {
            return;
        }
        ListNode *pre = NULL;
        while (node->next) {
            pre = node;
            node->val = node->next->val;
            node = node->next;
        }
        pre->next = NULL;
    }
};
//自己的改进版 速度更快
class Solution_0 {
  public:
    void deleteNode(ListNode *node) {
        if (node == NULL || node->next == NULL) {
            return;
        }
        ListNode *pre = NULL;
        node->val = node->next->val;
        node->next = node->next->next;
    }
};

// leetcode的写法
// https://discuss.leetcode.com/topic/18752/1-3-lines-c-java-python-c-c-javascript-ruby
class Solution_1 {
  public:
    void deleteNode(ListNode *node) { *node = *node->next; }
};
// leetcode的写法
//比上面的解法更合适的解法，因为真正的删除了节点
// https://discuss.leetcode.com/topic/18752/1-3-lines-c-java-python-c-c-javascript-ruby
class Solution_2 {
  public:
    void deleteNode(ListNode *node) {
        ListNode *next = node->next;
        *node = *next;
        delete next;
    }
};