#include <vector>
#include <string>
#include <set>
#include <map>
using namespace std;
//自己的解法，好像效率不高
//如果用s.size() - 10 为无符号数的减法，会出现问题
class Solution {
  public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        int m = s.size();
        map<string, int> directory;
        for (int i = 0; i <= m - 10; i++) {
            directory[s.substr(i, 10)]++;
        }
        for (auto element : directory) {
            if (element.second > 1) {
                res.push_back(element.first);
            }
        }
        return res;
    }
};
// https://discuss.leetcode.com/topic/8894/clean-java-solution-hashmap-bits-manipulation
class Solution_0 {
  public:
    vector<string> findRepeatedDnaSequences(string s) {
        set<int> words;
        set<int> doubleWords;
        int m = s.size();
        vector<string> res;
        map<char, int> directory;
        directory['A'] = 0;
        directory['C'] = 1;
        directory['G'] = 2;
        directory['T'] = 3;
        for (int i = 0; i < m - 9; i++) {
            int v = 0;
            for (int j = i; j < i + 10; j++) {
                v <<= 2;
                v |= directory[s[j]];
            }
            if (words.count(v)) {
                if (!doubleWords.count(v)) {
                    res.push_back(s.substr(i, 10));
                    doubleWords.insert(v);
                }
            } else {
                words.insert(v);
            }
        }
        return res;
    }
};

void test() {
    Solution_0 s;
    string s1 = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    s.findRepeatedDnaSequences(s1);
}