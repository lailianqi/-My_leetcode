#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;
//卡住了 没有想出来
// class Solution {
//   public:
//     vector<double> calcEquation(vector<pair<string, string>> equations,
//                                 vector<double> &values,
//                                 vector<pair<string, string>> queries) {
//         vector<double> res;
//         unordered_map<string, unordered_map<string, int>> dir;
//         for (int i = 0; i < equations.size(); i++) {
//             dir[equations[i].first][equations[i].second] = values[i];
//         }
//         for (int i = 0; i < queries.size(); i++) {
//             string dividend = queries[i].first, Divisor = queries[i].second;
//         }
//     }
// };

// leetcode的答案
// https://discuss.leetcode.com/topic/59146/java-ac-solution-using-graph/10?page=1
// https://discuss.leetcode.com/topic/59146/java-ac-solution-using-graph/14?page=1
// 当x/x x过没出现，oj上是-1 理论上是1 下面的解法输出的是-1
class Solution {
  public:
    vector<double> calcEquation(vector<pair<string, string>> equations,
                                vector<double> &values,
                                vector<pair<string, string>> queries) {
        unordered_map<string, unordered_map<string, double>> dir;
        vector<double> res;
        for (int i = 0; i < equations.size(); i++) {
            dir[equations[i].first][equations[i].second] = values[i];
            dir[equations[i].second][equations[i].first] = 1 / values[i];
        }
        for (int i = 0; i < queries.size(); i++) {
            if (dir.count(queries[i].first) && dir.count(queries[i].second)) {
                if (queries[i].first == queries[i].second) {
                    res.push_back(1.0);
                } else {
                    unordered_set<string> record;
                    res.push_back(helper(queries[i].first, queries[i].second,
                                         record, dir, 1.0));
                }
            } else {
                res.push_back(-1.0);
            }
        }
        return res;
    }
    double helper(string s, string t, unordered_set<string> &record,
                  unordered_map<string, unordered_map<string, double>> &dir,
                  double val) {
        if (dir[s].count(t)) {
            return val * dir[s][t];
        }
        double res = -1.0;
        for (auto &element : dir[s]) {
            if (record.count(element.first) == 0) {
                record.insert(element.first);
                res = helper(element.first, t, record, dir,
                             val * dir[s][element.first]);
                if (res != -1.0) {
                    return res;
                }
            }
        }
        return res;
    }
};
//上面的解法没问题 当x/x x是没出现的时，oj上是-1 理论上是1 这里输出1
class Solution_0 {
  public:
    vector<double> calcEquation(vector<pair<string, string>> equations,
                                vector<double> &values,
                                vector<pair<string, string>> queries) {
        unordered_map<string, unordered_map<string, double>> dir;
        vector<double> res;
        for (int i = 0; i < equations.size(); i++) {
            dir[equations[i].first][equations[i].second] = values[i];
            dir[equations[i].second][equations[i].first] = 1 / values[i];
        }
        for (int i = 0; i < queries.size(); i++) {
            if (queries[i].first == queries[i].second) {
                res.push_back(1.0);
            } else if (dir.count(queries[i].first) &&
                       dir.count(queries[i].second)) {
                unordered_set<string> record;
                res.push_back(helper(queries[i].first, queries[i].second,
                                     record, dir, 1.0));
            } else {
                res.push_back(-1.0);
            }
        }
        return res;
    }
    double helper(string s, string t, unordered_set<string> &record,
                  unordered_map<string, unordered_map<string, double>> &dir,
                  double val) {
        if (dir[s].count(t)) {
            return val * dir[s][t];
        }
        double res = -1.0;
        for (auto &element : dir[s]) {
            if (record.count(element.first) == 0) {
                record.insert(element.first);
                res = helper(element.first, t, record, dir,
                             val * dir[s][element.first]);
                if (res != -1.0) {
                    return res;
                }
            }
        }
        return res;
    }
};

// sp大神的解法
// https://discuss.leetcode.com/topic/58482/9-lines-floyd-warshall-in-python?page=1
// https://discuss.leetcode.com/topic/58482/9-lines-floyd-warshall-in-python/26?page=2