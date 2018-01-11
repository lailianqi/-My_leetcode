#include <string>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <set>
using namespace std;
// 这道题挺简单的  自己的第一个正确答案在第二个解法上
// 这里只是记录一下第一种错误的解法
// 刚开始题意理解错了 所以有下面这种解法 这种解法过不去ac的
class Solution {
  public:
    vector<string> findRelativeRanks(vector<int> &nums) {
        vector<string> res;
        int counter = 0;
        vector<string> dictionary = {"Bronze Medal", "Silver Medal",
                                     "Gold Medal"};
        auto comp = [&nums](int a, int b) { return nums[a] > nums[b]; };
        priority_queue<int, vector<int>, decltype(comp)> queue(comp);
        for (int i = 0; i < nums.size(); i++) {
            queue.push(i);
            if (queue.size() > 3) {
                queue.pop();
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            res.push_back(to_string(nums[i]));
        }
        while (!queue.empty()) {
            res[queue.top()] = dictionary[counter++];
            queue.pop();
        }
        return res;
    }
};

//自己的第二种解法 成功ac
//因为每个运动员的分数为独立的 所以直接用的map记录的分数
// leetcode 的最佳的答案和我的第二种的解法思路一样
// https://discuss.leetcode.com/topic/77876/easy-java-solution-sorting
class Solution_0 {
  public:
    vector<string> findRelativeRanks(vector<int> &nums) {
        vector<string> res;
        unordered_map<int, int> score;
        vector<int> temp = nums;
        sort(temp.begin(), temp.end(), [](int a, int b) { return a > b; });
        for (int i = 0; i < temp.size(); i++) {
            score[temp[i]] = i + 1;
        }
        for (int i = 0; i < nums.size(); i++) {
            res.push_back(score[nums[i]] == 1
                              ? "Gold Medal"
                              : score[nums[i]] == 2
                                    ? "Silver Medal"
                                    : score[nums[i]] == 3
                                          ? "Bronze Medal"
                                          : to_string(score[nums[i]]));
        }

        return res;
    }
};
//上面写法的改进版 代码更加的好看 来自leetcode答案的灵感
// https://discuss.leetcode.com/topic/77869/simple-sorting-o-n-log-n-solution
class Solution_1 {
  public:
    vector<string> findRelativeRanks(vector<int> &nums) {
        vector<int> rank(nums.size(), 0);
        vector<string> res(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            rank[i] = i;
        }
        sort(rank.begin(), rank.end(),
             [&](int a, int b) { return nums[a] > nums[b]; });
        for (int i = 0; i < nums.size(); ++i) {
            res[rank[i]] =
                i == 0 ? "Gold Medal" : i == 1 ? "Silver Medal"
                                               : i == 2 ? "Bronze Medal"
                                                        : to_string(i + 1);
        }
        return res;
    }
};
// sp大神的python解法
// https://discuss.leetcode.com/topic/77943/python-solution