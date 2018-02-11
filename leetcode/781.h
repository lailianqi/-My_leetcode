#include <algorithm>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;
// 自己的第一种答案
// 71周比赛中完美ac
class Solution {
  public:
    int numRabbits(vector<int> &answers) {
        int res = 0;
        unordered_map<int, int> dir;
        for (int i = 0; i < answers.size(); i++) {
            dir[answers[i]]++;
        }
        for (auto element : dir) {
            res = res + ((element.second - 1) / (element.first + 1) + 1) *
                            (element.first + 1);
        }
        return res;
    }
};