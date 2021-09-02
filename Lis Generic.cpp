#include<bits/stc++.h>
using namespace std;

template<typename T>
int lis(const vector<T>& A) {
    int n = A.size();
    T dp[n + 1];
    memset(dp, 0x3f, sizeof(dp));
    memset(dp, 0xc0, sizeof(T));
    const T INF = dp[1];


    // dp[i] = last element of increasing subsequence of length i
    for (int i = 0; i < n; i++) {
        int j = upper_bound(dp, dp + n + 1, A[i]) - dp;
        if (dp[j-1] < A[i] && A[i] < dp[j])
            dp[j] = A[i];
    }

    int ans = 0;
    for (int i = 0; i <= n; i++) {
        if (dp[i] < INF)
            ans = i;
    }
    return ans;
}
