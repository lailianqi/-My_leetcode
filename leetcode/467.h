#include <string>
#include <vector>
#include <algorithm>
using namespace std;
//自己的第一种解法 成功ac
// leetcode上相似的解法
// https://discuss.leetcode.com/topic/70658/concise-java-solution-using-dp?page=1
class Solution {
  public:
    int findSubstringInWraproundString(string p) {
        vector<int> dir(26, 0);
        int length = 1;
        for (int i = 0; i < p.size(); i++) {
            if (i > 0 && (p[i] == p[i - 1] + 1 || p[i - 1] - p[i] == 25)) {
                length++;
            } else {
                length = 1;
            }
            dir[p[i] - 'a'] = max(dir[p[i] - 'a'], length);
        }
        return accumulate(dir.begin(), dir.end(), 0);
    }
};

// leetcode上更短的解法
// https://discuss.leetcode.com/topic/70654/c-concise-solution/5
class Solution_0 {
  public:
    int findSubstringInWraproundString(string p) {
        vector<int> dir(26, 0);
        int length = 0;
        for (int i = 0; i < p.size(); i++) {
            int cur = p[i] - 'a';
            if (i > 0 && p[i - 1] != (cur + 26 - 1) % 26 + 'a') {
                length = 0;
            }
            dir[cur] = max(dir[cur], ++length);
        }
        return accumulate(dir.begin(), dir.end(), 0);
    }
};