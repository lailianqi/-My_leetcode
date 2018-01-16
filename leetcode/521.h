#include <string>
#include <vector>
using namespace std;
//这问题太鸡贼了 我勒个大草
class Solution {
  public:
    int findLUSlength(string a, string b) {
        return a == b ? -1 : max(a.size(), b.size());
    }
};