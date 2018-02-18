#include <algorithm>
#include <string>
#include <vector>
using namespace std;
// 72周周赛 成功ac
class Solution {
  public:
    vector<string> letterCasePermutation(string S) {
        helper(S, 0);
        return res;
    }

    void helper(string &S, int start) {
        for (int i = start; i < S.size(); i++) {
            if (islower(S[i])) {
                S[i] = toupper(S[i]);
                helper(S, i + 1);
                S[i] = tolower(S[i]);
            } else if (isupper(S[i])) {
                S[i] = tolower(S[i]);
                helper(S, i + 1);
                S[i] = toupper(S[i]);
            }
        }
        res.push_back(S);
    }
    vector<string> res;
};