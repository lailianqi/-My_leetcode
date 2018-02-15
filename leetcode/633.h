#include <cmath>

//自己的第一种解法 成功ac
class Solution {
  public:
    bool judgeSquareSum(int c) {
        for (int i = 0, j = sqrt(c); i <= j;) {
            int temp = i * i + j * j;
            if (temp < c) {
                i++;
            } else if (temp > c) {
                j--;
            } else {
                return true;
            }
        }
        return false;
    }
};

// LeetCode上面另外的一种解法
/*
public class Solution {
    public boolean judgeSquareSum(int c) {
        HashSet<Integer> set = new HashSet<Integer>();
        
        for (int i = 0; i <= Math.sqrt(c); i++) {
            set.add(i * i);
            if (set.contains(c - i * i)) {
                return true;
            }
        }
        return false;
    }
}
*/