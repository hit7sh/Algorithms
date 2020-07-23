#include<bits/stdc++.h>
using namespace std;

vector<int>adj[20];
bool vis[20];
vector<int>tps;

void dfs(int v) {
    vis[v] = true;
    
    for (int u : adj[v])
        if (!vis[u])
            dfs(u);
            
    tps.push_back(v);
}

int main() {
	int n, m, u, v;
	cin >> n >> m;
  
	while(m--)
		cin >> u >> v, u--, v--, adj[u].push_back(v);
    
	for(u=0;u<n;u++)
		if(!vis[u])
			dfs(u);
      
	reverse(tps.begin(), tps.end());
  
	for(int x: tps)
		cout << x+1 << ' ';
    
  return 0;
}
