#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

void GetNext(string p, vector<int> &next) {
    int m = p.size(), k = -1, j = 0;
    next[0] = -1;
    while (j < m - 1) {
        if (k == -1 || p[j] == p[k]) {
            k++, j++;
            next[j] = k;
        } else {
            k = next[k];
        }
    }
}
// http://blog.csdn.net/v_july_v/article/details/7041827
//优化过后的next 数组求法
void GetNextval(char *p, int next[]) {
    int pLen = strlen(p);
    next[0] = -1;
    int k = -1;
    int j = 0;
    while (j < pLen - 1) {
        // p[k]表示前缀，p[j]表示后缀
        if (k == -1 || p[j] == p[k]) {
            ++j;
            ++k;
            //较之前next数组求法，改动在下面4行
            if (p[j] != p[k])
                next[j] = k; //之前只有这一行
            else
                //因为不能出现p[j] = p[ next[j ]]，所以当出现时需要继续递归，k =
                // next[k] = next[next[k]]
                next[j] = next[k];
        } else {
            k = next[k];
        }
    }
}

int KmpSearch(char *s, char *p) {
    int i = 0;
    int j = 0;
    int sLen = strlen(s);
    int pLen = strlen(p);
    while (i < sLen && j < pLen) {
        //①如果j = -1，或者当前字符匹配成功（即S[i] == P[j]），都令i++，j++
        if (j == -1 || s[i] == p[j]) {
            i++;
            j++;
        } else {
            //②如果j != -1，且当前字符匹配失败（即S[i] != P[j]），则令 i 不变，j
            //= next[j]
            // next[j]即为j所对应的next值
            j = next[j];
        }
    }
    if (j == pLen)
        return i - j;
    else
        return -1;
}