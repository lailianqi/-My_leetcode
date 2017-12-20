#include <iostream>
#include <map>
#include <string>
#include <stack>
using namespace std;
class Solution {
  public:
    bool isValid(string s) {
        stack<char> sta;
        map<char, char> bracketsMap;
        bracketsMap[')'] = '(';
        bracketsMap['}'] = '{';
        bracketsMap[']'] = '[';
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
                if (!sta.empty() && sta.top() == bracketsMap[s[i]]) {
                    sta.pop();
                } else {
                    return false;
                }
            } else {
                sta.push(s[i]);
            }
        }
        return sta.empty();
    }
};

void test() {
    Solution s;
    if (s.isValid("]"))
        cout << "yes" << endl;
    else
        cout << "no" << endl;
}