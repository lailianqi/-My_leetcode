#include <string>
#include <algorithm>
#include <vector>
using namespace std;
//比较简单 下面是自己的解法
class Solution {
  public:
    string toHex(int num) {
        if (num == 0) {
            return "0";
        }
        vector<char> map = {'0', '1', '2', '3', '4', '5', '6', '7',
                            '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
        string res;
        while (num && res.size() < 8) { //加上范围限制 防止负数导致的无限循环
            res.push_back(map[num & 15]);
            num >>= 4;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// leetcode的解法
// https://discuss.leetcode.com/topic/60365/simple-java-solution-with-comment?page=1
//https://discuss.leetcode.com/topic/60365/simple-java-solution-with-comment/6?page=1