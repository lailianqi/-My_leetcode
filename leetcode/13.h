#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;
class Solution {
      public:
        int romanToInt(string s) {
                int num = 0;
                string a[] = {"M",  "CM", "D",  "CD", "C",  "XC", "L",
                              "XL", "X",  "IX", "V",  "IV", "I"};
                int b[] = {1000, 900, 500, 400, 100, 90, 50,
                           40,   10,  9,   5,   4,   1};
                map<string, int> romaIntMap = stringToInt(a, b);
                int i;
                for (i = 0; i < s.length() - 1; i++) {
                        if (romaIntMap.find(s.substr(i, 2)) !=
                            romaIntMap.end()) {
                                num += romaIntMap[s.substr(i, 2)];
                                i++;
                        } else {
                                num += romaIntMap[s.substr(i, 1)];
                        }
                }
                if (i == s.length() - 1) {
                        num += romaIntMap[s.substr(i, 1)];
                }
                return num;
        }
        int romanToInt2(string s) {
                unordered_map<char, int> romans = {
                    {'I', 1},   {'V', 5},   {'X', 10},  {'L', 50},
                    {'C', 100}, {'D', 500}, {'M', 1000}};
                int sum = 0;
                int cur, nex;
                for (int i = 0; i < s.length() - 1; i++) {
                        cur = romans[s[i]];
                        nex = romans[s[i + 1]];
                        if (cur >= nex)
                                sum += cur;
                        else
                                sum -= cur;
                }
                return sum + romans[s[s.length() - 1]];
        }
        map<string, int> stringToInt(string *a, int *b) {
                map<string, int> romaIntMap;
                for (int i = 0; i < 13; i++) {
                        romaIntMap[a[i]] = b[i];
                }
                return romaIntMap;
        }
};

void test() {
        Solution s;
        cout << s.romanToInt("MMMCDI") << endl;
}