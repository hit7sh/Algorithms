// Author :: <Hitesh_Saini>
#include<bits/stdc++.h>

#define __speed() ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define tt int t;for(cin>>t; t--; )
#define f0(i, n) for(i = 0; i < int(n); i++)
#define PB push_back

using namespace std;
using vi = vector<int>;
const int mod = 1e9+7,mxN = 1e5+5;

int i, n, x, endnode;
vi adj[mxN];
int vis[mxN];
int prv[mxN];
bool dfs(int node, int par)
{
	vis[node]=1;

	for(int child:adj[node])
	{
		if(!vis[child])
		{
			prv[child]=node;
			if(dfs(child, node))
				return true;
		}
		else if(child!=par)
			{prv[child]=node,endnode=par;return true;}
	}
	return false;
}
void solve(){
	cin >> n;
	int u, v;
	f0(i, n)
		adj[i].clear(), vis[i]=0, prv[i]=0;
	prv[0]=-1;
	f0(i, n)
		cin >> u >> v, u--, v--, adj[u].PB(v), adj[v].PB(u);
	dfs(0, -1);
	vi cycle;
	while(true){
		cycle.PB(endnode);
		endnode=prv[endnode];
		if(cycle.size()>1&&cycle[0]==cycle.back())
			break;
	}
	cycle.pop_back();
	for(int x:cycle)
		cout << x << ' ';
	cout << endl;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin); 
		freopen("output.txt", "w", stdout);
	#endif
    __speed();
    tt solve();
    return 0;
}
