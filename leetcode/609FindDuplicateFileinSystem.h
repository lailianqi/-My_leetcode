#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// 这题没写出来  对文件系统缺乏理解
// 直接看的LeetCode的答案
// https://discuss.leetcode.com/topic/91430/c-clean-solution-answers-to-follow-up
class Solution {
  public:
    vector<vector<string>> findDuplicate(vector<string> &paths) {
        unordered_map<string, vector<string>> files;
        vector<vector<string>> result;
        for (int i = 0; i < paths.size(); i++) {
            stringstream ss(paths[i]);
            string root, s;
            getline(ss, root, ' ');
            while (getline(ss, s, ' ')) {
                string fileName = root + '/' + s.substr(0, s.find('('));
                string fileContent =
                    s.substr(s.find('(') + 1, s.find(')') - s.find('(') - 1);
                files[fileContent].push_back(fileName);
            }
        }
        for (auto file : files) {
            if (file.second.size() > 1) {
                result.push_back(file.second);
            }
        }
        return result;
    }
};

// 还有一种很牛逼的java的解法
// https://discuss.leetcode.com/topic/91301/straight-forward-solution-with-a-tiny-bit-of-java8