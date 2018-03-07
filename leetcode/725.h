#include <algorithm>
#include <string>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 自己的第一种写法 感觉非常的丑陋 但是成功ac
class Solution {
  public:
    vector<ListNode *> splitListToParts(ListNode *root, int k) {
        vector<ListNode *> res(k, nullptr);
        ListNode *current = root;
        int length = 0;
        while (current) {
            length++;
            current = current->next;
        }
        int averNum = length / k, remainNum = length % k;
        current = root;
        for (int i = 0; i < k && current; i++) {
            res[i] = current;
            int addExtraNum = remainNum-- > 0 ? 1 : 0;
            for (int t = 0; t < averNum + addExtraNum - 1; t++) {
                current = current->next;
            }
            ListNode *temp = current->next;
            current->next = NULL;
            current = temp;
        }
        return res;
    }
};

// 自己的第一种解法的写法和思想和LeetCode一模一样 LeetCode的代码同样很长
class Solution_0 {
  public:
    vector<ListNode *> splitListToParts(ListNode *root, int k) {
        vector<ListNode *> res(k, nullptr);
        int length = 0;
        for (ListNode *current = root; current; current = current->next) {
            length++;
        }
        int averNum = length / k, remainNum = length % k;
        ListNode *current = root, *prev = nullptr;
        for (int i = 0; i < k && current; i++, remainNum--) {
            res[i] = current;
            for (int t = 0; t < averNum + (remainNum > 0 ? 1 : 0); t++) {
                prev = current;
                current = current->next;
            }
            prev->next = nullptr;
        }
        return res;
    }
};