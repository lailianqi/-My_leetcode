#include <iostream>
#include <string>
using namespace std;

class Solution {
  public:
    int strStr(string haystack, string needle) {
        //防止无符号数溢出
        int m = haystack.size(), n = needle.size();
        if (n == 0)
            return 0;
        for (int i = 0; i < m - n + 1; i++) {
            if (haystack[i] == needle[0]) {
                int j;
                for (j = 1; j < n; j++) {
                    if (haystack[i + j] != needle[j])
                        break;
                }
                if (j == n)
                    return i;
            }
        }
        return -1;
    }
};

void test() {
    Solution s;
    cout << s.strStr("abb", "abaaa") << endl;
}