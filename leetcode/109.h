#include <map>
#include <queue>
#include <string>
#include <vector>
using namespace std;
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// LeetCode的答案
// https://discuss.leetcode.com/topic/35997/share-my-java-solution-1ms-very-short-and-concise
// https://discuss.leetcode.com/topic/8141/share-my-o-1-space-and-o-n-time-java-code/16
class Solution {
  public:
    TreeNode *sortedListToBST(ListNode *head) {
        if (head == NULL)
            return NULL;
        ListNode *cnt = head;
        int len = 1;
        while (cnt->next != NULL) {
            cnt = cnt->next;
            len++;
        }
        return inorderRe(head, 1, len);
    }
    TreeNode *inorderRe(ListNode *&head, int left, int right) {
        if (left > right)
            return NULL;
        int mid = left + (right - left) / 2;
        TreeNode *leftnode = inorderRe(head, left, mid - 1);
        TreeNode *cur = new TreeNode(head->val);
        cur->left = leftnode;
        head = head->next;
        cur->right = inorderRe(head, mid + 1, right);
        return cur;
    }
};