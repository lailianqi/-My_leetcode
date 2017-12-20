#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    vector<vector<int>> answers;
    vector<int> answer;
    vector<vector<int>> subsets(vector<int> &nums) {
        subtrack(nums, 0);
        return answers;
    }
    void subtrack(vector<int> &nums, int deep) {
        if (deep <= nums.size()) {
            answers.push_back(answer);
        }
        for (int i = deep; i < nums.size(); i++) {
            answer.push_back(nums[i]);
            subtrack(nums, i + 1);
            answer.pop_back();
        }
    }
};

// bit操作 https://leetcode.com/problems/subsets/#/discuss
/*
Bit Manipulation

This is the most clever solution that I have seen. The idea is that to give all
the possible subsets, we just need to exhaust all the possible combinations of
the numbers. And each number has only two possibilities: either in or not in a
subset. And this can be represented using a bit.

There is also another a way to visualize this idea. That is, if we use the above
example, 1 appears once in every two consecutive subsets, 2 appears twice in
every four consecutive subsets, and 3 appears four times in every eight subsets,
shown in the following (initially the 8 subsets are all empty):

[], [], [], [], [], [], [], []

[], [1], [], [1], [], [1], [], [1]

[], [1], [2], [1, 2], [], [1], [2], [1, 2]

[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3]
*/
class Solution_0 {
  public:
    vector<vector<int>> subsets(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int num_subset = pow(2, nums.size());
        vector<vector<int>> res(num_subset, vector<int>());
        for (int i = 0; i < nums.size(); i++)
            for (int j = 0; j < num_subset; j++)
                if ((j >> i) & 1)
                    res[j].push_back(nums[i]);
        return res;
    }
};
/*
Iterative
This problem can also be solved iteratively. Take [1, 2, 3] in the problem
statement as an example. The process of generating all the subsets is like:

Initially: [[]]
Adding the first number to all the existed subsets: [[], [1]];
Adding the second number to all the existed subsets: [[], [1], [2], [1, 2]];
Adding the third number to all the existed subsets: [[], [1], [2], [1, 2], [3],
[1, 3], [2, 3], [1, 2, 3]].
Have you got the idea :-)

The code is as follows.
*/

class Solution_1 {
  public:
    vector<vector<int>> subsets(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> answers(1, vector<int>());
        for (int i = 0; i < nums.size(); i++) {
            int size = answers.size();
            for (int j = 0; j < size; j++) {
                answers.push_back(answers[j]);
                answers.back().push_back(nums[i]);
            }
        }
        return answers;
    }
};

void test() {
    Solution s;
    vector<int> nums = {1, 2, 3};
    s.subsets(nums);
}