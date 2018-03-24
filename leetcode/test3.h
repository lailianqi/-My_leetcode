#include <algorithm>
#include <map>
#include <string>
#include <vector>
using namespace std;
// https://www.nowcoder.com/discuss/70063
int distance(string &S, string &T) {
    int m = S.size(), n = T.size();
    int res = 0;
    for (int i = 0; i < m - n + 1; i++) {
        int distance = 0;
        for (int j = 0; j < n; j++) {
            if (S[i + j] != T[j]) {
                distance++;
            }
        }
        res += distance;
    }
    return res;
}
//改进版
int distance1(string &S, string &T) {
    int m = S.size(), n = T.size(), res = 0;
    int a = 0, b = 0;
    for (int i = 0; i < m; i++) {
        a += S[i] == 'a';
        b += S[i] == 'b';
    }
    res += T[0] == 'a' ? b : a;
    for (int i = 1; i < n; i++) {
        S[i - 1] == 'a' ? --a : --b;
        S[i + m - n] == 'a' ? ++a : ++b;
        res += T[i] == 'a' ? b : a;
    }
    return res;
}

// int miniNum(string &s) {
//     vector<int> dp(10, 0);
//     for (int i = 0; i < s.size(); i++) {
//         dp[s[i] - '0']++;
//     }
//     int i = 1;
//     while (true) {
//         vector<int> temp(10, 0);
//         int num = i;
//         while (num) {
//             temp[num % 10]++;
//             num /= 10;
//         }
//         for (int j = 0; j < 10; j++) {
//             if (temp[j] > dp[j]) {
//                 return i;
//             }
//         }
//         i++;
//     }
//     return 0;
// }

// int miniNum1(string &s) {
//     vector<int> dp(10, 0);
//     for (int i = 0; i < s.size(); i++) {
//         dp[s[i] - '0']++;
//     }
//     int index = min_element(dp.begin() + 1, dp.end()) - dp.begin();
//     int res = 0;
//     for (int i = 0; i < dp[index]; i++) {
//         res = res * 10 + index;
//     }
//     if (dp[0] == 0) {
//         res = res * 10;
//     } else {
//         res = res * 10 + index;
//     }
//     return res;
// }

string miniNum2(string s) {
    vector<int> dp(10, 0);
    for (int i = 0; i < s.size(); i++) {
        dp[s[i] - '0']++;
    }
    int index = min_element(dp.begin() + 1, dp.end()) - dp.begin();
    return (*dp.begin() + 1 <= dp[index])
               ? ("1" + string(dp[0] + 1, '0'))
               : (string(dp[index] + 1, index + '0'));
}