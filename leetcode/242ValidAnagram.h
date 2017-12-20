#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <map>
using namespace std;
//一开始理解错了
//只需要求字母出现的次数是否是一样的，并不是任意连续的字母打乱顺序
class Solution {
  public:
    bool isAnagram(string s, string t) {
        int m = s.size(), n = t.size();
        if (m != n)
            return false;
        if (s.empty() && t.empty()) {
            return true;
        }
        vector<bool> dp(m + 1, false);
        dp[0] = true;
        for (int i = 1; i <= m; i++) {
            for (int k = 0; k < i; k++) {
                string remains = s.substr(k, i - k);
                string remaint = t.substr(k, i - k);
                reverse(remaint.begin(), remaint.end());
                if (dp[k] && remains == remaint) {
                    dp[i] = true;
                }
            }
        }
        return dp[m];
    }
};

class Solution_0 {
  public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;
        map<char, int> directory;
        for (int i = 0; i < s.size(); i++) {
            directory[s[i]]++;
            directory[t[i]]--;
        }
        for (auto element : directory)
            if (element.second != 0) {
                return false;
            }
        return true;
    }
};

void test() {
    Solution_0 s1;
    string s = "agdc";
    string t = "addg";
    if (s1.isAnagram(s, t)) {
        cout << "hello" << endl;
    }
}