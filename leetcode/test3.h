#include <algorithm>
#include <map>
#include <string>
#include <vector>
using namespace std;

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

int miniNum(string &s) {
    vector<int> dp(10, 0);
    for (int i = 0; i < s.size(); i++) {
        dp[s[i] - '0']++;
    }
    int i = 1;
    while (true) {
        vector<int> temp(10, 0);
        int num = i;
        while (num) {
            temp[num % 10]++;
            num /= 10;
        }
        for (int j = 0; j < 10; j++) {
            if (temp[j] > dp[j]) {
                return i;
            }
        }
        i++;
    }
    return 0;
}

int miniNum1(string &s) {
    vector<int> dp(10, 0);
    for (int i = 0; i < s.size(); i++) {
        dp[s[i] - '0']++;
    }
    int index = min_element(dp.begin() + 1, dp.end()) - dp.begin();
    int res = 0;
    for (int i = 0; i < dp[index]; i++) {
        res = res * 10 + index;
    }
    if (dp[0] == 0) {
        res = res * 10;
    } else {
        res = res * 10 + index;
    }
    return res;
}