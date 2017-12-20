#include <vector>
#include <stack>
#include <iostream>
using namespace std;
//第一次并木有写出来
//下面是leetcode的答案
// https://discuss.leetcode.com/topic/32272/share-my-greedy-solution?page=1
class Solution {
  public:
    vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        vector<int> result;
        for (int i = max(0, k - n); i <= k && i <= m; i++) {
            vector<int> candidate =
                merge(maxArray(nums1, i), maxArray(nums2, k - i), k);
            if (greater(candidate, 0, result, 0))
                result = candidate;
        }
        return result;
    }
    vector<int> merge(vector<int> nums1, vector<int> nums2, int k) {
        vector<int> result(k, 0);
        for (int t = 0, i = 0, j = 0; t < k; t++) {
            result[t] = greater(nums1, i, nums2, j) ? nums1[i++] : nums2[j++];
        }
        return result;
    }
    bool greater(vector<int> nums1, int i, vector<int> nums2, int j) {
        while (i < nums1.size() && j < nums2.size() && nums1[i] == nums2[j]) {
            i++;
            j++;
        }
        return j == nums2.size() || (i < nums1.size() && nums1[i] > nums2[j]);
    }
    vector<int> maxArray(vector<int> nums, int k) {
        int n = nums.size();
        vector<int> ans(k, 0);
        for (int i = 0, j = 0; i < n; ++i) {
            while (n - i + j > k && j > 0 && ans[j - 1] < nums[i])
                j--;
            if (j < k)
                ans[j++] = nums[i];
        }
        return ans;
    }
};
//这个算法的关键是stack.size()的动态变化
vector<int> maxArray(vector<int> nums, int k) {
    int n = nums.size();
    stack<int> stack;
    for (int i = 0; i < n; i++) {
        while (stack.size() + n - i > k && !stack.empty() &&
               stack.top() < nums[i]) {
            cout << stack.top();
            stack.pop();
        }
        cout << endl;
        if (stack.size() < k) {
            stack.push(nums[i]);
        }
    }
    vector<int> result(k, 0);
    for (int i = k - 1; i >= 0; i--) {
        result[i] = stack.top();
        stack.pop();
    }
    return result;
}
void test() {
    vector<int> nums = {1, 6, 3, 7, 15, 14, 3};
    for (auto element : maxArray(nums, 5)) {
        cout << element << " ";
    }
}
