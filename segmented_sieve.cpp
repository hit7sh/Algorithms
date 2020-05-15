// Author :: <Hitesh_Saini>
#include<bits/stdc++.h>

#define speed() ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define foreachrev(i,t) for(typeof(t.rbegin()) i = t.rbegin(); i!=t.rend(); i++)
#define foreach(i,t) for(typeof(t.begin()) i = t.begin(); i!=t.end(); i++)
#define fo(i, start, end)  for(i = start; i <= end; i++)
#define fro(i, start, end) for(i = start; i >= end; i--)
#define findmax(v) *max_element(v.begin(), v.end())
#define _sum(a) accumulate(a.begin(), a.end(), 0)
#define cnt(v, x) count(v.begin(), v.end(), x)
#define _revsort(v) sort(v.rbegin(), v.rend())
#define debug(x) cout<<#x<<" is "<<x<<endl
#define _sort(v) sort(v.begin(), v.end())
#define f0(i, n) for(i = 0; i < n; i++)
#define f1(i, n) for(i = 1; i<= n; i++)
#define tt int tt;for(cin>>tt;tt--;)
#define eb(n) emplace_back(n)
#define pf(n) push_front(n)
#define pb(n) push_back(n)
#define endl "\n"

using namespace std;
using umii = unordered_map<int, int>;
using mii = map<int, int>;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
const int mod = 1e9+7;

bool si[100001];

void solve(){
    ll m,n,i,j;
    cin>>m>>n;
    memset(si,1,sizeof(si));
    for(i=2;i*i<=n;i++){
        ll fi=max(i+i, ((m+i-1)/i)*i);

        for(;fi<=n;fi+=i)
            si[fi-m]=0;
    }
    for(i=m;i<=n;i++)
        if(i-1 && si[i-m])
            cout<<i<<"\n";
    cout<<endl;
}

int main(){
    tt solve();
    return 0;
}
