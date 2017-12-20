#include <stack>
#include <string>
#include <vector>
using namespace std;
class Solution {
  public:
    vector<string> v;
    vector<string> generateParenthesis(int n) {
        string s = "";
        recur(s, 0, 0, n);
        return v;
    }
    void recur(string s, int left, int right, int n) {
        string temp = s;
        if (s.length() == 2 * n) {
            v.push_back(s);
            return;
        }
        if (left < n) {
            recur(s + "(", left + 1, right, n);
        }
        if (right < left) {
            recur(s + ")", left, right + 1, n);
        }
    }
};