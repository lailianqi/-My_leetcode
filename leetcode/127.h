#include <map>
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;
//自己的写法
class Solution {
  public:
    int minLevel = 0;
    int level = 0;
    int ladderLength(string beginWord, string endWord,
                     vector<string> &wordList) {
        unordered_set<string> directory(wordList.begin(), wordList.end());
        queue<string> paths;
        paths.push(beginWord);
        while (!paths.empty()) {
            level++;
            int pathSize = paths.size();
            for (int i = 0; i < pathSize; i++) {
                string path = paths.front();
                paths.pop();
                getNeighbors(endWord, paths, path, directory);
                if (minLevel != 0) {
                    return minLevel;
                }
            }
        }
        return minLevel;
    }
    void getNeighbors(string &endWord, queue<string> &paths, string &path,
                      unordered_set<string> &dictionary) {
        for (int i = 0; i < path.size(); i++) {
            string newLast = path;
            for (char ch = 'a'; ch <= 'z'; ++ch) {
                newLast[i] = ch;
                if (dictionary.count(newLast)) {
                    dictionary.erase(newLast);
                    if (newLast == endWord) {
                        minLevel = level + 1;
                        return;
                    }
                    paths.push(newLast);
                }
            }
        }
    }
};

class Solution_0 {
  public:
    int ladderLength(string beginWord, string endWord,
                     vector<string> &wordList) {
        unordered_set<string> directory(wordList.begin(), wordList.end());
        if (directory.find(endWord) == directory.end())
            return 0;
        queue<string> paths;
        int step = 0;
        paths.push(beginWord);
        while (!paths.empty()) {
            int pathSize = paths.size();
            step++;
            for (int i = 0; i < pathSize; i++) {
                string path = paths.front();
                paths.pop();
                if (path == endWord) {
                    return step;
                }
                addNextWords(path, directory, paths);
            }
        }
        return 0;
    }
    void addNextWords(string word, unordered_set<string> &directory,
                      queue<string> &paths) {
        for (int i = 0; i < word.size(); i++) {
            char letter = word[i];
            for (char ch = 'a'; ch <= 'z'; ++ch) {
                word[i] = ch;
                if (directory.find(word) != directory.end()) {
                    paths.push(word);
                    directory.erase(word);
                }
            }
            word[i] = letter;
        }
    }
};

// https://discuss.leetcode.com/topic/29303/two-end-bfs-in-java-31ms?page=1
// leetcoded的答案

class Solution_1 {
  public:
    int ladderLength(string beginWord, string endWord,
                     vector<string> &wordList) {
        unordered_set<string> directory(wordList.begin(), wordList.end());
        if (directory.find(endWord) == directory.end())
            return 0;
        int step = 2;
        unordered_set<string> start, end;
        start.insert(beginWord);
        end.insert(endWord);
        directory.erase(beginWord);
        directory.erase(endWord);
        while (!start.empty()) {
            if (start.size() > end.size()) {
                swap(start, end);
            }
            unordered_set<string> newPaths;
            for (string cur : start) {
                if (addNextWords(cur, directory, newPaths, end))
                    return step;
            }
            start = newPaths;
            step++;
        }
        return 0;
    }
    bool addNextWords(string word, unordered_set<string> &directory,
                      unordered_set<string> &paths,
                      unordered_set<string> &end) {
        for (int i = 0; i < word.size(); i++) {
            char letter = word[i];
            for (char ch = 'a'; ch <= 'z'; ++ch) {
                word[i] = ch;
                if (end.find(word) != end.end()) {
                    return true;
                }
                if (directory.find(word) != directory.end()) {
                    paths.insert(word);
                    directory.erase(word);
                }
            }
            word[i] = letter;
        }
        return false;
    }
};
void test() {
    Solution_0 s;
    vector<string> ss = {"hot", "dot", "dog", "lot", "log"};
    s.ladderLength("hit", "cog", ss);
}

// -----------------------------二刷
class Solution_2 {
  public:
    int ladderLength(string beginWord, string endWord,
                     vector<string> &wordList) {
        unordered_set<string> dir(wordList.begin(), wordList.end());
        if (!dir.count(endWord)) {
            return 0;
        }
        int res = 0;
        queue<string> word_queue;
        word_queue.push(beginWord);
        while (!word_queue.empty()) {
            int m = word_queue.size();
            res++;
            for (int i = 0; i < m; i++) {
                auto ele = word_queue.front();
                word_queue.pop();
                if (ele == endWord) {
                    return res;
                }
                add_queue(word_queue, ele, dir);
            }
        }
        return 0;
    }
    void add_queue(queue<string> &word_queue, string &word,
                   unordered_set<string> &dir) {
        for (int i = 0; i < word.size(); i++) {
            char letter = word[i];
            for (char ch = 'a'; ch <= 'z'; ++ch) {
                word[i] = ch;
                if (dir.count(word)) {
                    word_queue.push(word);
                    dir.erase(word);
                }
            }
            word[i] = letter;
        }
    }
};