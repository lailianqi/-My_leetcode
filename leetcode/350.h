#include <vector>
#include <multiset>
using namespace std;
//自己的第一种解法
class Solution {
  public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
        multiset<int> s(nums1.begin(), nums1.end());
        vector<int> out;
        for (int x : nums2) {
            //不能直接使用erase,要不然会一次性删除所有相同的元素
            auto pos = s.find(x);
            if (pos != s.end()) {
                out.push_back(x);
                s.erase(pos);
            }
        }
        return out;
    }
};

// leetcode的解法
// https://discuss.leetcode.com/topic/45893/c-hash-table-solution-and-sort-two-pointers-solution-with-time-and-space-complexity/2
namespace leetanswer {
class Solution_0 {
  public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
        unordered_map<int, int> dict;
        vector<int> res;
        for (int i = 0; i < (int)nums1.size(); i++)
            dict[nums1[i]]++;
        for (int i = 0; i < (int)nums2.size(); i++)
            if (--dict[nums2[i]] >= 0)
                res.push_back(nums2[i]);
        return res;
    }
};
class Solution_1 {
  public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
        unordered_map<int, int> dict;
        vector<int> res;
        for (int i = 0; i < (int)nums1.size(); i++)
            dict[nums1[i]]++;
        for (int i = 0; i < (int)nums2.size(); i++)
            if (dict.find(nums2[i]) != dict.end() && --dict[nums2[i]] >= 0)
                res.push_back(nums2[i]);
        return res;
    }
};

class Solution_2 {
  public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int n1 = (int)nums1.size(), n2 = (int)nums2.size();
        int i1 = 0, i2 = 0;
        vector<int> res;
        while (i1 < n1 && i2 < n2) {
            if (nums1[i1] == nums2[i2]) {
                res.push_back(nums1[i1]);
                i1++;
                i2++;
            } else if (nums1[i1] > nums2[i2]) {
                i2++;
            } else {
                i1++;
            }
        }
        return res;
    }
};
};

// sp大神的解法
// https://discuss.leetcode.com/topic/45934/short-python-c/2
class Solution_0 {
    vector<int> intersect(vector<int> &a, vector<int> &b) {
        unordered_map<int, int> ctr;
        for (int i : a)
            ctr[i]++;
        vector<int> out;
        for (int i : b)
            if (ctr[i]-- > 0)
                out.push_back(i);
        return out;
    }
};

class Solution_1 {
    vector<int> intersect(vector<int> &a, vector<int> &b) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        a.erase(
            set_intersection(a.begin(), a.end(), b.begin(), b.end(), a.begin()),
            a.end());
        return a;
    }
};