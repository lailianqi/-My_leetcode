#include <algorithm>
#include <string>
#include <vector>
using namespace std;

// 自己的第一种解法 暴力的解法 并不可行 超时 这题没写出来
class Solution {
  public:
    int bestRotation(vector<int> &A) {
        int m = A.size(), res = 0, index = 0;
        auto temp = A;
        for (int i = 0; i < m; i++) {
            auto temp = A;
            reverseK(temp, i);
            int counter = countResult(temp);
            if (res < counter) {
                res = counter;
                index = i;
            }
        }
        return index;
    }
    int countResult(vector<int> &A) {
        int res = 0;
        for (int i = 0; i < A.size(); i++) {
            res += (A[i] <= i);
        }
        return res;
    }
    void reverseK(vector<int> &A, int k) {
        reverse(A.begin(), A.begin() + k);
        reverse(A.begin() + k, A.end());
        reverse(A.begin(), A.end());
    }
};

// 直接看到LeetCode的答案  这题看了答案也没明白怎么回事
// https://leetcode.com/problems/smallest-rotation-with-highest-score/discuss/118725/Easy-and-Concise-5-lines-Solution-C++JavaPython?page=2
// https://www.cnblogs.com/seyjs/p/8551935.html
// http://blog.csdn.net/zjucor/article/details/79516917
class Solution_0 {
  public:
    int bestRotation(vector<int> &A) {
        int N = A.size();
        vector<int> change(N);
        for (int i = 0; i < N; ++i)
            change[(i - A[i] + 1 + N) % N] -= 1;
        for (int i = 1; i < N; ++i)
            change[i] += change[i - 1] + 1;
        return distance(change.begin(),
                        max_element(change.begin(), change.end()));
    }
};