#include <vector>
#include <string>
using namespace std;
// leetCode的答案
class Solution {
  public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        int len = s.size();
        for (int i = 1; i < 4 && i < len - 2; i++) {
            for (int j = i + 1; j < i + 4 && j < len - 1; j++) {
                for (int k = j + 1; k < j + 4 && k < len; k++) {
                    if (len - k > 3)
                        continue;
                    string a = s.substr(0, i);
                    string b = s.substr(i, j - i);
                    string c = s.substr(j, k - j);
                    string d = s.substr(k, len - k);
                    if (isValid(a) && isValid(b) && isValid(c) && isValid(d))
                        res.push_back(a + '.' + b + '.' + c + '.' + d);
                }
            }
        }
        return res;
    }
    bool isValid(string s) {
        if (atoi(s.c_str()) > 255 || s[0] == '0' && s.size() > 1)
            return false;
        return true;
    }
};

// https://discuss.leetcode.com/topic/3919/my-code-in-java/15    #10
class Solution_0 {
  public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        doRestore(result, "", s, 0);
        return result;
    }
    void doRestore(vector<string> &result, string path, string s, int k) {
        if (s.empty() || k == 4) {
            if (s.empty() && k == 4) {
                result.push_back(path.substr(1));
            }
            return;
        }
        for (int i = 1; i <= s.length() && i <= (s[0] == '0' ? 1 : 3); i++) {
            if (stoi(s.substr(0, i)) <= 255)
                doRestore(result, path + "." + s.substr(0, i), s.substr(i), k + 1);
        }
    }
};