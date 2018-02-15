#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

// 直接看的答案 这题没有想出来
// https://leetcode.com/problems/exclusive-time-of-functions/discuss/105062/Java-Stack-Solution-O(n)-Time-O(n)-Space
/*
Input:
n = 2
logs =
["0:start:0",
 "1:start:2",
 "1:end:5",
 "0:end:6"]
Output:[3, 4]
*/

class Solution {
  public:
    vector<int> exclusiveTime(int n, vector<string> &logs) {
        vector<int> res(n, 0);
        stack<int> st;
        int pre = 0;
        for (int i = 0; i < logs.size(); i++) {
            istringstream ss(logs[i]);
            string temp, action;
            int id, time;
            getline(ss, temp, ':');
            id = stoi(temp);
            getline(ss, temp, ':');
            action = temp;
            getline(ss, temp, ':');
            time = stoi(temp);
            if (action == "start") {
                if (!st.empty()) {
                    res[st.top()] += time - pre;
                }
                st.push(id);
                pre = time;
            } else {
                res[st.top()] += time - pre + 1;
                st.pop();
                pre = time + 1;
            }
        }
        return res;
    }
};