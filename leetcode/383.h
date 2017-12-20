#include <string>
#include <vector>
#include <map>
using namespace std;

class Solution {
  public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.size() > magazine.size()) {
            return false;
        }
        map<char, int> directory;
        for (int i = 0; i < magazine.size(); i++) {
            directory[magazine[i]]++;
        }
        for (int i = 0; i < ransomNote.size(); i++) {
            if (--directory[ransomNote[i]] < 0) {
                return false;
            }
        }
        return true;
    }
};
//节省空间的改进版 // 速度非常的快
class Solution_0 {
  public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> directory(26, 0);
        for (int i = 0; i < magazine.size(); i++) {
            directory[magazine[i] - 'a']++;
        }
        for (int i = 0; i < ransomNote.size(); i++) {
            if (--directory[ransomNote[i] - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};