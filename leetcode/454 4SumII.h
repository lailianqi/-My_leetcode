#include <vector>
#include <map>
#include <unordered_map>
using namespace std;
//暴力的解法 通不过ac
class Solution {
  public:
    int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C,
                     vector<int> &D) {
        int res = 0;
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < B.size(); j++) {
                for (int k = 0; k < C.size(); k++) {
                    for (int t = 0; t < D.size(); t++) {
                        if (A[i] + B[j] + C[k] + D[t] == 0) {
                            res++;
                        }
                    }
                }
            }
        }
        return res;
    }
};

// 并没想到其它的解法 所以直接看了后面leetcode的答案
// https://discuss.leetcode.com/topic/67593/clean-java-solution-o-n-2
class Solution_0 {
  public:
    int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C,
                     vector<int> &D) {
        int res = 0;
        unordered_map<int, int> dir; //比用map快多了
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < B.size(); j++) {
                dir[A[i] + B[j]]++;
            }
        }
        for (int i = 0; i < C.size(); i++) {
            for (int j = 0; j < D.size(); j++) {
                res += dir.count(-(C[i] + D[j])) ? dir[-(C[i] + D[j])] : 0;
            }
        }
        return res;
    }
};