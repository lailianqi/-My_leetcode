#include <iostream>
#include <string>
using namespace std;
//答案可行
class Solution {
  public:
    string a[101];
    string countAndSay(int n) {
        init(n);
        return a[n - 1];
    }
    void init(int n) {
        a[0] = "1";
        for (int i = 1; i < n; i++) {
            string s = "";
            int count = 0;
            for (int j = 0; j < a[i - 1].length(); j++) {
                if (j == 0 || a[i - 1][j] == a[i - 1][j - 1]) {
                    count++;
                } else {
                    s = s + to_string(count) + a[i - 1][j - 1];
                    count = 1;
                }
            }
            s = s + to_string(count) + a[i - 1][a[i - 1].length() - 1];
            a[i] = s;
        }
    }
};

class Solution_0 {
  public:
    string countAndSay(int n) {
        string res = "1";
        while (--n) {
            string cur = "";
            int counter = 1;
            for (int i = 0; i < res.size(); i++) {
                if (res[i] == res[i + 1] && i < res.size() - 1) {
                    counter++;
                } else {
                    cur = cur + to_string(counter) + res[i];
                    counter = 1;
                }
            }
            res = cur;
        }
        return res;
    }
};

void test() {
    Solution s;
    cout << s.countAndSay(4) << endl;
}