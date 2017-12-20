#include <vector>
#include <map>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
  public:
    vector<vector<int> > answers;
    vector<vector<int> > permuteUnique(vector<int> &nums) {
        Perm(nums, 0);
        return answers;
    }
    void Perm(vector<int> &nums, int k) {
        if (k == nums.size() - 1) {
            answers.push_back(nums);
            return;
        } else {
            map<int, int> st;
            for (int i = k; i < nums.size(); i++) {
                if (st.find(nums[i]) == st.end()) {
                    swap(nums[k], nums[i]);
                    Perm(nums, k + 1);
                    swap(nums[k], nums[i]);
                }
                st[nums[i]] = 1;
            }
        }
    }
};

class Solution_0 {
  public:
    void permuteUniqueHelper(int i, vector<int> &nums,vector<vector<int> > &result) {
        if (i == nums.size()) {
            result.push_back(nums);
            return;
        }
        unordered_set<int> st;
        for (int j = i; j < nums.size(); ++j) {
            if (st.count(nums[j]) == 1) {
                continue;
            }
            st.insert(nums[j]);
            std::swap(nums[i], nums[j]);
            permuteUniqueHelper(i + 1, nums, result);
            std::swap(nums[i], nums[j]);
        }
    }

    vector<vector<int> > permuteUnique(vector<int> &nums) {
        vector<vector<int> > result;
        permuteUniqueHelper(0, nums, result);
        return result;
    }
};
// https://discuss.leetcode.com/topic/15875/short-40ms-c-solution-similar-to-permutation-i-solution
