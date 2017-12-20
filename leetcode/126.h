#include <vector>
#include <unordered_set>
#include <queue>
#include <string>
#include <map>
using namespace std;
//网上的解法 http://www.cnblogs.com/grandyang/p/4548184.html
class Solution {
  public:
    vector<vector<string>> findLadders(string beginWord, string endWord,
                                       vector<string> &wordList) {
        vector<vector<string>> res;
        unordered_set<string> dict(wordList.begin(), wordList.end());
        vector<string> p{beginWord};
        queue<vector<string>> paths;
        paths.push(p);
        int level = 1, minLevel = INT_MAX;
        unordered_set<string> words;
        while (!paths.empty()) {
            auto t = paths.front();
            paths.pop();
            if (t.size() > level) {
                for (string w : words)
                    dict.erase(w);
                words.clear();
                level = t.size();
                if (level > minLevel)
                    break;
            }
            string last = t.back();
            for (int i = 0; i < last.size(); i++) {
                string newLast = last;
                for (char ch = 'a'; ch <= 'z'; ++ch) {
                    newLast[i] = ch;
                    if (!dict.count(newLast))
                        continue;
                    words.insert(newLast);
                    vector<string> nextPath = t;
                    nextPath.push_back(newLast);
                    if (newLast == endWord) {
                        res.push_back(nextPath);
                        minLevel = level;
                    } else {
                        paths.push(nextPath);
                    }
                }
            }
        }
        return res;
    }
};
// https://discuss.leetcode.com/topic/2857/share-two-similar-java-solution-that-accpted-by-oj/21?page=2
// leetcode的写法
class Solution_0 {
  public:
    vector<vector<string>> findLadders(string beginWord, string endWord,
                                       vector<string> &wordList) {
        unordered_set<string> dictionary(wordList.begin(), wordList.end());
        vector<vector<string>> res;
        map<string, vector<string>> nodeNeighbors; // Neighbors for every node
        map<string, int> distance; // Distance of every node from the start node
        vector<string> solution;
        dictionary.insert(beginWord);
        bfs(beginWord, endWord, dictionary, nodeNeighbors, distance);
        dfs(beginWord, endWord, nodeNeighbors, distance, solution, res);
        return res;
    }
    void bfs(string &start, string &end, unordered_set<string> &dictionary,
             map<string, vector<string>> &nodeNeighbors,
             map<string, int> &distance) {
        for (string str : dictionary) {
            nodeNeighbors[str] = vector<string>();
        }
        queue<string> pathsQueue;
        pathsQueue.push(start);
        distance[start] = 0;
        while (!pathsQueue.empty()) {
            int count = pathsQueue.size();
            for (int i = 0; i < count; i++) {
                string curr = pathsQueue.front();
                int currDistance = distance[curr];
                vector<string> currentNodesNeighbors =
                    getNeighbors(curr, dictionary);
                for (string neighbor : currentNodesNeighbors) {
                    nodeNeighbors[curr].push_back(neighbor);
                    if (distance.find(neighbor) != distance.end()) {
                        distance[neighbor] = currDistance + 1;
                        if (end == neighbor) {
                            break;
                        } else {
                            pathsQueue.push(neighbor);
                        }
                    }
                }
            }
        }
    }

    vector<string> getNeighbors(string &node,
                                unordered_set<string> &dictionary) {
        vector<string> neighbours;
        for (int i = 0; i < node.size(); i++) {
            string newLast = node;
            for (char ch = 'a'; ch <= 'z'; ++ch) {
                newLast[i] = ch;
                if (dictionary.count(newLast)) {
                    neighbours.push_back(newLast);
                }
            }
        }
        return neighbours;
    }

    void dfs(string &beginWord, string &endWord,
             map<string, vector<string>> &nodeNeighbors,
             map<string, int> &distance, vector<string> &individualSequence,
             vector<vector<string>> &results) {
        individualSequence.push_back(beginWord);
        if (endWord == beginWord) {
            results.push_back(vector<string>(individualSequence));
        }
        for (string next : nodeNeighbors[beginWord]) {
            if (distance[next] == distance[beginWord] + 1) {
                dfs(next, endWord, nodeNeighbors, distance, individualSequence,
                    results);
            }
        }
        individualSequence.erase(individualSequence.begin() +
                                 individualSequence.size() - 1);
    }
};
//参照写法一，自己的写法
class Solution_1 {
  public:
    int minLevel = INT_MAX;
    vector<vector<string>> findLadders(string beginWord, string endWord,
                                       vector<string> &wordList) {
        vector<vector<string>> res;
        unordered_set<string> directory(wordList.begin(), wordList.end());
        vector<string> p{beginWord};
        queue<vector<string>> paths;
        paths.push(p);
        unordered_set<string> words;
        while (!paths.empty()) {
            if (minLevel != INT_MAX)
                break;
            for (string w : words)
                directory.erase(w);
            words.clear();
            int pathSize = paths.size();
            for (int i = 0; i < pathSize; i++) {
                vector<string> path = paths.front();
                paths.pop();
                getNeighbors(endWord, paths, path, words, directory, res);
            }
        }
        return res;
    }
    void getNeighbors(string &endWord, queue<vector<string>> &paths,
                      vector<string> &path, unordered_set<string> &words,
                      unordered_set<string> &dictionary,
                      vector<vector<string>> &res) {
        string s = path.back();
        for (int i = 0; i < s.size(); i++) {
            string newLast = s;
            for (char ch = 'a'; ch <= 'z'; ++ch) {
                newLast[i] = ch;
                if (dictionary.count(newLast)) {
                    vector<string> nextPath = path;
                    nextPath.push_back(newLast);
                    words.insert(newLast);
                    if (newLast == endWord) {
                        res.push_back(nextPath);
                        minLevel = path.size();
                    } else {
                        paths.push(nextPath);
                    }
                }
            }
        }
    }
};