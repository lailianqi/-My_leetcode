#include <vector>
#include <unordered_set>
#include <climits>
#include <algorithm>
using namespace std;
//一看就知道没有思路 做不出来
// leetcode的答案
// https://discuss.leetcode.com/topic/56052/really-easy-understanding-solution-o-n-java
class Solution {
  public:
    bool isRectangleCover(vector<vector<int>> &rectangles) {
        if (rectangles.empty() || rectangles[0].empty()) {
            return false;
        }
        int x1 = INT_MAX, x2 = INT_MIN, y1 = INT_MAX, y2 = INT_MIN, area = 0;
        unordered_set<string> directory;
        for (auto element : rectangles) {
            x1 = min(element[0], x1);
            y1 = min(element[1], y1);
            x2 = max(element[2], x2);
            y2 = max(element[3], y2);
            area += (element[2] - element[0]) * (element[3] - element[1]);
            string leftButtom =
                to_string(element[0]) + " " + to_string(element[1]);
            string leftTop =
                to_string(element[0]) + " " + to_string(element[3]);
            string rightBottom =
                to_string(element[2]) + " " + to_string(element[1]);
            string rightTop =
                to_string(element[2]) + " " + to_string(element[3]);
            if (!directory.erase(leftButtom))
                directory.insert(leftButtom);
            if (!directory.erase(leftTop))
                directory.insert(leftTop);
            if (!directory.erase(rightBottom))
                directory.insert(rightBottom);
            if (!directory.erase(rightTop))
                directory.insert(rightTop);
        }
        if (directory.find(to_string(x1) + " " + to_string(y1)) ==
                directory.end() ||
            directory.find(to_string(x1) + " " + to_string(y2)) ==
                directory.end() ||
            directory.find(to_string(x2) + " " + to_string(y1)) ==
                directory.end() ||
            directory.find(to_string(x2) + " " + to_string(y2)) ==
                directory.end() ||
            directory.size() != 4) {
            return false;
        }
        return area == (x2 - x1) * (y2 - y1);
    }
};

// leetcode的答案 上面的改进版
// https://discuss.leetcode.com/topic/56052/really-easy-understanding-solution-o-n-java/29?page=2
class Solution {
  public:
    bool isRectangleCover(vector<vector<int>> &rectangles) {
        if (rectangles.empty() || rectangles[0].empty()) {
            return false;
        }
        int x1 = INT_MAX, x2 = INT_MIN, y1 = INT_MAX, y2 = INT_MIN, area = 0;
        unordered_set<string> directory;
        for (auto element : rectangles) {
            x1 = min(element[0], x1);
            y1 = min(element[1], y1);
            x2 = max(element[2], x2);
            y2 = max(element[3], y2);
            area += (element[2] - element[0]) * (element[3] - element[1]);
            string leftButtom = getKey(element[0], element[1]);
            string leftTop = getKey(element[0], element[3]);
            string rightBottom = getKey(element[2], element[1]);
            string rightTop = getKey(element[2], element[3]);
            if (!directory.erase(leftButtom))
                directory.insert(leftButtom);
            if (!directory.erase(leftTop))
                directory.insert(leftTop);
            if (!directory.erase(rightBottom))
                directory.insert(rightBottom);
            if (!directory.erase(rightTop))
                directory.insert(rightTop);
        }
        return directory.count(getKey(x1, y1)) &&
               directory.count(getKey(x1, y2)) &&
               directory.count(getKey(x2, y1)) &&
               directory.count(getKey(x2, y2)) && directory.size() == 4 &&
               area == (x2 - x1) * (y2 - y1);
    }

  private:
    inline string getKey(int x, int y) {
        return to_string(x) + " " + to_string(y);
    }
};

//另外的一种解决的方法
// leetcode的答案
// https://discuss.leetcode.com/topic/55923/o-n-solution-by-counting-corners-with-detailed-explaination?page=1
// https://www.cnblogs.com/grandyang/p/5825619.html