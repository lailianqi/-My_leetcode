#include <string>
#include <vector>
#include <map>
using namespace std;
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