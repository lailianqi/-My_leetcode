#include <algorithm>
#include <map>
#include <string>
#include <vector>
using namespace std;

// 自己的第一种写法 成功ac
// 这题直接参考731MyCalendarII.h就可以直接写出来  并不难
// https://leetcode.com/problems/my-calendar-iii/discuss/109556/JavaC++-Clean-Code
class MyCalendarThree {
  public:
    MyCalendarThree() {}

    int book(int start, int end) {
        int res = 0;
        dir[start]++, dir[end]--;
        int currValue = 0;
        for (auto &p : dir) {
            currValue += p.second;
            res = max(res, currValue);
        }
        return res;
    }

  private:
    map<int, int> dir;
};