#include <string>
#include <sstream>
using namespace std;
//因为觉得分割字符串不会怎么写，就直接看了答案
// https://discuss.leetcode.com/topic/46836/clear-c-solution
class Solution {
  public:
    bool isValidSerialization(string preorder) {
        int diff = 1;
        istringstream ss(preorder);
        string temp;
        while (getline(ss, temp, ',')) {
            if (--diff < 0) {
                return false;
            }
            if (temp != "#") {
                diff += 2;
            }
        }
        return diff == 0;
    }
};

//另外的一种解法 使用stack
// https://discuss.leetcode.com/topic/35973/java-intuitive-22ms-solution-with-stack