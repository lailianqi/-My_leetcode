#include <vector>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;
//简单题 一次性ac 改用了unordered_map而不是map（一开始用的map） 提高了很多的效率
class Solution {
  public:
    vector<string> findWords(vector<string> &words) {
        vector<string> res;
        vector<vector<char>> Aphas = {
            {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'},
            {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'},
            {'z', 'x', 'c', 'v', 'b', 'n', 'm'}};
        unordered_map<char, int> dir;
        for (int i = 0; i < Aphas.size(); i++) {
            for (int j = 0; j < Aphas[i].size(); j++) {
                dir[Aphas[i][j]] = i;
            }
        }
        for (int i = 0; i < words.size(); i++) {
            if (keyboardRow(words[i], dir)) {
                res.push_back(words[i]);
            }
        }
        return res;
    }
    bool keyboardRow(string &word, unordered_map<char, int> &dir) {
        for (int i = 1; i < word[i]; i++) {
            if (dir[tolower(word[i])] != dir[tolower(word[i - 1])]) {
                return false;
            }
        }
        return true;
    }
};