#include <algorithm>
#include <iterator>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Employee {
  public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
// 自己的第一种解法 成功ac 是一道好题 所以加上了标题
class Solution {
  public:
    int getImportance(vector<Employee *> employees, int id) {
        unordered_map<int, Employee *> dir;
        for (int i = 0; i < employees.size(); i++) {
            dir[employees[i]->id] = employees[i];
        }
        return helper(dir, id);
    }
    int helper(unordered_map<int, Employee *> &dir, int id) {
        int res = dir[id]->importance;
        for (int i = 0; i < dir[id]->subordinates.size(); i++) {
            res += helper(dir, dir[id]->subordinates[i]);
        }
        return res;
    }
};

// 上面的改写版 使用了STL
// https://leetcode.com/problems/employee-importance/discuss/112593/C++-DFS-using-STL
class Solution_00 {
  public:
    int getImportance(vector<Employee *> employees, int id) {
        unordered_map<int, Employee *> dir;
        transform(
            employees.begin(), employees.end(), inserter(dir, dir.end()),
            [&](Employee *element) { return make_pair(element->id, element); });
        return helper(dir, id);
    }
    int helper(unordered_map<int, Employee *> &dir, int id) {
        return dir[id]->importance +
               accumulate(
                   dir[id]->subordinates.begin(), dir[id]->subordinates.end(),
                   0, [&](int sum, int id) { return sum + helper(dir, id); });
    }
};
// LeetCode上面BFS的解法
// https://leetcode.com/problems/employee-importance/discuss/112587/Java-HashMap-bfs-dfs
class Solution_0 {
    // public int getImportance(List<Employee> employees, int id) {
    //     int total = 0;
    //     Map<Integer, Employee> map = new HashMap<>();
    //     for (Employee employee : employees) {
    //         map.put(employee.id, employee);
    //     }
    //     Queue<Employee> queue = new LinkedList<>();
    //     queue.offer(map.get(id));
    //     while (!queue.isEmpty()) {
    //         Employee current = queue.poll();
    //         total += current.importance;
    //         for (int subordinate : current.subordinates) {
    //             queue.offer(map.get(subordinate));
    //         }
    //     }
    //     return total;
    // }
};
