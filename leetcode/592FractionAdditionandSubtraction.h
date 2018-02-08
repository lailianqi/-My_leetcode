#include <sstream>
#include <string>
using namespace std;
// 这题没写出来 直接看的答案  答案来自sp大神
// https://discuss.leetcode.com/topic/90061/small-simple-c-java-python
class Solution {
  public:
    string fractionAddition(string expression) {
        istringstream in(expression);
        int A = 0, B = 1, a, b;
        char _;
        while (in >> a >> _ >> b) {
            A = A * b + a * B;
            B *= b;
            int g = abs(gcd(A, B));
            A /= g;
            B /= g;
        }
        return to_string(A) + '/' + to_string(B);
    }
    int gcd(int a, int b) { return a == 0 ? b : gcd(b % a, a); }
};

// 第二种写法  来自LeetCode 也非常的精彩
// https://discuss.leetcode.com/topic/89991/concise-java-solution