#include <string>
#include <vector>
#include <cstdlib>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
//自己的第一种方案  使用的额外的空间
class Solution {
  public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least
       one node. */
    Solution(ListNode *head) {
        while (head) {
            dir.push_back(head->val);
            head = head->next;
        }
    }

    /** Returns a random node's value. */
    int getRandom() { return dir[rand() % dir.size()]; }

  private:
    vector<int> dir;
};

// leetcode的解法 真得有点吊
// https://discuss.leetcode.com/topic/53753/brief-explanation-for-reservoir-sampling?page=1
namespace s1 {
class Solution {
  public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least
       one node. */
    Solution(ListNode *head) { this->head = head; }

    /** Returns a random node's value. */
    int getRandom() {
        ListNode *p = head;
        int result = p->val;
        for (int i = 1; p->next != NULL; i++) {
            p = p->next;
            if (rand() % (i + 1) == i)
                result = p->val;
        }
        return result;
    }

  private:
    ListNode *head;
};
};