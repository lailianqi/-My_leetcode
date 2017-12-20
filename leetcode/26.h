#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
  public:
    /*    int removeDuplicates(vector<int> &nums) {
            int counter = 0;
            vector<int>::iterator it = nums.begin();
            while (it != nums.end()) {
                if (it == nums.begin() || *it != *(it - 1)) {
                    counter++;
                } else {
                    nums.erase(it);
                }
                it++;
            }
            return counter;
        }*/
    int removeDuplicates(vector<int> &nums) {
        int counter = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0 || nums[i] != nums[i - 1]) {
                nums[counter++] = nums[i];
            }
        }
        return counter;
    }
};

void test() {
    vector<int> v = {1, 1, 2};
    Solution s;
    s.removeDuplicates(v);
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
}