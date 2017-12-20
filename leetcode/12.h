#include <iostream>
#include <string>
#include <map>
using namespace std;

class Solution {
      public:
        string intToRoman(int num) {
                int a[] = {1000, 900, 500, 400, 100, 90, 50,
                           40,   10,  9,   5,   4,   1};
                string b[] = {"M",  "CM", "D",  "CD", "C",  "XC", "L",
                              "XL", "X",  "IX", "V",  "IV", "I"};
                string result = "";
                for (int i = 0; num != 0; i++) {
                        while (num >= a[i]) {
                                num -= a[i];
                                result += b[i];
                        }
                }
                return result;
        }
        map<int, string> stringToInt(int *a, string *b) {
                map<int, string> romaIntMap;
                for (int i = 0; i < 13; i++) {
                        romaIntMap[a[i]] = b[i];
                }
                return romaIntMap;
        }
};
void test() {
    Solution s;
    cout<<s.intToRoman(3401)<<endl;
}