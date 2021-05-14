//
// Created by dev on 5/10/21.
//
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int n = encoded.size()+1;
        vector<int> perm(n, 0);
        int total = 0;
        for (int i = 1; i <= n; ++i) {
            total ^= i;
        }
        int odd = 0;
        for (int i = 1; i < n-1; i += 2) {
            odd ^= encoded[i];
        }
        perm[0] = total ^ odd;
        for (int i = 1; i < n; ++i) {
            perm[i] = perm[i-1] ^ encoded[i-1];
        }
        return perm;
    }
};

