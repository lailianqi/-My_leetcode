#include <string>
#include <vector>
#include <iostream>
using namespace std;
class Solution {
  public:
    int numDecodings(string s) {
        if (s.length() == 0 || s[0] == '0')
            return 0;
        int m = s.length();
        vector<int> dp(m + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= s.length(); i++) {
            dp[i] = (int)(s[i - 1] != '0') * dp[i - 1] + (int)((s[i - 2] == '1') || (s[i - 2] == '2' && s[i - 1] < '7')) * dp[i - 2];
        }
        return dp[m];
    }
};

void test() {
    Solution s;
    cout << s.numDecodings("10") << endl;
}