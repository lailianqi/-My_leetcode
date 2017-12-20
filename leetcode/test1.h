#include <cstring>
#include <vector>
#include <iostream>
#include <ctime>
using namespace std;
//从一段中均匀选取点
int ComPressToOne(vector<int> &pDataIn, int start, int end,
                  vector<int> &pDataOut) {
    int nlenIn = end - start + 1;
    int nlenOut = pDataOut.size();
    int k = 0;
    int kBefore = 0;
    int k1 = 0;
    vector<int> temp(nlenOut, 0);
    double BiLi = (double)nlenOut / (double)nlenIn;
    int i = start;
    for (i = start; i <= end; i++) {
        k = (int)((i - start) * BiLi);
        if (temp[k] <= pDataIn[i]) {
            temp[k] = pDataIn[i];
        }
    }
    for (i = 0; i < nlenOut; i++) {
        pDataOut[i] = temp[i];
    }
    return k;
}

void test() {
    vector<int> input(8192, 0);
    vector<int> output(1024, 0);
    for (int i = 0; i < input.size(); i++) {
        input[i] = i;
    }
    ComPressToOne(input, 0, 8191, output);
    for (int i = 0; i < output.size(); i++) {
        cout << output[i] << endl;
    }
}

void test1() {
    clock_t start, finish;
    vector<vector<double>> ves(10, vector<double>(8192, 5));
    vector<vector<double>> ves1(10, vector<double>(8192, 5));
    start = clock();
    //cout << start << endl;
    for (int k = 0; k < 10; k++) {
        ves1 = ves;
        //cout << "HW .... " << endl;
    }
    finish = clock();
    //cout << finish << endl;
    cout << (finish - start) << "/" << CLOCKS_PER_SEC << " (s) " << endl;
}
