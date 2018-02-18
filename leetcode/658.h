#include <algorithm>
#include <string>
#include <vector>
using namespace std;

// 自己的第一种方案 成功ac 但是代码非常的丑陋
class Solution {
  public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x) {
        vector<int> res;
        int m = arr.size();
        int index = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        if ((index > 0 && x - arr[index - 1] < arr[index] - x) || index == m) {
            index--;
        }
        int left = index - 1, right = index + 1;
        res.push_back(arr[index]);
        k--;
        while ((left >= 0 || right <= m - 1) && k > 0) {
            if (left < 0) {
                res.push_back(arr[right++]);
            } else if (right >= m || ((x - arr[left]) <= (arr[right] - x))) {
                res.insert(res.begin(), arr[left--]);
            } else {
                res.push_back(arr[right++]);
            }
            k--;
        }
        return res;
    }
};

// leetcode的答案 上面代码的升价版
// https://leetcode.com/problems/find-k-closest-elements/discuss/106439/JavaC++-Very-simple-binary-search-solution

class Solution_0 {
  public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x) {
        int index = std::lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int i = index - 1, j = index;
        while (k--)
            (i < 0 || (j < arr.size() && abs(arr[i] - x) > abs(arr[j] - x)))
                ? j++
                : i--;
        return vector<int>(arr.begin() + i + 1, arr.begin() + j);
    }
};

// leetcode的答案 来自sp大神的解法
// https://leetcode.com/problems/find-k-closest-elements/discuss/106419/O(log-n)-Java-1-line-O(log(n)-+-k)-Ruby?page=1

class Solution_1 {
  public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x) {
        int lo = 0, hi = arr.size() - k;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (x - arr[mid] > arr[mid + k] - x)
                lo = mid + 1;
            else
                hi = mid;
        }
        return vector<int>(arr.begin() + lo, arr.begin() + lo + k);
    }
};