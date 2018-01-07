// #include "498.h"
#include <iostream>
#include <string>
using namespace std;
int main() {
    string s = "aabcd";
    string ac = "abc";
    cout << s.find_first_of(ac.c_str());
    return 0;
}