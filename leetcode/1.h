#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
  public:
    vector<int> twoSum(vector<int> &nums, int target) {
        vector<int> answer;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    answer.push_back(i);
                    answer.push_back(j);
                    return answer;
                }
            }
        }
        return answer;
    }
};

class Solution_0 {
  public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> hash;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            int numberToFind = target - nums[i];
            // if numberToFind is found in map, return them
            if (hash.find(numberToFind) != hash.end()) {
                //+1 because indices are NOT zero based
                result.push_back(hash[numberToFind] + 1);
                result.push_back(i + 1);
                return result;
            }
            // number was not found. Put it in the map.
            hash[nums[i]] = i;
        }
        return result;
    }
};

void test() {
    Solution s;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> temp = s.twoSum(nums, 9);
    cout << temp[0] << temp[1];
}
