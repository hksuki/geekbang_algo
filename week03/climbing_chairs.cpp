//
// Created by kurumi on 2021/4/14.
//
class Solution {
public:
    // 1.
    int climbStairs1(int n) {
        if (n <= 3) {
            return n;
        }
        int j, k, r;
        j = 2, k = 3, r = 0;
        for (int i = 4; i != n + 1; ++i) {
            r = j + k;
            j = k;
            k = r;
        }
        return r;
    }

    // 2. 超时
    int climbStairs2(int n) {
        if (n <= 3){
            return n;
        }
        else{
            return climbStairs(n-1) + climbStairs(n-2);
        }
    }

    // 3.
    int climbStairs3(int n) {
        int cache[n+1];
        cache[0] = 1;
        cache[1] = 1;
        for (int i = 0; i != n+1; ++i) {
            cache[i] = cache[i-1] + cache[i-2];
        }
        return cache[n];
    }
};

