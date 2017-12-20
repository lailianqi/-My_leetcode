#include <vector>
#include <set>
#include <map>
using namespace std;
//自己的第一种写法 感觉写的一般
// leetcode的某种解法和这种解法是一样的
// https://discuss.leetcode.com/topic/45685/three-java-solutions
class Solution {
  public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        vector<int> result;
        set<int> directory, record;
        for (int i = 0; i < nums1.size(); i++) {
            directory.insert(nums1[i]);
        }
        for (int j = 0; j < nums2.size(); j++) {
            if (directory.find(nums2[j]) != directory.end() &&
                record.find(nums2[j]) == record.end()) {
                record.insert(nums2[j]);
                result.push_back(nums2[j]);
            }
        }
        return result;
    }
};
// two pointers的解法
// https://discuss.leetcode.com/topic/45685/three-java-solutions

// sp大神的解法
// https://discuss.leetcode.com/topic/45846/small-c-solution
class Solution_0 {
  public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        set<int> s(nums1.begin(), nums1.end());
        vector<int> out;
        for (int x : nums2)
            if (s.erase(x))
                out.push_back(x);
        return out;
    }
};