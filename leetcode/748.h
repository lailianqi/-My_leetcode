#include <algorithm>
#include <map>
#include <string>
#include <vector>
using namespace std;

// 自己的第一种解法 成功ac
// leetcode的解法差不多一模一样 不过感觉我自己写的好
// https://leetcode.com/problems/shortest-completing-word/discuss/110137/Java-Solution-using-character-Array
class Solution {
  public:
    string shortestCompletingWord(string licensePlate, vector<string> &words) {
        vector<int> dir(26, 0);
        string res;
        for (int i = 0, m = licensePlate.size(); i < m; i++) {
            if (isalpha(licensePlate[i])) {
                dir[tolower(licensePlate[i]) - 'a']++;
            }
        }
        for (int i = 0; i < words.size(); i++) {
            if (isLegal(words[i], dir) &&
                (res == "" || res.size() > words[i].size())) {
                res = words[i];
            }
        }
        return res;
    }
    bool isLegal(string &s, vector<int> &dir) {
        vector<int> dirCopy(26, 0);
        for (int j = 0; j < s.size(); j++) {
            dirCopy[s[j] - 'a']++;
        }
        for (int j = 0; j < dirCopy.size(); j++) {
            if (dirCopy[j] < dir[j]) {
                return false;
            }
        }
        return true;
    }
};

// 另外一种思路的解法 其实思想差不多
// https://leetcode.com/problems/shortest-completing-word/discuss/110158/JavaC++-Clean-Code

class Solution_0 {
  public:
    string shortestCompletingWord(string s, vector<string> &words) {
        std::transform(s.begin(), s.end(), s.begin(), ::tolower);
        map<char, int> counts; // count for each chars in licensePlate
        int total = 0;         // total number of chars licensePlate
        for (char c : s) {
            if (isalpha(c)) {
                counts[c]++;
                total++;
            }
        }
        string res;
        for (string w : words) {
            int n = total;
            map<char, int> cnts = counts;
            for (int i = 0; i < w.size() && n; i++)
                n -= cnts[w[i]]-- > 0;
            if (n == 0 && (res.empty() || w.size() < res.size()))
                res = w;
        }
        return res;
    }
};

// 另外一种思路的解法 其实思想差不多
// https://leetcode.com/problems/shortest-completing-word/discuss/117849/Java-solution-17ms-using-char-array
/*
public String shortestCompletingWord(String licensePlate, String[] words) {
        int plate[] = new int[26], count = 0;
        for (char c : licensePlate.toCharArray())
            if (Character.isLetter(c)) {
                count++;
                plate[Character.toLowerCase(c) - 'a']++;
            }
        String shortest = null;
        for (String w : words) {
            int word[] = new int[26], currCount = 0;
            for (char c : w.toCharArray())
                if (word[c - 'a'] < plate[c - 'a']) {
                    word[c - 'a']++;
                    currCount++;
                    if (currCount == count) {
                        if (shortest == null || shortest.length() > w.length())
                            shortest = w;
                        break;
                    }
                }
        }
        return shortest;
    }
*/