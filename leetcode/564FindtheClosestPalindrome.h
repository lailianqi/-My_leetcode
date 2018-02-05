#include <algorithm>
#include <string>
#include <vector>
using namespace std;

// 直接看的LeetCode的答案 一开始并没有写出来 这道题的oj通过率极低
// https://discuss.leetcode.com/topic/87220/python-simple-with-explanation/10
class Solution {
  public:
    string nearestPalindromic(string n) {
        int m = n.size();
        if (m == 1) {
            return string(1, --n[0]);
        }
        int half_sn = (m + 1) / 2;
        long half_val = stol(n.substr(0, half_sn));
        vector<long> candidates = {pow(10, m) - 1, pow(10, m - 1) - 1,
                                   pow(10, m - 1) + 1, pow(10, m) + 1};
        findOtherCandidates(candidates, m, half_val);
        sort(candidates.begin(), candidates.end());
        string ans;
        long val = stol(n), min_diff = INT_MAX;
        for (long candidate : candidates) {
            if (candidate != val) {
                long diff = labs(val - candidate);
                if (diff < min_diff) {
                    min_diff = diff;
                    ans = to_string(candidate);
                }
            }
        }
        return ans;
    }

  private:
    void findOtherCandidates(vector<long> &candidates, int m, long val) {
        vector<long> fmdc = {val, val - 1, val + 1};
        for (int i = 0; i < fmdc.size(); i++) {
            string receive = to_string(fmdc[i]);
            if (m % 2) {
                receive.pop_back();
            }
            reverse(receive.begin(), receive.end());
            candidates.push_back(stol(to_string(fmdc[i]) + receive));
        }
    }
};

// 来自LeetCode的另外一种答案 另外一个大神写的 但是题解太长了 英文看的太吃力
// 留着以后看
// ttps://discuss.leetcode.com/topic/88897/java-solution-with-detailed-proof
