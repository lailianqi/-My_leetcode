#include <algorithm>
#include <map>
#include <string>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> anagramMappings(vector<int> &A, vector<int> &B) {
        map<int, int> dir;
        vector<int> res;
        for (int i = 0; i < B.size(); i++) {
            dir[B[i]] = i;
        }
        for (int i = 0; i < A.size(); i++) {
            res.push_back(dir[A[i]]);
        }
        return res;
    }
};

class Solution_0 {
  public:
    string boldWords(vector<string> &words, string S) {

    }
};

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution_1 {
  public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> &avails) {
        vector<Interval> temp;
        vector<Interval> res;
        for (int i = 0; i < avails.size(); i++) {
            for (int j = 0; j < avails[i].size(); j++) {
                temp.push_back(avails[i][j]);
            }
        }
        sort(temp.begin(), temp.end(),
             [](Interval &a, Interval &b) { return a.start < b.start; });
        Interval it(temp[0].start, temp[0].end);
        for (int i = 1; i < temp.size(); i++) {
            if (temp[i].start > it.end) {
                res.push_back(Interval(it.end, temp[i].start));
                it = temp[i];
            } else {
                it.end = max(it.end, temp[i].end);
            }
        }
        return res;
    }
};

void test() {}