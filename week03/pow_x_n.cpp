//
// Created by kurumi on 2021/4/16.
//
#include <iostream>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        return n > 0 ? powHelper(x, N) : 1.0 / powHelper(x, -N);
    }
    double powHelper(double x, long long n) {
        if (n == 0) return 1;
        double sub = myPow(x, n/2);
        double value = sub * sub;
        if (n % 2 == 1) {
            value *= x;
        }
        return value;
    }
};

int main() {
    Solution sol;
    cout << sol.myPow(2.0, -10) << endl;
}


