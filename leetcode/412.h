#include <vector>
#include <string>
using namespace std;
//简单题 马上就写出来了  自己的解法
// leetcode上并没有更好的解法
class Solution {
  public:
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        for (int i = 1; i <= n; i++) {
            string temp;
            if (i % 3 == 0) {
                temp = "Fizz";
            }
            if (i % 5 == 0) {
                temp += "Buzz";
            }
            res.push_back(temp.empty() ? to_string(i) : temp);
        }
        return res;
    }
};