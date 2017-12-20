#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    vector<vector<int>> answers;
    vector<int> answer;
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        subtrack(nums, 0);
        return answers;
    }
    void subtrack(vector<int> &nums, int deep) {
        if (deep <= nums.size()) {
            answers.push_back(answer);
        }
        for (int i = deep; i < nums.size(); i++) {
            if (i == deep || nums[i] != nums[i - 1]) {
                answer.push_back(nums[i]);
                subtrack(nums, i + 1);
                answer.pop_back();
            }
        }
    }
};

class Solution_0 {
  public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> answers(1, vector<int>());
        int start, size = 0;
        for (int i = 0; i < nums.size(); i++) {
            start = i > 0 && nums[i] == nums[i - 1] ? size : 0;
            size = answers.size();
            for (int j = start; j < size; j++) {
                answers.push_back(answers[j]);
                answers.back().push_back(nums[i]);
            }
        }
        return answers;
    }
};