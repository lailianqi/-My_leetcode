#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
//参考的答案
// https://discuss.leetcode.com/topic/5125/sharing-my-simple-c-code-o-n-time-o-1-space
// https://discuss.leetcode.com/topic/5125/sharing-my-simple-c-code-o-n-time-o-1-space/14
// https://discuss.leetcode.com/topic/3016/share-my-short-solution
class Solution {
  public:
    int trap(vector<int> &height) {
        int result = 0;
        int left = 0, right = height.size() - 1;
        int leftMax = 0, rightMax = 0;
        while (left <= right) {
            if (height[left] <= height[right]) {
                if (height[left] < leftMax) {
                    result += leftMax - height[left];
                } else {
                    leftMax = height[left];
                }
                left++;
            } else {
                if (height[right] < rightMax) {
                    result += rightMax - height[right];
                } else {
                    rightMax = height[right];
                }
                right--;
            }
        }
        return result;
    }
};
//上面的改进版
// https://discuss.leetcode.com/topic/5125/sharing-my-simple-c-code-o-n-time-o-1-space/14
/*
public class Solution {
    public int trap(int[] heights) {

        if ( heights.length <= 2 ) { return 0; }

        int left = 0, right = heights.length-1, totalArea = 0;
        int leftMaxHeight = heights[left], rightMaxHeight = heights[right];

        while ( left < right ) {
            if ( heights[left] < heights[right] ) {
                leftMaxHeight = Math.max(leftMaxHeight, heights[++left]);
                totalArea += leftMaxHeight-heights[left];
            } else {
                rightMaxHeight = Math.max(rightMaxHeight, heights[--right]);
                totalArea += rightMaxHeight-heights[right];
            }
        }
        return totalArea;
    }
}
*/
// 简短的答案
// sp大神的解法 稍微理解了一下
// https://discuss.leetcode.com/topic/18731/7-lines-c-c
class Solution_0 {
  public:
    int trap(vector<int> &height) {
        int l = 0, r = height.size() - 1, level = 0, water = 0;
        while (l < r) {
            int lower = height[height[l] < height[r] ? l++ : r--];
            level = max(level, lower);
            water += level - lower;
        }
        return water;
    }
};
// stack的解法 自己的改造的解法
// https://discuss.leetcode.com/topic/4939/a-stack-based-solution-for-reference-inspired-by-histogram
class Solution_00 {
  public:
    int trap(vector<int> &height) {
        stack<int> waterStack;
        int res = 0;
        for (int i = 0; i < height.size(); i++) {
            while (!waterStack.empty() &&
                   height[waterStack.top()] < height[i]) {
                int bot = waterStack.top();
                waterStack.pop();
                res += waterStack.empty()
                           ? 0
                           : ((min(height[i], height[waterStack.top()]) -
                               height[bot]) *
                              (i - waterStack.top() - 1));
            }
            waterStack.push(i);
        }
        return res;
    }
};
//最快的答案,根据图形来算
// https://discuss.leetcode.com/topic/18731/7-lines-c-c
class Solution_1 {
  public:
    int trap(vector<int> &height) {
        if (height.size() == 0)
            return 0;

        int leng = height.size();

        vector<int> Max(leng, 0);
        int Tmp_max = 0;
        int ori_sum = 0;
        for (int i = 0; i < leng; i++) {
            ori_sum += height[i];

            if (Tmp_max < height[i])
                Tmp_max = height[i];
            Max[i] = Tmp_max;
        }
        int after_sum = 0;
        Tmp_max = height[leng - 1];
        for (int i = leng - 1; i >= 0; i--) {
            if (Tmp_max < height[i])
                Tmp_max = height[i];

            Max[i] = min(Max[i], Tmp_max);
            after_sum += Max[i];
        }

        return after_sum - ori_sum;
    }
};

void test() {
    Solution_00 s;
    vector<int> height = {2, 0, 2};
    s.trap(height);
}