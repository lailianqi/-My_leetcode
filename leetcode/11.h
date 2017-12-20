#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
      public:
        // 超时
        int maxArea1(vector<int> &height) {
                int maxsum = 0;
                for (int i = 0; i < height.size(); i++) {
                        for (int j = i + 1; j < height.size(); j++) {
                                maxsum = max(maxsum, (j - i) * min(height[i],
                                                                   height[j]));
                        }
                }
                return maxsum;
        }
        int maxArea(vector<int> &height) {
                int i = 0, j = height.size() - 1;
                int maxWater = 0;
                while (i < j) {
                        int heig = min(height[i], height[j]);
                        maxWater = max(maxWater, (j - i) * heig);
                        while (height[i] <= heig)
                                i++;
                        while (height[j] <= heig)
                                j--;
                }
                return maxWater;
        }
};