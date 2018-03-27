#include <algorithm>
#include <iomanip>
#include <iostream>
#include <set>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;
// 网上的分析
// https://www.cnblogs.com/whistle13326/p/7668554.html

class solution_1 {
  public:
    int test() {
        string res;
        int n = 0;
        cin >> n;
        while (n > 0) {
            if (n % 2 == 0) {
                res += '2';
                n = (n - 2) / 2;
            } else {
                res += '1';
                n = (n - 1) / 2;
            }
        }
        reverse(res.begin(), res.end());
        cout << res << endl;
        return 0;
    }
};

class solution_2 {
  public:
    void test() {
        int n = 0;
        cin >> n;
        string s = to_string(n);
        reverse(s.begin(), s.end());
        int b = stoi(s);
        cout << n + b << endl;
    }
};

class solution_3 {
  public:
    void test() {
        string s;
        cin >> s;
        int num = 1, m = s.size();
        for (int i = 1; i < m; i++) {
            if (s[i] != s[i - 1]) {
                num++;
            }
        }
        // cout << setprecision(3) << 1.0 * m / num << endl;
        printf("%.2f", 1.0 * m / num);
    }
};

// 这题写不出来 直接看的答案
// https://www.nowcoder.com/test/question/done?tid=14519324&qid=126951#summary
class solution_4 {
  public:
    // 自己的原始的解法 是错误的答案
    void test() {
        int m, n, res = 1;
        cin >> m >> n;
        vector<int> parent(m, 0);
        for (int i = 0; i < m; i++) {
            parent[i] = i;
        }
        for (int i = 0; i < m - 1; i++) {
            int temp;
            cin >> temp;
            parent[i + 1] = temp;
        }
        for (int i = 0; i < m; i++) {
            int counter = 1, index = i, limitNum = n;
            while (parent[index] != index && limitNum--) {
                index = parent[index];
                counter++;
            }
            res = max(res, counter);
        }
        cout << res << endl;
    }
    // 正确的答案的解法
    void test1() {
        int m, n, res = 0;
        cin >> m >> n;
        vector<int> parent(m, 0), dp(m, 0);
        for (int i = 0; i < m - 1; i++) {
            int temp;
            cin >> temp;
            parent[i] = temp;
        }
        for (int i = 0; i < m - 1; i++) {
            dp[i + 1] = dp[parent[i]] + 1;
            res = max(res, dp[i + 1]);
        }
        int d = min(n, res);
        cout << min(m, 1 + d + (n - d) / 2) << endl;
    }
};

class solution_5 {
  public:
    void test() {
        int t = 0, m = 0, n = 0;
        cin >> t;
        while (t--) {
            cin >> m;
            int cnt1 = 0, cnt2 = 0, cnt4 = 0;
            for (int i = 0; i < m; i++) {
                cin >> n;
                if (n % 4 == 0) {
                    cnt4++;
                } else if (n % 2 == 0) {
                    cnt2++;
                } else {
                    cnt1++;
                }
            }
            cout << ((cnt4 >= (cnt1 - 1 + (cnt2 > 0))) ? "Yes" : "No") << endl;
        }
    }
};

// 这题的题意我一开始就没看懂 真是日了狗了
class solution_6 {
  public:
    bool isValidBracket(string str) {
        int tmp = 0, len = str.size();
        for (int i = 0; i < len; i++) {
            tmp += (str[i] == '(') ? 1 : -1;
            if (tmp < 0) {
                return false;
            }
        }
        return true;
    }
    int test() {
        string str;
        cin >> str;
        set<string> dir;
        int m = str.size();
        for (int i = 0; i < m; i++) {
            string s = str.substr(0, i) + str.substr(i + 1);
            for (int j = 0; j < m - 1; j++) {
                string u = s.substr(0, j) + str[i] + s.substr(j);
                if (isValidBracket(u)) {
                    dir.insert(u);
                }
            }
        }
        return dir.size() - 1;
    }
};
// 没写出来 直接看的答案
// https://blog.csdn.net/zjucor/article/details/78071216
// https://www.cnblogs.com/whistle13326/p/7668554.html
// https://www.cnblogs.com/joeylee97/p/7607407.html
// https://www.nowcoder.com/questionTerminal/fddf64d5757e41ec93f3ef0c0a10b891

// 递归的写法 会超时 但是容易明白原理
class solution_7 {
  public:
    int test() {
        int n;
        cin >> n;
        vector<int> v(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        cout << minSum(v) << endl;
        return 0;
    }
    int minSum(vector<int> &v) {
        int m = v.size();
        vector<vector<int>> dp(m, vector<int>(m));
        return helper(v, -1, -1, dp);
    }
    int helper(vector<int> &v, int i, int j, vector<vector<int>> &dp) {
        if (i >= 0 && j >= 0 && dp[i][j] != 0) {
            return dp[i][j];
        }
        int next = max(i, j) + 1, m = v.size();
        if (next == m) {
            return 0;
        }
        int res =
            min(helper(v, next, j, dp) + (i == -1 ? 0 : abs(v[next] - v[i])),
                helper(v, i, next, dp) + (j == -1 ? 0 : abs(v[next] - v[j])));
        if (i >= 0 && j >= 0) {
            dp[i][j] = res;
        }
        return res;
    }
};
// dp的写法 参考自
// https://blog.csdn.net/zjucor/article/details/78071216
class solution_7_1 {
  public:
    int test() {
        int n;
        cin >> n;
        vector<int> v(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        cout << minSum(v) << endl;
        return 0;
    }
    int minSum(vector<int> &v) {
        int m = v.size();
        vector<vector<int>> dp(m + 1, vector<int>(m + 1, 0));
        for (int i = m - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int next = max(i, j) + 1;
                dp[i][j] = min(
                    dp[next][j] + (i == 0 ? 0 : abs(v[next - 1] - v[i - 1])),
                    dp[i][next] + (j == 0 ? 0 : abs(v[next - 1] - v[j - 1])));
            }
        }
        return dp[0][0];
    }
};

// 就是两条垂直线最多经过多少个焦点
// https://blog.csdn.net/zjucor/article/details/78071216
class solution_8 {
  public:
    int test() {}
};