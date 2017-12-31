
#include <cmath>
#include <string>
using namespace std;
//根本就不是简单题 没有想出来
// LeetCode的答案
// https://discuss.leetcode.com/topic/74125/java-solution-using-assumed-max-palindrom/20?page=1
// https://discuss.leetcode.com/topic/74125/java-solution-using-assumed-max-palindrom/26?page=2
class Solution {
  public:
    int largestPalindrome(int n) {
        if (n == 1)
            return 9;
        long maxNum = (long)pow(10, n) - 1;
        long minNum = (long)pow(10, n - 1);
        long maxProduct = maxNum * maxNum;
        long firstHalf = maxProduct / (long)pow(10, n);
        while (firstHalf > minNum) {
            long palindrome = createPalindrome(firstHalf--);
            for (int i = maxNum;
                 palindrome / i <= maxNum && (long)i * (long)i >= palindrome;
                 i--) {
                if (palindrome % i == 0) {
                    return palindrome % 1337;
                }
            }
        }
        return -1;
    }
    long createPalindrome(long firstHalf) {
        string str = to_string(firstHalf);
        str += str;
        reverse(str.begin() + str.length() / 2, str.end());
        return stol(str);
    }
};