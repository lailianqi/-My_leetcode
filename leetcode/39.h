#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

//参照了标准答案
class Solution {
  public:
    vector<vector<int> > answers;
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<int> answer;
        sort(candidates.begin(), candidates.end());
        combinationSum(candidates,answer,target,0);
        return answers;
    }
    void combinationSum(vector<int> &candidates, vector<int> &answer,int target, int start) {
        if (target == 0) {
            answers.push_back(answer);
            return;
        } else {
            for (int i = start;i < candidates.size() && candidates[i] <= target; i++) {
                answer.push_back(candidates[i]);
                combinationSum(candidates, answer, target - candidates[i], i);
                answer.pop_back();
            }
        }
    }
};