#include <vector>
#include <algorithm>
using namespace std;

//最简单的写法
class Solution {
  public:
    void sortColors(vector<int> &nums) { sort(nums.begin(), nums.end()); }
};

//直接统计个数  two pass O(m+n) space
class Solution_0 {
  public:
    void sortColors(vector<int> &nums) {
        int n0 = 0, n1 = 0, n2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0)
                n0++;
            else if (nums[i] == 1)
                n1++;
            else
                n2++;
        }
        for (int i = 0; i < n0; i++)
            nums[i] = 0;
        for (int i = 0; i < n1; i++)
            nums[n0 + i] = 1;
        for (int i = 0; i < n2; i++)
            nums[n0 + n1 + i] = 2;
    }
};

//下面是leetcode的答案

// two pass O(m+n) space
void sortColors1(int A[], int n) {
    int num0 = 0, num1 = 0, num2 = 0;

    for (int i = 0; i < n; i++) {
        if (A[i] == 0)
            ++num0;
        else if (A[i] == 1)
            ++num1;
        else if (A[i] == 2)
            ++num2;
    }

    for (int i = 0; i < num0; ++i)
        A[i] = 0;
    for (int i = 0; i < num1; ++i)
        A[num0 + i] = 1;
    for (int i = 0; i < num2; ++i)
        A[num0 + num1 + i] = 2;
}

// one pass in place solution  //最佳方案
void sortColors2(int A[], int n) {
    int n0 = -1, n1 = -1, n2 = -1;
    for (int i = 0; i < n; ++i) {
        if (A[i] == 0) {
            A[++n2] = 2;
            A[++n1] = 1;
            A[++n0] = 0;
        } else if (A[i] == 1) {
            A[++n2] = 2;
            A[++n1] = 1;
        } else if (A[i] == 2) {
            A[++n2] = 2;
        }
    }
}

// one pass in place solution
void sortColors3(int A[], int n) {
    int j = 0, k = n - 1;
    for (int i = 0; i <= k; ++i) {
        if (A[i] == 0 && i != j)
            swap(A[i--], A[j++]);
        else if (A[i] == 2 && i != k)
            swap(A[i--], A[k--]);
    }
}

// one pass in place solution
void sortColors4(int A[], int n) {
    int j = 0, k = n - 1;
    for (int i = 0; i <= k; i++) {
        if (A[i] == 0)
            swap(A[i], A[j++]);
        else if (A[i] == 2)
            swap(A[i--], A[k--]);
    }
}