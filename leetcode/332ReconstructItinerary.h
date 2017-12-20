#include <vector>
#include <set>
#include <algorithm>
#include <multiset>
#include <map>
#include <iostream>
#include <deque>
#include <string>
#include <stack>
using namespace std;
//当初自己的第一想法，然而当初并没有理解题意 所以没有通过测试
//题的网址
// https://leetcode.com/problems/reconstruct-itinerary/description/
// http://blog.csdn.net/y990041769/article/details/9371591
class Solution {
  public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        vector<string> result;
        set<string> visited;
        deque<string> nodeQueue;
        map<string, set<string>> graphPaths = createGraph(tickets);
        nodeQueue.push_back("JFK");
        result.push_back("JFK");
        while (!nodeQueue.empty()) {
            int nodeNum = nodeQueue.size();
            string minPath = "";
            for (int i = 0; i < nodeNum; i++) {
                string path = nodeQueue.front();
                nodeQueue.pop_front();
                for (auto element : graphPaths[path]) {
                    if (visited.find(element) == visited.end()) {
                        minPath =
                            minPath == "" ? element : min(minPath, element);
                    }
                }
            }
            if (minPath != "") {
                nodeQueue.push_back(minPath);
                if (minPath != "JFK")
                    visited.insert(minPath);
                result.push_back(minPath);
            }
        }
        return result;
    }

    map<string, set<string>>
    createGraph(vector<pair<string, string>> &tickets) {
        map<string, set<string>> graphPaths;
        for (auto element : tickets) {
            graphPaths[element.first].insert(element.second);
        }
        return graphPaths;
    }
};
//参考的答案 下面是网址 http://www.cnblogs.com/grandyang/p/5183210.html
// http://www.cnblogs.com/ivorysi/p/5745005.html
//欧拉回路 https://en.wikipedia.org/wiki/Eulerian_path
//递归回溯的写法
class Solution_0 {
  public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        vector<string> res;
        map<string, multiset<string>> graphPaths = createGraph(tickets);
        helper(graphPaths, "JFK", res);
        reverse(res.begin(), res.end());
        return res;
    }
    void helper(map<string, multiset<string>> &graphPaths, string s,
                vector<string> &res) {
        while (graphPaths[s].size()) {
            string temp = *graphPaths[s].begin();
            graphPaths[s].erase(graphPaths[s].begin());
            helper(graphPaths, temp, res);
        }
        res.push_back(s);
    }
    map<string, multiset<string>>
    createGraph(vector<pair<string, string>> &tickets) {
        map<string, multiset<string>> graphPaths;
        for (auto element : tickets) {
            graphPaths[element.first].insert(element.second);
        }
        return graphPaths;
    }
};
// 最原始的stack的写法
// https://discuss.leetcode.com/topic/36721/short-c-dfs-iterative-44ms-solution-with-explanation-no-recursive-calls-no-backtracking
class Solution_1 {
  public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        vector<string> res;
        map<string, multiset<string>> graphPaths = createGraph(tickets);
        stack<string> nodesStack;
        nodesStack.push("JFK");
        helper(graphPaths, nodesStack, res);
        reverse(res.begin(), res.end());
        return res;
    }
    void helper(map<string, multiset<string>> &graphPaths,
                stack<string> &nodesStack, vector<string> &res) {
        while (!nodesStack.empty()) {
            string temp = nodesStack.top();
            if (!graphPaths[temp].empty()) {
                string element = *graphPaths[temp].begin();
                graphPaths[temp].erase(graphPaths[temp].begin());
                nodesStack.push(element);
            } else {
                res.push_back(temp);
                nodesStack.pop();
            }
        }
    }
    map<string, multiset<string>>
    createGraph(vector<pair<string, string>> &tickets) {
        map<string, multiset<string>> graphPaths;
        for (auto element : tickets) {
            graphPaths[element.first].insert(element.second);
        }
        return graphPaths;
    }
};
//另外一种堆栈的写法 leetcode的答案
//挺牛逼的
// https://discuss.leetcode.com/topic/36370/short-ruby-python-java-c/2?page=1
class Solution_2 {
  public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        vector<string> res;
        map<string, multiset<string>> graphPaths = createGraph(tickets);
        stack<string> nodesStack;
        nodesStack.push("JFK");
        helper(graphPaths, nodesStack, res);
        reverse(res.begin(), res.end());
        return res;
    }
    void helper(map<string, multiset<string>> &graphPaths,
                stack<string> &nodesStack, vector<string> &res) {
        while (!nodesStack.empty()) {
            while (!graphPaths[nodesStack.top()].empty()) {
                string temp = nodesStack.top();
                nodesStack.push(*graphPaths[temp].begin());
                graphPaths[temp].erase(graphPaths[temp].begin());
            }
            res.push_back(nodesStack.top());
            nodesStack.pop();
        }
    }
    map<string, multiset<string>>
    createGraph(vector<pair<string, string>> &tickets) {
        map<string, multiset<string>> graphPaths;
        for (auto element : tickets) {
            graphPaths[element.first].insert(element.second);
        }
        return graphPaths;
    }
};

void test() { Solution s; }