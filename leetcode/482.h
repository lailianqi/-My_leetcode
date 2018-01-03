#include <string>
#include <algorithm>
using namespace std;
//自己的第一种写法 成功ac 但是代码太长
class Solution {
  public:
    string licenseKeyFormatting(string S, int K) {
        int counter = 0;
        string res;
        for (int j = S.size() - 1; j >= 0; j--) {
            if (S[j] != '-') {
                res.push_back(toupper(S[j]));
                if (++counter % K == 0) {
                    res.push_back('-');
                }
            }
        }
        reverse(res.begin(), res.end());
        if (!res.empty() && *res.begin() == '-') {
            res.erase(res.begin());
        }
        return res;
    }
};

//根据leetcode的答案自己改进上面自己的答案
// https://discuss.leetcode.com/topic/74995/java-5-lines-clean-solution
// https://discuss.leetcode.com/topic/74993/4-line-c-concise-solution-to-scan-string-backward
class Solution_0 {
  public:
    string licenseKeyFormatting(string S, int K) {
        string res;
        for (int j = S.size() - 1; j >= 0; j--) {
            if (S[j] != '-') {
                (res.size() % (K + 1) == K ? res += '-' : res) += toupper(S[j]);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
