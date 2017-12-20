#include <string>
#include <vector>
#include <sstream>
using namespace std;
//"dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext"
// leetcode的答案
// https://discuss.leetcode.com/topic/55247/9-lines-4ms-java-solution/12
class Solution {
  public:
    int lengthLongestPath(string input) {
        int res = 0;
        vector<string> vt = split(input);
        vector<int> level(100, 0);
        for (string element : vt) {
            int count = element.find_last_of('\t') + 1;
            //主要是算长度的时候加上/
            level[count + 1] = level[count] + element.size() - count + 1;
            if (element.find('.') != -1) {
                res = max(res, level[count + 1] - 1);
            }
        }
        return res;
    }
    vector<string> split(string &s) {
        vector<string> res;
        stringstream ss(s);
        string str;
        while (getline(ss, str)) {
            res.push_back(str);
        }
        return res;
    }
};