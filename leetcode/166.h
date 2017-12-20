#include <string>
#include <cmath>
#include <map>
using namespace std;
// https://discuss.leetcode.com/topic/7876/my-clean-java-solution
// https://discuss.leetcode.com/topic/6079/accepted-cpp-solution-with-explainations?page=1
// leetcode的答案
class Solution {
  public:
    string fractionToDecimal(int64_t numerator, int64_t denominator) {
        if (numerator == 0)
            return "0";
        string res;
        if (numerator < 0 ^ denominator < 0)
            res += '-';
        numerator = abs(numerator);
        denominator = abs(denominator);
        res += to_string(numerator / denominator);
        if (numerator % denominator == 0)
            return res;
        res += '.';
        map<int, int> directory;
        for (int64_t remainer = numerator % denominator; remainer;
             remainer %= denominator) {
            if (directory.count(remainer) > 0) {
                res.insert(directory[remainer], 1, '(');
                res += ')';
                break;
            }
            directory[remainer] = res.size();
            remainer *= 10;
            res += to_string(remainer / denominator);
        }
        return res;
    }
};