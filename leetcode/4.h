#include <vector>
using namespace std;
class Solution {
    public:
      double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
            vector<int>::iterator a = nums1.begin();
            vector<int>::iterator b = nums2.begin();
            int total = nums1.size() + nums2.size();
            if (total & 1)
                  return findkth(a, nums1.size(), b, nums2.size(),
                                 total / 2 + 1);
            else
                  return (findkth(a, nums1.size(), b, nums2.size(), total / 2) +
                          findkth(a, nums1.size(), b, nums2.size(),
                                  total / 2 + 1)) /
                         2;
      }
      double findKth(int *nums1, int m, int *nums2, int n, int k) {
            if (m > n) {
                  return findKth(nums2, n, nums1, m, k);
            }
            if (m == 0) {
                  return nums2[k - 1];
            }
            if (k == 1) {
                  return min(nums1[0], nums2[0]);
            }
            int i = min(k / 2, m), j = k - i;
            if (nums1[i - 1] < nums2[j - 1]) {
                  return findKth(nums1 + i, m - i, nums2, n, j);
            } else if (nums1[i - 1] > nums2[j - 1]) {
                  return findKth(nums1, m, nums2 + j, n - j, i);
            } else {
                  return nums1[i - 1];
            }
      }
      double findkth(vector<int>::iterator a, int m, vector<int>::iterator b,
                     int n, int k) {
            if (m > n)
                  return findkth(b, n, a, m, k);
            if (m == 0)
                  return b[k - 1];
            if (k == 1)
                  return min(*a, *b);
            int i = min(k / 2, m), j = k - i;
            if (*(a + i - 1) < *(b + j - 1))
                  return findkth(a + i, m - i, b, n, j);
            else if (*(a + i - 1) > *(b + j - 1))
                  return findkth(a, m, b + j, n - j, i);
            else
                  return *(a + i - 1);
      }
};