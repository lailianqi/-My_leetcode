#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

// 第二遍的时候发现第一遍写的答案没标出官方题解的网址 所以加上网址
// https://leetcode.com/problems/next-permutation/discuss/13867/A-simple-algorithm-from-Wikipedia-with-C++-implementation-(can-be-used-in-Permutations-and-Permutations-II)
class Solution {
  public:
    void nextPermutation(vector<int> &nums) {
        int k = -1;
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                k = i;
                break;
            }
        }
        if (k == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        int aim = -1;
        for (int i = nums.size() - 1; i > k; i--) {
            if (nums[i] > nums[k]) {
                aim = i;
                break;
            }
        }
        swap(nums[k], nums[aim]);
        reverse(nums.begin() + k + 1, nums.end());
    }
};

// 第二遍刷的时候 上面的改写版
// 题解来自sp大神
// https://leetcode.com/problems/next-permutation/discuss/13921/1-4-11-lines-C++
class Solution_0 {
  public:
    void nextPermutation(vector<int> &nums) {
        auto it = is_sorted_until(nums.rbegin(), nums.rend());
        if (it != nums.rend()) {
            swap(*it, *upper_bound(nums.rbegin(), it, *it));
        }
        reverse(nums.rbegin(), it);
    }
};

// sp大神的第二种解法
// https://leetcode.com/problems/next-permutation/discuss/13921/1-4-11-lines-C++
class Solution_1 {
  public:
    void nextPermutation(vector<int> &nums) {
        int index = nums.size() - 1;
        while (index > 0 && nums[index - 1] >= nums[index]) {
            index--;
        }
        reverse(nums.begin() + index, nums.end());
        if (index > 0) {
            int k = index--;
            while (nums[k] <= nums[index]) {
                k++;
            }
            swap(nums[index], nums[k]);
        }
    }
};
/*
题解:
按照字典序的定义不难推出，正序，是一组排列中最小的排列，而逆序，则是一组排列中最大的排列。

从字典序的定义出发，我们可以看到，n个元素的排列全排列中，从给定排列P
求解下一排列P+1
，假设两个排列有前k位是相同的(0<=k<=n)，那么我们只需要在后面n-k个元素的排列
P(n-k)中求得下一个排列即可。

既然我们关心的是后面 n-k位的排列，那么不妨开开脑洞，从后向前考察排列。



首先我们举一个比较极端的例子：排列 1 2 3 4 5

很显然，这是一个正序排列（递增序列），因此这是这几个数字所组成的排列中最小的排列，记为P1.

现在我们要求出P2，P2是 1 2 3 5 4.
我们可以看到，P2的前三位和P1的前三位的排列完全相同，唯一的变化是最后两位颠倒顺序，这一顺序的颠倒有何玄机呢？——使得最后两位从正序的
4 5 变成了逆序的 5 4.

接着求P3.P3是 1 2 4 3 5.
我们看到，最后两位已经是逆序，不可能有字典序更大的排列，因此必须考虑更多的位，在后3个元素中，3
5 4 显然不是逆序，因此一定存在字典序更大的排列方式，我们由此确定了n-k==3



我们现在要在 3 5 4 中求得下一个排列，3 5 4 不是一个逆序，是因为 3
后面有元素大于3
。我们要在大于3的数字中选择最小的那个，和3交换，因为这样可以保证得到最小的首位元素。对于这个例子，我们选择将3和4进行交换，而不是3
和 5，这样得到的首位元素是4. 现在我们得到了排列 4 5 3 。

显然，4 5 3 并不是我们想要的下一个排列，下一个排列是 4 3 5.
观察区别，不难看出，首位元素一定是4，但是5 3 这个子排列是一个逆序排列。

为什么会是逆序排列？

因为我们寻找的时候就以是不是逆序为分割点，3 恰好是第一个非逆序的元素，而4作为与3
交换的元素，又比3要大，因此交换后得到的 5 3 一定是逆序的排列。

逆序排列没有下一排列，但是将逆序排列反向后，我们就得到了对应的正序排列，而正序排列是当前元素所能形成的最小排列，因此，4
3 5 是4 为首位元素所能形成最小排列，而前3 位没有变化，故我们得到了下一排列P3.

另外，大于3的最小元素，即4 ，也是第一个大于3的元素，因为 5 4 是个逆序排列。



更一般地，例如对于可重集排列 1 2 3 7 6 5 2 1

我们首先寻找第一个非逆序元素，这里是3，然后从后向前寻找第一个大于3的元素，这里是5，交换，得到
5 7 6 3 2 1
的子排列，然后反向，即可得到下一排列。如果没有找到第一个非逆序元素，那么说明该排列已经是最大排列。
*/