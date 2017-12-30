#include <algorithm>
#include <climits>
#include <vector>
using namespace std;
// 这道题难度是简单 其实还挺难的 当初没有写出来 看的LeetCode答案改写的
// https://discuss.leetcode.com/topic/71460/short-and-clean-java-binary-search-solution
class Solution {
  public:
    int findRadius(vector<int> &houses, vector<int> &heaters) {
        sort(heaters.begin(), heaters.end());
        int res = INT_MIN;
        for (int i = 0; i < houses.size(); i++) {
            auto it = lower_bound(heaters.begin(), heaters.end(), houses[i]);
            if (it != heaters.end()) {
                int index = it - heaters.begin();
                int dist1 =
                    index - 1 < 0 ? INT_MAX : houses[i] - heaters[index - 1];
                int dist2 = heaters[index] - houses[i];
                res = max(res, min(dist1, dist2));
            } else {
                res = max(res, houses[i] - heaters[heaters.size() - 1]);
            }
        }
        return res;
    }
};

// leetcode 上另外一个更好的答案
// https://discuss.leetcode.com/topic/71450/simple-java-solution-with-2-pointers
class Solution_0 {
  public:
    int findRadius(vector<int> &houses, vector<int> &heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int i = 0, j = 0, res = 0;
        while (i < houses.size()) {
            while (j < heaters.size() - 1 && abs(heaters[j + 1] - houses[i]) <=
                                                 abs(heaters[j] - houses[i])) {
                j++;
            }
            res = max(res, abs(heaters[j] - houses[i]));
            i++;
        }
        return res;
    }
};

//上面更好答案的改进版
// https://discuss.leetcode.com/topic/71450/simple-java-solution-with-2-pointers

class Solution_1 {
  public:
    int findRadius(vector<int> &houses, vector<int> &heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int i = 0, res = 0;
        for (int house : houses) {
            while (i < heaters.size() - 1 &&
                   heaters[i] + heaters[i + 1] <= house * 2) {
                i++;
            }
            res = max(res, abs(heaters[i] - house));
        }
        return res;
    }
};