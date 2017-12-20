#include <vector>
#include <algorithm>
using namespace std;
class Solution {
  public:
    //答案正确，但出现超时
    bool canJump(vector<int> &nums) {
        int m = nums.size();
        vector<bool> dp(m, false);
        dp[0] = true;
        for (int i = 0; i < m; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (j + nums[j] >= i && dp[j]) {
                    dp[i] = true;
                }
            }
        }
        return dp[m - 1];
    }
};
// BFS改进版,自己写的 You are here! Your runtime beats 22.28 % of cpp
// submissions.
class Solution_0 {
  public:
    bool canJump(vector<int> &nums) {
        int curEnd = 0, curFarthest = 0;
        int m = nums.size();
        vector<bool> dp(m, false);
        dp[0] = true;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (dp[i]) {
                curFarthest = max(curFarthest, i + nums[i]);
                if (curFarthest >= nums.size() - 1) {
                    return true;
                }
                if (i == curEnd) {
                    for (int j = i + 1; j <= curFarthest; j++) {
                        dp[j] = true;
                    }
                    curEnd = curFarthest;
                }
            }
        }
        return dp[m - 1];
    }
};

class Solution_1 {
  public:
    bool canJump(vector<int> &nums) {
        int reach = 0, m = nums.size();
        int i = 0;
        for (; i < m && i <= reach; i++)
            reach = max(i + nums[i], reach);
        return i == m;
    }
};
//贪心算法 77%beat
class Solution_2 {
  public:
    bool canJump(vector<int> &nums) {
        int m = nums.size();
        int index = nums.size() - 1, i, j;
        for (i = m - 2; i >= 0; i--) {
            if (i + nums[i] >= index)
                index = i;
        }
        return index <= 0;
    }
};

/*
The easiest way to think about this problem is to ask are the elements with a 0
value avoidable? this is the algorithm that I constructed to answer this
question.Starting from the second to last element in the array we continue to
decrement towards the start of the array. Only stopping if we hit an element
with a value of 0; in this case we evaluate if there exist an element somewhere
at the start of the array which has a jump value large enough to jump over this
0 value element.
*/
//You are here! Your runtime beats 22.28 % of cpp submissions.
class Solution_3 {
  public:
    bool canJump(vector<int> &nums) {
        int m = nums.size();
        if (m < 2)
            return true;
        for (int curr = m - 2; curr >= 0; curr--) {
            if (nums[curr] == 0) {
                int neededJumps = 1;
                while (neededJumps > nums[curr]) {
                    neededJumps++;
                    curr--;
                    if (curr < 0)
                        return false;
                }
            }
        }
        return true;
    }
};