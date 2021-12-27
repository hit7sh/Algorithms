#include<bits/stdc++.h>
using namespace std;


const int INF = 1e9;

int main() {
  int n = 4;
  vector<int> A = {6, 5, 7, 3, 9};

  vector<vector<int>> dp(n + 1, vector<int>(n + 1));
  // ....i....k...j....
  // dp[i][j] = minimum cost to multiply matrix i till j :: min_cost(i * a * b * c * j)

  for (int w = 2; w <= n; w++) {
    for (int i = 1; i + w - 1 <= n; i++) {
      int j = i + w - 1;
      dp[i][j] = INF;
      for (int k = i; k < j; k++) {
        dp[i][j] = min(dp[i][j], A[i - 1] * A[k] * A[j] + dp[i][k] + dp[k + 1][j]);
      }
    }
  }

  vector<vector<bool>> vis(n + 1, vector<bool>(n + 1));
  vector<int> F(n + 1), B(n + 1);
  queue<pair<int, int>> q;
  q.push({1, n});

  while (!q.empty()) { // applying bfs to recover sequence
    auto f = q.front(); q.pop();
    int x = f.first, y = f.second;
    // cout << x << y << '\n';
    if (y - x + 1 == 1 || vis[x][y]) continue;
    ++F[x], ++B[y];
    vis[x][y] = 1;
    // (x...y)

    int r = dp[x][y];

    for (int j = x; j < y; j++) {
      int v = A[x - 1] * A[j] * A[y];
      if (r == dp[x][j] + v + dp[j + 1][y]) {
        q.push({x, j});
        q.push({j + 1, y});
      }
    }
  }

  string ans = "*PQRS";
  
  for (int i = 1; i <= n; i++) {
    cout << string(F[i], '(') << ans[i] << string(B[i], ')');
  }
  cout << " = " << dp[1][n] << '\n';
  return 0;
}
