#include <vector>
#include <algorithm>
using namespace std;
//没有写出来 没有想到点子上
// leetcode的答案
// https://discuss.leetcode.com/topic/49652/classic-dp-solution-similar-to-lis-o-n-2
// 这3个链接的方法其实是一样的，但是第一个链接写的好
// https://discuss.leetcode.com/topic/49456/c-solution-with-explanations
// https://discuss.leetcode.com/topic/49741/easy-understood-java-dp-solution-in-28ms-with-o-n-2-time
class Solution {
  public:
    vector<int> largestDivisibleSubset(vector<int> &nums) {
        int m = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> count(m, 0), pre(m, 0), res;
        int maxValue = 0, index = -1;
        for (int i = 0; i < m; i++) {
            count[i] = 1, pre[i] = -1;
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] % nums[j] == 0) {
                    if (1 + count[j] > count[i]) {
                        count[i] = count[j] + 1;
                        pre[i] = j;
                    }
                }
            }
            if (count[i] > maxValue) {
                maxValue = count[i];
                index = i;
            }
        }
        while (index != -1) {
            res.push_back(nums[index]);
            index = pre[index];
        }
        return res;
    }
};

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }