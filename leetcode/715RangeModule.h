#include <algorithm>
#include <map>
#include <string>
#include <vector>
using namespace std;

// 这种类型的题目是真的不是非常的擅长 所以没写出来 所以直接看得答案
// https://leetcode.com/problems/range-module/discuss/108912/C++-vector-O(n)-and-map-O(logn)-compare-two-solutions
class RangeModule {
  public:
    RangeModule() {}

    void addRange(int left, int right) {
        int n = invals.size();
        vector<pair<int, int>> tmp;
        for (int i = 0; i <= n; i++) {
            if (i == n || invals[i].first > right) {
                tmp.push_back({left, right});
                while (i < n)
                    tmp.push_back(invals[i++]);
            } else if (invals[i].second < left) {
                tmp.push_back(invals[i]);
            } else {
                left = min(left, invals[i].first);
                right = max(right, invals[i].second);
            }
        }
        swap(invals, tmp);
    }

    bool queryRange(int left, int right) {
        int m = invals.size(), l = 0, r = m - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (invals[mid].second <= left) {
                l = mid + 1;
            } else if (invals[mid].first >= right) {
                r = mid - 1;
            } else {
                return invals[mid].first <= left && invals[mid].second >= right;
            }
        }
        return false;
    }

    void removeRange(int left, int right) {
        int m = invals.size();
        vector<pair<int, int>> tmp;
        for (int i = 0; i < m; i++) {
            if (invals[i].second <= left || invals[i].first >= right) {
                tmp.push_back(invals[i]);
            } else {
                if (invals[i].first < left) {
                    tmp.push_back({invals[i].first, left});
                }
                if (invals[i].second > right) {
                    tmp.push_back({right, invals[i].second});
                }
            }
        }
        swap(invals, tmp);
    }

  private:
    vector<pair<int, int>> invals;
};

// 第二中方法 来自LeetCode 用的map
// https://leetcode.com/problems/range-module/discuss/108912/C++-vector-O(n)-and-map-O(logn)-compare-two-solutions
class RangeModule_0 {
  public:
    RangeModule_0() {}

    void addRange(int left, int right) {
        auto l = intervals.upper_bound(left), r = intervals.upper_bound(right);
        if (l != intervals.begin()) {
            l--;
            if (l->second < left)
                l++;
        }
        if (l != r) {
            left = min(left, l->first);
            right = max(right, (--r)->second);
            intervals.erase(l, ++r);
        }
        intervals[left] = right;
    }

    bool queryRange(int left, int right) {
        auto it = intervals.upper_bound(left);
        if (it == intervals.begin() || (--it)->second < right) {
            return false;
        }
        return true;
    }

    void removeRange(int left, int right) {
        auto l = intervals.upper_bound(left), r = intervals.upper_bound(right);
        if (l != intervals.begin()) {
            l--;
            if (l->second < left)
                l++;
        }
        if (l == r)
            return;
        int l1 = min(l->first, left), r1 = max(right, (--r)->second);
        intervals.erase(l, ++r);
        if (l1 < left) {
            intervals[l1] = left;
        }
        if (r1 > right) {
            intervals[right] = r1;
        }
    }
    map<int, int> intervals;
};