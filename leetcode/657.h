#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

//自己的第一种方案 成功ac
class Solution {
  public:
    bool judgeCircle(string moves) {
        unordered_map<char, pair<int, int>> dir = {
            {'L', {-1, 0}}, {'R', {1, 0}}, {'U', {0, -1}}, {'D', {0, 1}}};

        pair<int, int> originalPlace = {0, 0};
        for (int i = 0; i < moves.size(); i++) {
            originalPlace.first += dir[moves[i]].first;
            originalPlace.second += dir[moves[i]].second;
        }
        return originalPlace.first == 0 && originalPlace.second == 0;
    }
};
//自己的第二种方案 成功ac
class Solution_0 {
  public:
    bool judgeCircle(string moves) {
        unordered_map<char, int> dir;
        for (int i = 0; i < moves.size(); i++) {
            dir[moves[i]]++;
        }
        return dir['L'] == dir['R'] && dir['U'] == dir['D'];
    }
};