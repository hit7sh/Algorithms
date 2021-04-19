#include<bits/stdc++.h>
using namespace std;

vector<int64_t> segmentedSieve(int64_t L, int64_t R) { // R - L + 1 <= 1e7
    int64_t i, j;
    vector<int64_t> P;
    vector<bool> isPrime(R - L + 1, true);

    for(i = 2; i * i <= R; i++){
        int64_t j = max(i + i, ((L + i - 1) / i) * i);

        for(; j <= R; j += i)
            isPrime[j - L] = false;
    }

    for(i = L; i <= R; i++)
        if(i - 1 && isPrime[i-L])
            P.emplace_back(i);

    return P;
}
