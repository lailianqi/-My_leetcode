#include <vector>
#include <unordered_map>
#include <priority_queue>
using namespace std;

//一道非常好但是并不难的题，但是第一次做的时候居然没有思路
//下面是leetcode的答案
// https://discuss.leetcode.com/topic/44226/c-o-n-log-n-k-unordered_map-and-priority_queue-maxheap-solution?page=1
// https://discuss.leetcode.com/topic/48158/3-java-solution-using-array-maxheap-treemap
class Solution {
  public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        vector<int> res;
        unordered_map<int, int> directory;
        for (int num : nums) {
            directory[num]++;
        }
        priority_queue<pair<int, int>> pq;
        for (auto it = directory.begin(); it != directory.end(); it++) {
            pq.push(make_pair(it->second, it->first));
            if (pq.size() > (int)directory.size() - k) {
                res.push_back(pq.top().second);
                pq.pop();
            }
        }
        return res;
    }
};

//另外的一种解法  Bucket Sort
// https://discuss.leetcode.com/topic/44313/3-ways-to-solve-this-problem/2
class Solution_0 {
  public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        vector<int> res;
        if (!nums.size())
            return res;
        unordered_map<int, int> cnt;
        for (auto num : nums)
            cnt[num]++;
        vector<vector<int>> bucket(nums.size() + 1);
        for (auto kv : cnt) {
            bucket[kv.second].push_back(kv.first);
        }
        for (int i = bucket.size() - 1; i >= 0; i--) {
            for (int j = 0; j < bucket[i].size(); ++j) {
                res.push_back(bucket[i][j]);
                if (res.size() == k)
                    return res;
            }
        }
        return res;
    }
};