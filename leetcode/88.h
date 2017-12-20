#include <vector>
using namespace std;
//自己的答案，需要额外空间
class Solution {
  public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        vector<int> answer;
        int i = 0, j = 0;
        while (i < m || j < n) {
            if (i < m && j < n) {
                if (nums1[i] <= nums2[j]) {
                    answer.push_back(nums1[i++]);
                } else {
                    answer.push_back(nums2[j++]);
                }
            } else {
                answer.push_back(i == m ? nums2[j++] : nums1[i++]);
            }
        }
        nums1 = answer;
    }
};

class Solution_0 {
  public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        int i = m - 1, j = n - 1, totalSize = m + n - 1;
        while (j >= 0) {
            nums1[totalSize--] = i >= 0 && nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
        }
    }
};