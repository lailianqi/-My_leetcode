#include <algorithm>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
// 自己的第一种方案 成功ac
// leetcode上面的答案思想和写法和我的方案基本上一模一样
// https://leetcode.com/problems/top-k-frequent-words/discuss/108346/My-simple-Java-solution-using-HashMap-and-PriorityQueue-O(nlogk)-time-and-O(n)-space
// https://leetcode.com/problems/top-k-frequent-words/discuss/108366/O(nlog(k))-Priority-Queue-C++-code
class Solution {
  public:
    vector<string> topKFrequent(vector<string> &words, int k) {
        unordered_map<string, int> dir;
        vector<string> res;
        auto comp = [](pair<string, int> &a, pair<string, int> &b) {
            return a.second == b.second ? a.first < b.first
                                        : a.second > b.second;
        };
        priority_queue<pair<string, int>, vector<pair<string, int>>,
                       decltype(comp)>
            pq(comp);
        for (int i = 0; i < words.size(); i++) {
            dir[words[i]]++;
        }
        int counter = 0;
        for (auto element : dir) {
            counter++;
            pq.push(element);
            if (counter > k) {
                pq.pop();
            }
        }
        while (!pq.empty()) {
            res.push_back(pq.top().first);
            pq.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// 上面解法的改进版 参考自LeetCode
// https://leetcode.com/problems/top-k-frequent-words/discuss/108359/Java-HashMap-and-MaxHeap-O(nlogn)
class Solution_0 {
  public:
    vector<string> topKFrequent(vector<string> &words, int k) {
        unordered_map<string, int> dir;
        vector<string> res;
        auto comp = [](pair<string, int> &a, pair<string, int> &b) {
            return a.second == b.second ? a.first > b.first
                                        : a.second < b.second;
        };
        priority_queue<pair<string, int>, vector<pair<string, int>>,
                       decltype(comp)>
            pq(comp);
        for (int i = 0; i < words.size(); i++) {
            dir[words[i]]++;
        }
        for (auto element : dir) {
            pq.push(element);
        }
        while (res.size() < k) {
            res.push_back(pq.top().first);
            pq.pop();
        }
        return res;
    }
};

// 最牛逼的做法 还是堆排序 答案来自LeetCode
// https://leetcode.com/problems/top-k-frequent-words/discuss/108346/My-simple-Java-solution-using-HashMap-and-PriorityQueue-O(nlogk)-time-and-O(n)-space

// class Solution_1 {
//   public
//     List<String> topKFrequent(String[] words, int k) {
//         HashMap<String, Integer> map = new HashMap<>();
//         int max = 0;
//         for (String w : words) {
//             map.put(w, map.getOrDefault(w, 0) + 1);
//             max = Math.max(max, map.get(w));
//         }
//         List<String>[] bucket = new ArrayList[max + 1];
//         for (Map.Entry<String, Integer> entry : map.entrySet()) {
//             int fre = entry.getValue();
//             if (bucket[fre] == null) {
//                 bucket[fre] = new ArrayList<>();
//             }
//             bucket[fre].add(entry.getKey());
//         }
//         List<String> res = new ArrayList<>();
//         for (int i = max; i >= 0 && res.size() < k; i--) {
//             if (bucket[i] != null) {
//                 Collections.sort(bucket[i]);
//                 res.addAll(bucket[i]);
//             }
//         }
//         return res.subList(0, k);
//     }
// }

// python的解法更快 来自LeetCode
// class Solution:
//     def topKFrequent(self, words, k):
//         counts = collections.Counter(words)
//         items = list(counts.items())
//         items.sort(key=lambda item:(-item[1],item[0]))
//         return [item[0] for item in items[0:k]]