#include <vector>
#include <map>
using namespace std;
//这题直接看的答案 没有想到解法
// https://discuss.leetcode.com/topic/68896/java-solution-using-hashmap-with-detailed-explanation/3
class Solution {
  public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (desiredTotal <= 0)
            return true;
        if (maxChoosableInteger * (maxChoosableInteger + 1) / 2 < desiredTotal)
            return false;
        map<int, bool> dir;
        return helper(desiredTotal, maxChoosableInteger, 0, dir);
    }
    bool helper(int desiredTotal, int counter, int state, map<int, bool> &dir) {
        if (dir.find(state) != dir.end()) {
            return dir[state];
        }
        for (int i = 0; i < counter; i++) {
            if ((state & (1 << i)) == 0) {
                if (desiredTotal <= i + 1 ||
                    !helper(desiredTotal - (i + 1), counter, state | (1 << i),
                            dir)) {
                    dir[state] = true;
                    return true;
                }
            }
        }
        dir[state] = false;
        return false;
    }
};