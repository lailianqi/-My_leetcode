#include <strirng>
using namespace std;
//这道题一开始就没有看懂 简直没法做
// leetcode的答案
// https://discuss.leetcode.com/topic/63386/one-pass-o-n-java-solution-simple-and-clear
// https://discuss.leetcode.com/topic/63386/one-pass-o-n-java-solution-simple-and-clear/4
//还是这个解法的下面sp大神的解释和解法更好
class Solution {
  public:
    string originalDigits(string s) {
        vector<int> count(10, 0);
        string res;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == 'z')
                count[0]++;
            if (c == 'w')
                count[2]++;
            if (c == 'x')
                count[6]++;
            if (c == 's')
                count[7]++; // 7-6
            if (c == 'g')
                count[8]++;
            if (c == 'u')
                count[4]++;
            if (c == 'f')
                count[5]++; // 5-4
            if (c == 'h')
                count[3]++; // 3-8
            if (c == 'i')
                count[9]++; // 9-8-5-6
            if (c == 'o')
                count[1]++; // 1-0-2-4
        }
        count[7] -= count[6];
        count[5] -= count[4];
        count[3] -= count[8];
        count[9] = count[9] - count[8] - count[5] - count[6];
        count[1] = count[1] - count[0] - count[2] - count[4];
        for (int i = 0; i <= 9; i++) {
            for (int j = 0; j < count[i]; j++) {
                res.push_back(i + '0');
            }
        }
        return res;
    }
};

// sp大神的解法
/*
The even digits all have a unique letter while the odd digits all don't:
zero: Only digit with z
two: Only digit with w
four: Only digit with u
six: Only digit with x
eight: Only digit with g
The odd ones for easy looking, each one's letters all also appear in other digit
words:
one, three, five, seven, nine

*/
// https://discuss.leetcode.com/topic/63432/fun-fact
// https://discuss.leetcode.com/topic/63382/share-my-simple-and-easy-o-n-solution
// https://discuss.leetcode.com/topic/64150/straightforward-c-accepted-solution
//目前看的最爽的解法
class Solution {
  public:
    string originalDigits(string s) {
        vector<string> words = {"zero", "two",   "four", "six",   "eight",
                                "one",  "three", "five", "seven", "nine"};
        vector<int> nums = {0, 2, 4, 6, 8, 1, 3, 5, 7, 9};
        vector<int> distinct_char = {'z', 'w', 'u', 'x', 'g',
                                     'o', 'r', 'f', 'v', 'i'};
        vector<int> counts(26, 0);
        string result;
        for (int i = 0; i < s.size(); i++) {
            counts[s[i] - 'a']++;
        }
        for (int i = 0; i < 10; i++) {
            int num = counts[distinct_char[i] - 'a'];
            for (int j = 0; j < words[i].size(); j++) {
                counts[words[i][j] - 'a'] -= num;
            }
            while (num--) {
                result += to_string(nums[i]);
            }
        }
        sort(result.begin(), result.end());
        return result;
    }
};