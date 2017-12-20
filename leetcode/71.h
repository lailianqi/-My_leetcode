#include <string>
#include <sstream>
#include <vector>
using namespace std;
//参考的答案
class Solution {
  public:
    string simplifyPath(string path) {
        vector<string> sources;
        vector<string> st;
        string result;
        split(path, '/', sources);
        for (auto a : sources) {
            if (a == "" || a == ".")
                continue;
            if (a == ".." && !st.empty()) {
                st.pop_back();
            } else if (a != "..") {
                st.push_back(a);
            }
        }
        for (auto a : st) {
            result += "/" + a;
        }
        return st.empty() ? "/" : result;
    }
    void split(string s, char delim, vector<string> &sources) {
        string temp;
        stringstream ss(s);
        while (getline(ss, temp, delim)) {
            sources.push_back(temp);
        }
    }
};