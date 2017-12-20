#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > answers;
    vector<vector<int> > permute(vector<int> &nums) {
        Perm(nums, 0);
        return answers;
    }
    void Perm(vector<int> &nums, int k) {
        if (k == nums.size() - 1) {
            answers.push_back(nums);
        } else {
            for (int i = k; i < nums.size(); i++) {
                swap(nums[k], nums[i]);
                Perm(nums, k + 1);
                swap(nums[k], nums[i]);
            }
        }
    }
};

class Solution_0 {
    // https://discuss.leetcode.com/topic/6377/my-ac-simple-iterative-java-python-solution
};