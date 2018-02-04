#include <string>
#include <unordered_map>
using namespace std;

// LeetCode第70周周赛
// 比赛中没有写出 所以比赛后直接看的答案
// leetcode的答案
// https://discuss.leetcode.com/topic/119476/c-simple-subsequence-matching-with-position-constraint
class Solution {
  public:
    bool canTransform(string start, string end) {
        int i = 0, j = 0, n = start.size();
        while (i < n && j < n) {
            while (i < n && start[i] == 'X')
                ++i;
            while (j < n && end[j] == 'X')
                ++j;
            if (i == n && j == n)
                break;
            if ((i == n || j == n) || (start[i] != end[j]) ||
                ((start[i] == 'R' && i > j) || (end[j] == 'L' && i < j))) {
                return false;
            }
            i++;
            j++;
        }
        return true;
    }
};

// 比赛第一名的答案 太牛逼 感觉每一题写的答案都是标准答案  比上面的答案牛逼
// https://leetcode.com/uwi/
/*

class Solution {
    public boolean canTransform(String start, String end) {
        if(!start.replace("X", "").equals(end.replace("X", "")))
            return false;
        int n = start.length(); int p = 0;
        for(int i = 0;i < n;i++){
            if(start.charAt(i) != 'X'){
                while(p < n && end.charAt(p) == 'X'){
                    p++;
                }
                if(start.charAt(i) == 'R'){
                    if(i > p)return false;
                }else{
                    if(i < p)return false;
                }
                p++;
            }
        }
        return true;
    }
};
*/