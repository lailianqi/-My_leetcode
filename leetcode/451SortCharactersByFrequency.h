#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
//最快的方案 也是最简单的方案
// leetcode上面差不多的答案
// https://discuss.leetcode.com/topic/65914/concise-c-solution-using-stl-sort
class Solution {
  public:
    string frequencySort(string s) {
        vector<int> dir(256, 0);
        for (int i = 0; i < s.size(); i++) {
            dir[s[i]]++;
        }
        sort(s.begin(), s.end(), [&dir](char a, char b) {
            return dir[a] > dir[b] || (dir[a] == dir[b] && a < b);
        });
        return s;
    }
};

//上面的稍微的修改版
//这个方案比上面的慢多了
class Solution_0 {
  public:
    string frequencySort(string s) {
        map<char, int> dir;
        for (int i = 0; i < s.size(); i++) {
            dir[s[i]]++;
        }
        sort(s.begin(), s.end(), [&dir](char a, char b) {
            return dir[a] > dir[b] || (dir[a] == dir[b] && a < b);
        });
        return s;
    }
};

//终极的解法 就是不用排序
// leetcode的答案
// https://discuss.leetcode.com/topic/66045/c-o-n-solution-without-sort/2