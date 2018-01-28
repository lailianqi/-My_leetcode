#include <map>
#include <string>
using namespace std;
//第69周的周赛 没来得及参加 这是事后写的
//第69周的周赛
//一次性ac 这题比较简单
class Solution {
  public:
    int numJewelsInStones(string J, string S) {
        map<char, int> dir;
        int res = 0;
        for (int i = 0; i < J.size(); i++) {
            dir[J[i]]++;
        }
        for (int i = 0; i < S.size(); i++) {
            if (dir.count(S[i])) {
                res++;
            }
        }
        return res;
    }
};