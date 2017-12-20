#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;
//自己的第一种方法，暴力破解的方法
class Solution {
  public:
    int maxProduct(vector<string> &words) {
        int result = 0;
        for (int i = 0; i < words.size(); i++) {
            set<char> directory(words[i].begin(), words[i].end());
            for (int j = i + 1; j < words.size(); j++) {
                int k = 0;
                for (k = 0; k < words[j].size(); k++) {
                    if (directory.find(words[j][k]) != directory.end()) {
                        break;
                    }
                }
                if (k == words[j].size()) {
                    int temp = words[i].size() * words[j].size();
                    result = max(result, temp);
                }
            }
        }
        return result;
    }
};
//上面的改进版 算法层面时间复杂度还是一样
class Solution_0 {
  public:
    int maxProduct(vector<string> &words) {
        sort(words.begin(), words.end(),
             [](string a, string b) { return a.size() > b.size(); });
        int result = 0;
        for (int i = 0; i < words.size(); i++) {
            set<char> directory(words[i].begin(), words[i].end());
            for (int j = i + 1; j < words.size(); j++) {
                int k = 0;
                for (k = 0; k < words[j].size(); k++) {
                    if (directory.find(words[j][k]) != directory.end()) {
                        break;
                    }
                }
                if (k == words[j].size()) {
                    int temp = words[i].size() * words[j].size();
                    result = max(result, temp);
                    break;
                }
            }
        }
        return result;
    }
};
// leetcode的解法 利用了bit位 写的非常的好
// https://discuss.leetcode.com/topic/35539/java-easy-version-to-understand
// https://discuss.leetcode.com/topic/31769/32ms-java-ac-solution
//下面是那位大神的解法
// https://discuss.leetcode.com/topic/31766/bit-shorter-c
class Solution_1 {
  public:
    int maxProduct(vector<string> &words) {
        vector<int> value(words.size(), 0);
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words[i].size(); j++) {
                value[i] |= (1 << (words[i][j] - 'a'));
            }
        }
        int result = 0;
        for (int i = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words.size(); j++) {
                if ((value[i] & value[j]) == 0) {
                    //  int temp = words[i].size() * words[j].size();
                    result =
                        max(result, int(words[i].size() * words[j].size()));
                }
            }
        }
        return result;
    }
};