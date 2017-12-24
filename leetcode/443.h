#include <vector>
#include <string>
using namespace std;
//自己的第一种写法 成功ac
//发现leetcode的答案和我第一次写的思路一模一样 连代码也基本上99%相似
// https://discuss.leetcode.com/topic/108864/java-o-n-two-pointers-and-a-counter
class Solution {
  public:
    int compress(vector<char> &chars) {
        int length = 0, counter = 0, m = chars.size();
        for (int i = 0; i < chars.size(); i++) {
            counter++;
            if ((i < m - 1 && chars[i] != chars[i + 1]) || (i == m - 1)) {
                chars[length++] = chars[i];
                if (counter != 1) {
                    string temp = to_string(counter);
                    for (int j = 0; j < temp.size(); j++) {
                        chars[length++] = temp[j];
                    }
                }
                counter = 0;
            }
        }
        return length;
    }
};