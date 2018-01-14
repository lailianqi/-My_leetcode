#include <algorithm>
#include <map>
#include <string>
#include <atomic>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <set>
using namespace std;
/***********第一题************************/
// 成功ac
class Solution {
  public:
    int countPrimeSetBits(int L, int R) {
        int res = 0;
        for (int i = L; i <= R; i++) {
            if (isprime(countBit(i))) {
                res++;
            }
        }
        return res;
    }
    int countBit(int num) {
        int res = 0;
        for (int i = 0; i < 32; i++) {
            if (num & 1) {
                res++;
            }
            num >>= 1;
        }
        return res;
    }
    bool isprime(int n) {
        if (n == 1)
            return false;
        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
};

// leetcode上面比自己ac的第一个答案这个牛逼多的写法
// https://discuss.leetcode.com/topic/117013/java-c-clean-code
class Solution_0 {
  public:
    int countPrimeSetBits(int L, int R) {
        set<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        int cnt = 0;
        for (int i = L; i <= R; i++) {
            int bits = 0;
            for (int n = i; n; n >>= 1)
                bits += n & 1;
            cnt += primes.count(bits);
        }
        return cnt;
    }
};
// leetcode的答案 用dp的写法 非常的独特 不比上面的差
// https://discuss.leetcode.com/topic/117036/easy-o-n-java-solution-using-dp

/**********第二题*********************/

// 成功ac
class Solution_1 {
  public:
    vector<int> partitionLabels(string S) {
        vector<int> res;
        helper(S, 0, res);
        return res;
    }
    void helper(string S, int start, vector<int> &res) {
        if (start >= S.size()) {
            return;
        }
        int end = S.find_last_of(S[start]);
        for (int i = start + 1; i <= end; i++) {
            int temp = S.find_last_of(S[i]);
            if (temp > end) {
                end = temp;
            }
        }
        res.push_back(end - start + 1);
        helper(S, end + 1, res);
    }
};
// leetcode的答案 有点问题 数组会越界的 但是作者自己没有发现
// https://discuss.leetcode.com/topic/117037/c-5-lines-o-n-o-1-two-simple-passes
class Solution_11 {
  public:
    vector<int> partitionLabels(string S) {
        vector<int> res, pos(26, 0);
        for (auto i = 0; i < S.size(); ++i)
            pos[S[i] - 'a'] = i;
        for (int i = 0, idx = INT_MIN, last_i = 0; i < S.size(); i++) {
            idx = max(idx, pos[S[i] - 'a']);
            if (idx == i) {
                res.push_back(i - last_i + 1);
                last_i = i + 1;
                // res.push_back(i - exchange(last_i, i + 1) + 1);
            }
        }
        return res;
    }
};
//下面是滑动窗口的写法 来自leetcode
// https://discuss.leetcode.com/topic/117010/easy-o-n-java-solution-using-sliding-window-two-pointers-comments-and-explanation-given
class Solution_12 {
  public:
    vector<int> partitionLabels(string S) {
        vector<int> res, dir(26, 0);
        for (int i = 0; i < S.size(); i++) {
            dir[S[i] - 'a']++;
        }
        int i = 0, j = 0, counter = 0;
        unordered_map<char, int> hs;
        while (j < S.size()) {
            if (!hs.count(S[j])) {
                hs[S[j]] = 1;
                counter++;
            }
            dir[S[j] - 'a']--;
            if (dir[S[j] - 'a'] == 0) {
                counter--;
                hs.erase(S[j]);
            }
            if (counter == 0) {
                res.push_back(j - i + 1);
                i = j + 1;
            }
            j++;
        }
        return res;
    }
};

void test() {
    Solution_12 s;
    string sb = "ababcbacadefegdehijhklij";
    s.partitionLabels(sb);
}
/***********第三题***********/
//超时的写法 比赛中一直超时
class Solution_2 {
  public:
    int orderOfLargestPlusSign(int N, vector<vector<int>> &mines) {
        int res = 0;
        vector<vector<int>> matrix(N, vector<int>(N, 1));
        for (int i = 0; i < mines.size(); i++) {
            matrix[mines[i][0]][mines[i][1]] = 0;
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (matrix[i][j] == 1) {
                    helper(i, j, matrix, res);
                }
            }
        }
        return res;
    }
    void helper(int x, int y, vector<vector<int>> &mines, int &res) {
        int up = 1, down = 1, left = 1, right = 1;
        while (x - up >= 0 && mines[x - up][y] == 1) {
            up++;
        }
        while (x + down < mines.size() && mines[x + down][y] == 1) {
            down++;
        }
        while (y - left >= 0 && mines[x][y - left] == 1) {
            left++;
        }
        while (y + right < mines[0].size() && mines[x][y + right] == 1) {
            right++;
        }
        res = max(res, min(min(up, down), min(left, right)));
    }
};
// leetcode的写法 也是暴力 感觉和上面的解法猜不到 不知道为什么就能过
// https://discuss.leetcode.com/topic/117022/c-simple-brute-force-easy-to-understand-with-detailed-explanation
class Solution_21 {
  public:
    int orderOfLargestPlusSign(int N, vector<vector<int>> &mines) {
        int res = 0;
        vector<vector<int>> matrix(N, vector<int>(N, 1));
        for (int i = 0; i < mines.size(); i++) {
            matrix[mines[i][0]][mines[i][1]] = 0;
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                int k = 0;
                while (canExpand(N, i, j, matrix, k))
                    ++k;
                res = max(res, k);
            }
        }
        return res;
    }
    bool canExpand(int N, int x, int y, vector<vector<int>> &m, int k) {
        if (x - k < 0 || y - k < 0 || x + k >= N || y + k >= N)
            return false;
        return m[x - k][y] && m[x][y + k] && m[x + k][y] && m[x][y - k];
    }
};

// leetcode的另外的一种写法 空间换时间
// https://discuss.leetcode.com/topic/117012/c-brute-force
class Solution_22 {
  public:
    int orderOfLargestPlusSign(int n, vector<vector<int>> &mines) {
        vector<vector<int>> grid(n, vector<int>(n, 1));
        for (auto p : mines)
            grid[p[0]][p[1]] = 0;

        vector<vector<vector<int>>> cube(
            4, vector<vector<int>>(n + 2, vector<int>(n + 2)));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int _i = n - 1 - i, _j = n - 1 - j;
                cube[0][i][j] =
                    !grid[i][j]
                        ? 0
                        : 1 + (j == 0 ? 0 : cube[0][i][j - 1]); // left 2 right
                cube[1][i][j] =
                    !grid[i][j]
                        ? 0
                        : 1 + (i == 0 ? 0 : cube[1][i - 1][j]); // top down
                cube[2][i][_j] =
                    !grid[i][_j]
                        ? 0
                        : 1 + (_j == n - 1
                                   ? 0
                                   : cube[2][i][_j + 1]); // right 2 left
                cube[3][_i][j] =
                    !grid[_i][j]
                        ? 0
                        : 1 + (_i == n - 1 ? 0
                                           : cube[3][_i + 1][j]); // bottom up
            }
        }

        int order = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                order = max(order, min({cube[0][i][j], cube[1][i][j],
                                        cube[2][i][j], cube[3][i][j]}));
            }
        }
        return order;
    }
};

/*********第四题**********/
//这题没有赶上写
//这道题的难度是困难 但是实际上非常的简单
// leetcode的答案
// https://discuss.leetcode.com/topic/117015/c
class Solution_3 {
  public:
    int minSwapsCouples(vector<int> &row) {
        for (int &i : row)
            i /= 2;
        int len = 0;
        for (auto it = row.begin(); it != row.end(); it += 2) {
            if (*it != *(it + 1)) {
                auto target = find(it + 2, row.end(), *it);
                iter_swap(it + 1, target);
                ++len;
            }
        }
        return len;
    }
};