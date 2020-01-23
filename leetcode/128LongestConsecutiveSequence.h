#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// https://discuss.leetcode.com/topic/6148/my-really-simple-java-o-n-solution-accepted?page=1
// leetcode的第一种解法
class Solution {
  public:
    int longestConsecutive(vector<int> &nums) {
        unordered_map<int, int> directory;
        int res = 0;
        for (auto i : nums) {
            if (directory.find(i) == directory.end()) {
                int left = (directory.find(i - 1) != directory.end())
                               ? directory[i - 1]
                               : 0;
                int right = (directory.find(i + 1) != directory.end())
                                ? directory[i + 1]
                                : 0;
                int length = left + right + 1;
                directory[i] = length;
                res = max(res, length);
                directory[i - left] = length;
                directory[i + right] = length;
            }
        }
        return res;
    }
};
// Java的解法
// leetcode的第二种解法
/*
class Solution_0 {
  public:
    int longestConsecutive(vector<int> &nums) {
        if (nums == null || nums.length == 0)
            return 0;
        Set<Integer> set = new HashSet<Integer>();
        for (int num : nums)
            set.add(num);
        int max = 1;
        for (int num : nums) {
            if (set.remove(num)) { // num hasn't been visited
                int val = num;
                int sum = 1;
                while (set.remove(val - 1))
                    val--;
                sum += num - val;
                val = num;
                while (set.remove(val + 1))
                    val++;
                sum += val - num;
                max = Math.max(max, sum);
            }
        }
        return max;
    }
};
*/

//第三种解法

class Solution_1 {
  public:
    int longestConsecutive(vector<int> &num) {
        unordered_set<int> record(num.begin(), num.end());
        int res = 1;
        for (int n : num) {
            if (record.find(n) == record.end())
                continue;
            record.erase(n);
            int prev = n - 1, next = n + 1;
            while (record.find(prev) != record.end())
                record.erase(prev--);
            while (record.find(next) != record.end())
                record.erase(next++);
            res = max(res, next - prev - 1);
        }
        return res;
    }
};

class Solution_2 {
  public:
    int longestConsecutive(vector<int> &nums) {
        unordered_map<int, bool> mp;
        int ret = 0;
        for (const auto x : nums)
            mp[x] = true;
        for (const auto x : mp)
            if (x.second) {
                int left = x.first, right = x.first + 1;
                while (mp.count(left) && mp[left])
                    mp[left--] = false;
                while (mp.count(right) && mp[right])
                    mp[right++] = false;
                ret = max(ret, right - left - 1);
            }
        return ret;
    }
};

// ------------------------------二刷
class Solution {
  public:
    int longestConsecutive(vector<int> &nums) {
        unordered_map<int, int> dir;
        int m = nums.size(), res = 0;
        for (int i = 0; i < m; i++) {
            if (!dir.count(nums[i])) {
                int left = dir.count(nums[i] - 1) ? dir[nums[i] - 1] : 0;
                int right = dir.count(nums[i] + 1) ? dir[nums[i] + 1] : 0;
                int length = left + right + 1;
                dir[nums[i]] = length;
                dir[nums[i] - left] = length;
                dir[nums[i] + right] = length;
                res = max(res, length);
            }
        }
        return res;
    }
};