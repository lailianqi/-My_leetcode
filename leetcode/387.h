#include <string>
#include <vector>
using namespace std;
//自己最牛逼的方法
//和leetcode的答案一模一样
// https://discuss.leetcode.com/topic/55148/java-7-lines-solution-29ms/2
class Solution {
  public:
    int firstUniqChar(string s) {
        vector<int> dir(26, 0);
        for (int i = 0; i < s.size(); i++) {
            dir[s[i] - 'a']++;
        }
        for (int i = 0; i < s.size(); i++) {
            if (dir[s[i] - 'a'] == 1) {
                return i;
            }
        }
        return -1;
    }
};