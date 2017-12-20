#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
  public:
    int hIndex(vector<int> &citations) {
        int m = citations.size();
        int left = 0, right = m - 1;
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if (citations[mid] == m - mid) {
                return m - mid;
            } else if (citations[mid] < m - mid) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return m - left;
    }
};

class Solution_0 {
  public:
    int hIndex(vector<int> &citations) {
        int m = citations.size();
        int left = 0, right = m - 1;
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if (citations[mid] >= m - mid) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return m - left;
    }
};
//更加牛逼的方法
// https://discuss.leetcode.com/topic/23394/o-logn-time-o-1-space-easy-solution-with-detailed-explanations-c-java-python/3
class Solution_1 {
  public:
    int hIndex(vector<int> &citations) {
        int n = citations.size();
        for (int i = 0; i < n; i++)
            citations[i] -= (n - i);
        auto lb = lower_bound(citations.begin(), citations.end(), 0);
        return n - (lb - citations.begin());
    }
};