#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;
//没有写出来
// 自己安照leetcode的答案改写
// https://discuss.leetcode.com/topic/52948/share-my-thoughts-and-clean-java-code?page=1
class Solution {
  public:
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        int m = matrix.size();
        auto comp = [&matrix](pair<int, int> a, pair<int, int> b) {
            return matrix[a.first][a.second] > matrix[b.first][b.second];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)>
            min_heap(comp);
        for (int j = 0; j <= m - 1; j++) {
            min_heap.emplace(0, j);
        }
        for (int i = 0; i < k - 1; i++) {
            auto temp = min_heap.top();
            min_heap.pop();
            if (temp.first != m - 1) {
                min_heap.emplace(temp.first + 1, temp.second);
            }
        }
        return matrix[min_heap.top().first][min_heap.top().second];
    }
};

//另外一种的binary search
// https://discuss.leetcode.com/topic/52865/my-solution-using-binary-search-in-c/2
class Solution_0 {
  public:
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        int n = matrix.size();
        int left = matrix[0][0], right = matrix[n - 1][n - 1];
        int mid = 0;
        while (left < right) {
            mid = left + (right - left) / 2;
            int num = 0;
            for (int i = 0; i < n; i++) {
                int pos = upper_bound(matrix[i].begin(), matrix[i].end(), mid) -
                          matrix[i].begin();
                num += pos;
            }
            if (num < k) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};