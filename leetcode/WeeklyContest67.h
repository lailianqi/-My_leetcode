#include <algorithm>
#include <map>
#include <string>
#include <vector>
using namespace std;
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
// 成功ac
class Solution_1 {
  public:
    vector<int> partitionLabels(string S) {
        // map<char, int> dir;
        // for (int i = 0; i < S.size(); i++) {
        //     dir[S[i]]++;
        // }
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
//超时
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