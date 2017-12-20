#include <string>
#include <vector>
using namespace std;
//没有想出来,直接看的答案,其实主要觉得这道题做起来麻烦
class Solution {
  public:
    vector<string> LESS_THAN_20 = {
        "",        "One",     "Two",       "Three",    "Four",
        "Five",    "Six",     "Seven",     "Eight",    "Nine",
        "Ten",     "Eleven",  "Twelve",    "Thirteen", "Fourteen",
        "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> TENS = {"",      "Ten",   "Twenty",  "Thirty", "Forty",
                           "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> THOUSANDS = {"", "Thousand", "Million", "Billion"};
    string numberToWords(int num) {
        if (num == 0)
            return "Zero";
        int i = 0;
        string words = "";
        while (num > 0) {
            if (num % 1000 != 0)
                words = helper(num % 1000) + THOUSANDS[i] + " " + words;
            num /= 1000;
            i++;
        }
        words.erase(0, words.find_first_not_of(" "));
        words.erase(words.find_last_not_of(" ") + 1);
        return words;
    }
    string helper(int num) {
        if (num == 0)
            return "";
        else if (num < 20) {
            return LESS_THAN_20[num] + " ";
        } else if (num < 100) {
            return TENS[num / 10] + " " + helper(num % 10);
        } else
            return LESS_THAN_20[num / 100] + " Hundred " + helper(num % 100);
    }
};

// 下面是leetcode的另外一种写法的答案，可能写的更加的清晰
// https://discuss.leetcode.com/topic/30488/short-clean-java-solution/3