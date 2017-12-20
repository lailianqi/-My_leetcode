#include <string>
using namespace std;

//参照了题解
class Solution {
  public:
    string multiply(string num1, string num2) {
        int m = num1.size(), n = num2.size();
        int *pos = new int[m + n]();
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                pos[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
                pos[i + j] += pos[i + j + 1] / 10;
                pos[i + j + 1] = pos[i + j + 1] % 10;
            }
        }
        string s = "";
        for (int i = 0; i <= m + n - 1; i++) {
            if (!(s.length() == 0 && pos[i] == 0))
                s = s + to_string(pos[i]);
        }
        return s.length() == 0 ? "0" : s;
    }
};