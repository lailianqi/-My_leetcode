#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
//难点在于比较函数
//当初并没有写出比较函数
// https://discuss.leetcode.com/topic/8018/my-java-solution-to-share
// https://discuss.leetcode.com/topic/7286/a-simple-c-solution
// https://discuss.leetcode.com/topic/36004/mathematical-proof-of-correctness-of-sorting-method
class Solution {
  public:
    string largestNumber(vector<int> &nums) {
        vector<string> arr;
        for (auto num : nums) {
            arr.push_back(to_string(num));
        }
        sort(arr.begin(), arr.end(),
             [](string &s1, string &s2) { return s1 + s2 > s2 + s1; });
        string result;
        for (auto s : arr) {
            result += s;
        }
        while (result[0] == '0' && result.size() > 1)
            result.erase(0, 1);
        return result;
    }
    //  static bool compare(string &a, string &b) { return a + b >= b + a; }
};