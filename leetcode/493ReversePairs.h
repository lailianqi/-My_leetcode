#include <vector>
#include <algorithm>
using namespace std;

/* 题目描述
 * Given an array nums, we call (i, j) an important reverse pair if i < j and
 * nums[i] > 2*nums[j]. You need to return the number of important reverse pairs
 * in the given array.
 * */
/*类似的题目
315. Count of Smaller Numbers After Self
327. Count of Range Sum
**/
//最普通的解法 肯定会超时的 所以这题没有写出来
class Solution {
  public:
    int reversePairs(vector<int> &nums) {
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if ((long)nums[i] > 2 * (long)nums[j]) {
                    res++;
                }
            }
        }
        return res;
    }
};
// sp大神的写法
// https://discuss.leetcode.com/topic/78993/c-with-iterators
class Solution_0 {
  public:
    int reversePairs(vector<int> &nums) {
        return sort_and_count(nums.begin(), nums.end());
    }
    int sort_and_count(vector<int>::iterator begin, vector<int>::iterator end) {
        if (end - begin <= 1) {
            return 0;
        }
        auto mid = begin + (end - begin) / 2;
        int res = sort_and_count(begin, mid) + sort_and_count(mid, end);
        for (auto i = begin, j = mid; i != mid; i++) {
            while (j != end && *i > 2L * *j)
                ++j;
            res += j - mid;
        }
        inplace_merge(begin, mid, end);
        return res;
    }
};

//这道题最全面的写法 来自leetcode的答案
// https://discuss.leetcode.com/topic/79227/general-principles-behind-problems-similar-to-reverse-pairs
// https://discuss.leetcode.com/topic/78933/very-short-and-clear-mergesort-bst-java-solutions