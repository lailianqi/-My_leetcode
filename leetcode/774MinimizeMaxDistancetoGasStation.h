#include <queue>
#include <vector>
using namespace std;
// 第69周的周赛
// 没写出来
// LeetCode的答案 看了也觉得一知半解 没有完全理解
// https://discuss.leetcode.com/topic/118701/easy-and-concise-solution-using-binary-search-c-java-python
class Solution {
  public:
    double minmaxGasDist(vector<int> &stations, int K) {
        int counter = 0, m = stations.size();
        float left = 0, right = stations[m - 1] - stations[0];
        while (left + 0.00001 < right) {
            float mid = (left + right) / 2;
            counter = 0;
            for (int i = 0; i < m - 1; i++) {
                counter += ceil((stations[i + 1] - stations[i]) / mid) - 1;
            }
            if (counter > K) {
                left = mid;
            } else {
                right = mid;
            }
        }
        return right;
    }
};

// 第二种方案 来自LeetCode 感觉是最容易的理解的方案
// 和我一开始的想法有相似的地方 但是我没有写出来
// https://discuss.leetcode.com/topic/118688/accepted-c-solution-using-heap-and-a-small-trick
// https://discuss.leetcode.com/topic/118722/c-solution-o-nlogn-using-prority_queue
class CustomClass {
  public:
    CustomClass(int x) : numerator(x), denominator(1), val(x) {}
    bool operator<(const CustomClass &o) const { return val < o.val; }
    double numerator;
    double denominator;
    double val;
};
class Solution_0 {
  public:
    double minmaxGasDist(vector<int> &stations, int K) {
        double res = 0, threshold = 0;
        priority_queue<CustomClass> gap;
        for (int i = 1; i < stations.size(); i++) {
            int diff = stations[i] - stations[i - 1];
            threshold += diff / (double(K + 1));
            gap.push(CustomClass(diff));
        }
        for (int i = 0; i < K; i++) {
            auto element = gap.top();
            gap.pop();
            while (i < K &&
                   (element.val >= gap.top().val || element.val > threshold)) {
                i++;
                element.denominator++;
                element.val = element.numerator / element.denominator;
            }
            gap.push(element);
        }
        return gap.top().val;
    }
};