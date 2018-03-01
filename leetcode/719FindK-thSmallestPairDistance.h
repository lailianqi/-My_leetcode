#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
// 这题没写出来 直接看的答案
// 来自LeetCode的答案 题目本身和378有些类似
// https://leetcode.com/problems/find-k-th-smallest-pair-distance/discuss/109077/C++-counting-sort-O(n2)-and-binary-search-O(nlogn)
// 利用了堆排序
/*
2 <= len(nums) <= 10000.
0 <= nums[i] < 1000000.
1 <= k <= len(nums) * (len(nums) - 1) / 2.
*/
class Solution {
  public:
    int smallestDistancePair(vector<int> &nums, int k) {
        int m = nums.size(), N = 1000000;
        vector<int> buckets(N, 0);
        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < m; j++) {
                buckets[abs(nums[i] - nums[j])]++;
            }
        }
        for (int i = 0; i < N; i++) {
            if (buckets[i] >= k) {
                return i;
            }
            k -= buckets[i];
        }
        return 0;
    }
};
// 来自LeetCode的答案 二分查找的思路
// https://leetcode.com/problems/find-k-th-smallest-pair-distance/discuss/109077/C++-counting-sort-O(n2)-and-binary-search-O(nlogn)
// 上面的链接的答案比下面这个链接的答案牛逼
// https://leetcode.com/problems/find-k-th-smallest-pair-distance/discuss/109075/Java-solution-Binary-Search
class Solution_0 {
  public:
    int smallestDistancePair(vector<int> &nums, int k) {
        int m = nums.size();
        sort(nums.begin(), nums.end());
        int left = 0, right = 1000000;
        while (left < right) {
            int mid = (left + right) / 2;
            int counter = countSmallerNum(nums, mid);
            if (counter < k) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
    int countSmallerNum(vector<int> &nums, int target) {
        int m = nums.size(), res = 0;
        for (int i = 0, j = 0; i < m; i++) {
            while (j < m && nums[j] - nums[i] <= target) {
                j++;
            }
            res += j - i - 1;
        }
        return res;
    }
};

// sp大神的解法
// https://leetcode.com/problems/find-k-th-smallest-pair-distance/discuss/109092/%221-liner%22-and-%22almost-O(n)%22