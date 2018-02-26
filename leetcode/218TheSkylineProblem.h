#include <vector>
#include <algorithm>
#include <set>
using namespace std;
//根本不会
// http://blog.csdn.net/jeanphorn/article/details/46638289
// https://discuss.leetcode.com/topic/39416/guaranteed-really-detailed-and-good-perfect-explanation-of-the-skyline-problem?page=1
class Solution {
  public:
    vector<pair<int, int>> getSkyline(vector<vector<int>> &buildings) {
        vector<pair<int, int>> height, res;
        multiset<int> heap;
        for (auto element : buildings) {
            height.push_back(pair<int, int>(element[0], -element[2]));
            height.push_back(pair<int, int>(element[1], element[2]));
        }
        sort(height.begin(), height.end(),
             [](pair<int, int> a, pair<int, int> b) {
                 if (a.first != b.first)
                     return a.first < b.first; //先按左边界进行排序
                 return b.second > a.second;
             });
        // sort(height.begin(), height.end());
        heap.insert(0);
        int pre = 0, cur = 0;
        for (int i = 0; i < height.size(); i++) {
            if (height[i].second < 0) {
                heap.insert(-height[i].second);
            } else {
                heap.erase(heap.find(height[i].second));
            }
            cur = *heap.rbegin();
            if (cur != pre) {
                res.push_back(pair<int, int>(height[i].first, cur));
                pre = cur;
            }
        }
        return res;
    }
};