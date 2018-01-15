#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution_0 {
  public:
    void MergeSort(vector<int>::iterator begin, vector<int>::iterator end) {
        if (end - begin <= 1) {
            return;
        }
        auto mid = begin + (end - begin) / 2;
        MergeSort(begin, mid + 1);
        MergeSort(mid + 1, end);
        inplace_merge(begin, mid + 1, end);
    }
};
void MergeSort(vector<int>::iterator begin, vector<int>::iterator end) {
    if (end - begin <= 1) {
        return;
    }
    auto mid = begin + (end - begin) / 2;
    MergeSort(begin, mid); //因为end是取不到的 所以这里这样写是对的
    MergeSort(mid, end);
    inplace_merge(begin, mid, end);
}
void test() {
    vector<int> nums = {1, 6, 2, 9, 4, 5};
    MergeSort(nums.begin(), nums.end());
    for (auto element : nums) {
        cout << element << " ";
    }
}