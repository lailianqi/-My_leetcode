#include <string>
#include <vector>
#include <map>
using namespace std;

// 这是来自LeetCode的解法 第二遍还是看了答案 这种解法的思想有点暴力
// https://leetcode.com/problems/substring-with-concatenation-of-all-words/discuss/13658/Easy-Two-Map-Solution-(C++Java)
// 更好的版本去看python的

class Solution {
  public:
    vector<int> findSubstring(string s, vector<string> &words) {
        map<string, int> wordsMap;
        vector<int> answer;
        int sL = s.length(), wNum = words.size(), wL = words[0].length();
        for (string word : words) {
            wordsMap[word]++;
        }
        for (int i = 0; i < sL - wNum * wL + 1; i++) {
            int j = 0;
            map<string, int> wordsCountMap;
            while (j < wNum) {
                string word = s.substr(i + j * wL, wL);
                if (wordsMap.find(word) != wordsMap.end()) {
                    wordsCountMap[word]++;
                    if (wordsCountMap[word] > wordsMap[word]) {
                        break;
                    }
                } else {
                    break;
                }
                j++;
            }
            if (j == wNum) {
                answer.push_back(i);
            }
        }
        return answer;
    }
};