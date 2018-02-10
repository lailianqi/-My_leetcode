#include <vector>
using namespace std;
// 自己的第一种写法 Greedy的思想 成功ac
// https://discuss.leetcode.com/topic/91312/c-java-clean-code
// https://discuss.leetcode.com/topic/91376/simplest-c-code
class Solution {
  public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n) {
        flowerbed.insert(flowerbed.begin(), 0);
        flowerbed.push_back(0);
        for (int i = 1; i < flowerbed.size() - 1; i++) {
            if (flowerbed[i - 1] == 0 && flowerbed[i] == 0 &&
                flowerbed[i + 1] == 0) {
                n--;
                i++;
            }
        }
        return n <= 0;
    }
};

//上面一样的思想 写法略有不同
class Solution_0 {
  public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n) {
        for (int i = 0; i < flowerbed.size(); i++) {
            if ((i == 0 || flowerbed[i - 1] == 0) && flowerbed[i] == 0 &&
                (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0)) {
                n--;
                i++;
            }
        }
        return n <= 0;
    }
};