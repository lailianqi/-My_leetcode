#include <vector>
#include <stack>
#include <climits>
using namespace std;
//这道题暴力可解 但是暴力肯定过不去oj 所以其他的解法没有想出来
//直接看了leetcode的答案
// leetcode 的解法
// https://discuss.leetcode.com/topic/67881/single-pass-c-o-n-space-and-time-solution-8-lines-with-detailed-explanation?page=1
class Solution {
  public:
    bool find132pattern(vector<int> &nums) {
        int s3 = INT_MIN;
        stack<int> st;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] < s3)
                return true;
            else
                while (!st.empty() && nums[i] > st.top()) {
                    s3 = st.top();
                    st.pop();
                }
            st.push(nums[i]);
        }
        return false;
    }
};