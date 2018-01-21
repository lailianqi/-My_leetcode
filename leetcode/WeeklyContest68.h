#include <algorithm>
#include <atomic>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
//这次惨败 就做出来一题
//成功ac
class Solution1 {
  public:
    bool isToeplitzMatrix(vector<vector<int>> &matrix) {
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m + n - 1; i++) {
            for (int row = min(i, m - 1), col = max(0, i - m + 1);
                 col >= 0 && row < m; row++, col--) {
                if (row + 1 < m && col + 1 < n) {
                    if (matrix[row][col] != matrix[row + 1][col + 1]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
//来自LeetCode上更加简单的写法
// https://discuss.leetcode.com/topic/117842/java-solution-4-liner
class Solution11 {
  public:
    bool isToeplitzMatrix(vector<vector<int>> &matrix) {
        for (int i = 0; i < matrix.size() - 1; i++) {
            for (int j = 0; j < matrix[i].size() - 1; j++) {
                if (matrix[i][j] != matrix[i + 1][j + 1])
                    return false;
            }
        }
        return true;
    }
};
// 这题比赛中没有写出来
// leetcode 的答案
// https://discuss.leetcode.com/topic/117891/c-greedy-sort-o-n
// https://discuss.leetcode.com/topic/117851/java-solution-priorityqueue
class Solution_2 {
  public:
    string reorganizeString(string S) {
        unordered_map<char, int> dir;
        string res;
        for (int i = 0; i < S.size(); i++) {
            dir[S[i]]++;
            if (dir[S[i]] > ((S.size() + 1) / 2)) {
                return "";
            }
        }
        auto comp = [](pair<char, int> &a, pair<char, int> &b) {
            return a.second < b.second;
        };
        priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(comp)>
            maxStack(comp);
        for (auto element : dir) {
            maxStack.push(element);
        }
        while (!maxStack.empty()) {
            auto element = maxStack.top();
            maxStack.pop();
            if (res.size() == 0 || element.first != res.back()) {
                res.push_back(element.first);
                if (--element.second > 0) {
                    maxStack.push(element);
                }
            } else {
                auto temp = maxStack.top();
                maxStack.pop();
                res.push_back(temp.first);
                if (--temp.second > 0) {
                    maxStack.push(temp);
                }
                maxStack.push(element);
            }
        }
        return res;
    }
};
//第二个答案 来自LeetCode 比上面的代码短多了 而且方法更加的简单
// https://discuss.leetcode.com/topic/117891/c-greedy-sort-o-n
class Solution_21 {
  public:
    string reorganizeString(string S) {
        vector<int> dir(26, 0);
        vector<pair<int, char>> charCounts;
        int m = S.size();
        for (int i = 0; i < S.size(); i++) {
            dir[S[i] - 'a']++;
        }
        for (int i = 0; i < dir.size(); i++) {
            if (dir[i] > (m + 1) / 2)
                return "";
            if (dir[i])
                charCounts.push_back({dir[i], i + 'a'});
        }
        sort(charCounts.rbegin(), charCounts.rend());
        string strSorted;
        for (auto &p : charCounts) {
            strSorted += string(p.first, p.second);
        }
        string ans;
        for (int i = 0, j = (m - 1) / 2 + 1; i <= (m - 1) / 2; i++, j++) {
            ans += strSorted[i];
            if (j < m) {
                ans += strSorted[j];
            }
        }
        return ans;
    }
};
//这题比赛的时候死活写不出来 其实和67周的第二题挺像 但是利用了本题中数值的范围
// arr that is a permutation of [0, 1, ..., arr.length - 1]
//来自LeetCode的答案
// https://discuss.leetcode.com/topic/117837/c-4-lines-o-n-o-1
// https://discuss.leetcode.com/topic/117840/c-set
class Solution_3 {
  public:
    int maxChunksToSorted(vector<int> &arr) {
        int res = 0;
        for (int i = 0, maxValue = -1; i < arr.size(); i++) {
            maxValue = max(maxValue, arr[i]);
            if (maxValue == i) {
                res++;
            }
        }
        return res;
    }
};

// 另外的一种方法 来自LeetCode 也非常的聪明
// https://discuss.leetcode.com/topic/117872/java-solution-left-max-and-right-min
class Solution_31 {
  public:
    int maxChunksToSorted(vector<int> &arr) {
        int m = arr.size();
        vector<int> maxArr(m, 0), minArr(m, 0);
        for (int i = 0; i < arr.size(); i++) {
            maxArr[i] = i == 0 ? arr[0] : max(maxArr[i - 1], arr[i]);
        }
        for (int i = m - 1; i >= 0; i--) {
            minArr[i] = i == m - 1 ? arr[m - 1] : min(minArr[i + 1], arr[i]);
        }
        int res = 1;
        for (int i = 0; i < m - 1; i++) {
            if (maxArr[i] <= minArr[i + 1])
                res++;
        }
        return res;
    }
};
//比赛中没有写出来
//来自LeetCode的答案 Solution_31的解法可直接用在这个题目上 同一个作者写的
// https://discuss.leetcode.com/topic/117875/java-solution-left-max-and-right-min
class Solution_4 {
  public:
    int maxChunksToSorted(vector<int> &arr) {
        int m = arr.size();
        vector<int> maxArr(m, 0), minArr(m, 0);
        for (int i = 0; i < arr.size(); i++) {
            maxArr[i] = i == 0 ? arr[0] : max(maxArr[i - 1], arr[i]);
        }
        for (int i = m - 1; i >= 0; i--) {
            minArr[i] = i == m - 1 ? arr[m - 1] : min(minArr[i + 1], arr[i]);
        }
        int res = 1;
        for (int i = 0; i < m - 1; i++) {
            if (maxArr[i] <= minArr[i + 1])
                res++;
        }
        return res;
    }
};
// 另外一种牛逼的写法 来自LeetCode 可能比上面还要牛逼
// https://discuss.leetcode.com/topic/117857/c-7-lines-o-n-log-n-o-n
class Solution_41 {
  public:
    int maxChunksToSorted(vector<int> &arr) {
        int res = 0;
        vector<int> index(arr.size());
        iota(index.begin(), index.end(), 0);
        sort(index.begin(), index.end(), [&arr](int i1, int i2) {
            return arr[i1] == arr[i2] ? i1 < i2 : arr[i1] < arr[i2];
        });
        for (int i = 0, maxValue = -1; i < index.size(); i++) {
            maxValue = max(maxValue, index[i]);
            if (maxValue == i) {
                res++;
            }
        }
        return res;
    }
};
// LeetCode上最简单的写法
// https://discuss.leetcode.com/topic/117843/c-multiset
class Solution_42 {
  public:
    int maxChunksToSorted(vector<int> &arr) {
        int chunks = 0;
        multiset<int> cur;
        multiset<int> expect;
        vector<int> sorted = arr;
        sort(sorted.begin(), sorted.end());
        for (int i = 0; i < arr.size(); i++) {
            expect.insert(sorted[i]);
            cur.insert(arr[i]);
            if (cur == expect)
                chunks++;
        }
        return chunks;
    }
};