#include <map>
#include <string>
using namespace std;
//自己的答案,嫌麻烦直接用的map
// leetcode的答案和自己的想法一模一样
// https://discuss.leetcode.com/topic/28463/one-pass-java-solution
class Solution {
  public:
    string getHint(string secret, string guess) {
        map<char, int> directory;
        int bullsNum = 0, cowsNum = 0;
        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i]) {
                bullsNum++;
            } else {
                if (directory[secret[i]]++ < 0) {
                    cowsNum++;
                }
                if (directory[guess[i]]-- > 0) {
                    cowsNum++;
                }
            }
        }
        return to_string(bullsNum) + "A" + to_string(cowsNum) + "B";
    }
};

//另外一种想法
// https://discuss.leetcode.com/topic/28466/python-3-lines-solution/2
// https://discuss.leetcode.com/topic/28457/3-lines-in-python