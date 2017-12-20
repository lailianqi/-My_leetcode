#include <iostream>
#include <string>
#include <map>
#include <climits>
using namespace std;
class Solution {
    public:
      int myAtoi(string str) {
            int i = 0;
            int sign = 1;
            long long num = 0;
            map<char, int> charToIntMap = charIntTable();
            while (str[i] == ' ') {
                  i++;
            }
            if (str[i] == '+' || str[i] == '-') {
                  if (str[i] == '-')
                        sign = -1;
                  i++;
            }
            while (str[i] >= '0' && str[i] <= '9') {
                  num = num * 10 + charToIntMap[str[i]];
                  if (num > INT_MAX) {
                        if (sign == 1)
                              return INT_MAX;
                        else
                              return INT_MIN;
                  }
                  i++;
            }
            return num * sign;
      }
      map<char, int> charIntTable() {
            map<char, int> charToIntMap;
            charToIntMap.insert(pair<char, int>('0', 0));
            charToIntMap.insert(pair<char, int>('1', 1));
            charToIntMap.insert(pair<char, int>('2', 2));
            charToIntMap.insert(pair<char, int>('3', 3));
            charToIntMap.insert(pair<char, int>('4', 4));
            charToIntMap.insert(pair<char, int>('5', 5));
            charToIntMap.insert(pair<char, int>('6', 6));
            charToIntMap.insert(pair<char, int>('7', 7));
            charToIntMap.insert(pair<char, int>('8', 8));
            charToIntMap.insert(pair<char, int>('9', 9));
            return charToIntMap;
      }
};
void test() {
      Solution s;
      cout << s.myAtoi("12a11") << endl;
}