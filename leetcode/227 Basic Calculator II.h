#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
/*
"3+2*2" = 7
" 3/2 " = 1
" 3+5 / 2 " = 5
*/
// leetcode的解法 自己没有想出来
// https://discuss.leetcode.com/topic/16935/share-my-java-solution/26?page=2
class Solution {
  public:
    int calculate(string s) {
        vector<int> nums;
        int number = 0;
        s = s + "+";
        char sign = '+';
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') {
                if (s[i] >= '0' && s[i] <= '9') {
                    number = 10 * number + (int)(s[i] - '0');
                    continue;
                }
                if (sign == '+') {
                    nums.push_back(number);
                } else if (sign == '-') {
                    nums.push_back(-number);
                } else if (sign == '*') {
                    nums.back() = nums.back() * number;
                } else if (sign == '/') {
                    nums.back() = nums.back() / number;
                }
                sign = s[i];
                number = 0;
            }
        }
        return accumulate(nums.begin(), nums.end(), 0);
    }
};