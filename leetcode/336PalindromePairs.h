#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
//第一个自己的想法 暴力破解 肯定会超时 无法ac
class Solution {
  public:
    vector<vector<int>> palindromePairs(vector<string> &words) {
        vector<vector<int>> result;
        for (int i = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words.size(); j++) {
                if (judgePalindromic(words[i] + words[j])) {
                    vector<int> temp;
                    temp.push_back(i);
                    temp.push_back(j);
                    result.push_back(temp);
                }
                if (judgePalindromic(words[j] + words[i])) {
                    vector<int> temp;
                    temp.push_back(j);
                    temp.push_back(i);
                    result.push_back(temp);
                }
            }
        }
        return result;
    }
    bool judgePalindromic(string s) {
        for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
            if (s[i] != s[j]) {
                return false;
            }
        }
        return true;
    }
};
// leetcode的答案
// https://discuss.leetcode.com/topic/40654/easy-to-understand-ac-c-solution-o-n-k-2-using-map
class Solution_0 {
  public:
    vector<vector<int>> palindromePairs(vector<string> &words) {
        vector<vector<int>> result;
        unordered_map<string, int> dict;
        // build direction
        for (int i = 0; i < words.size(); i++) {
            string key = words[i];
            reverse(key.begin(), key.end());
            dict[key] = i;
        }
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words[i].size(); j++) {
                string left = words[i].substr(0, j);
                string right = words[i].substr(j);
                if (dict.find(right) != dict.end() && isPalindrome(left) &&
                    dict[right] != i) {
                    result.push_back({dict[right], i});
                }
                if (dict.find(left) != dict.end() && isPalindrome(right) &&
                    dict[left] != i) {
                    result.push_back({i, dict[left]});
                    if (left.empty())
                        result.push_back({dict[left], i});
                }
            }
        }
        return result;
    }
    bool isPalindrome(string s) {
        for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
            if (s[i] != s[j]) {
                return false;
            }
        }
        return true;
    }
};