#include <stack>
#include <vector>
using namespace std;

// 第69周的周赛
// 没写出来 没想到点子上 题目本身已经给出了提示  直接看的答案 答案非常的巧妙
// https://discuss.leetcode.com/topic/118695/check-if-we-can-sort-the-array-with-only-local-inversions
class Solution {
  public:
    bool isIdealPermutation(vector<int> &A) {
        for (int i = 1; i < A.size(); i++) {
            if (A[i] - A[i - 1] == -1) {
                swap(A[i], A[i - 1]);
            } else if (A[i - 1] != i - 1) {
                return false;
            }
        }
        return true;
    }
};

// 更加巧妙且牛逼的方案 来自Leetcode的答案 其实和上面的算法本质是一样的
// https://discuss.leetcode.com/topic/118667/my-3-lines-c-solution
class Solution_0 {
  public:
    bool isIdealPermutation(vector<int> &A) {
        for (int i = 0; i < A.size(); i++) {
            if (abs(A[i] - i) > 1) {
                return false;
            }
        }
        return true;
    }
};