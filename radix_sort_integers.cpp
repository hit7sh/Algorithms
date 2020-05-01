// Author :: <Hitesh_Saini>
#include<bits/stdc++.h>

#define speed() ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define foreachrev(i,t) for(typeof(t.begin()) i = t.rbegin(); i!=t.rend(); i++)
#define foreach(i,t) for(typeof(t.begin()) i = t.begin(); i!=t.end(); i++)
#define fo(i, start, end)  for(i = start; i <= end; i++)
#define fro(i, start, end) for(i = start; i >= end; i--)
#define debug(x) cout<<#x<<" is "<<x<<endl
#define f0(i, n) for(i = 0; i < n; i++)
#define f1(i, n) for(i = 1; i<= n; i++)
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
const int mod=1e9+7;

void radix_sort(vi &A){
    int i,n=floor(log(*max_element(A.begin(),A.end()))+1),j; //no. of digits in max number
    n=(n+1)/2;
    f0(i,n){
        vi count[100];
        for(int x:A)
            count[int(x/pow(10,i))%100].eb(x);

        A.clear();
        
        f0(j,100)
            for(int x:count[j])
                A.eb(x);
    }
}

int main() {
    int len,i,t;cin>>len;
    vi pos,neg;
    f0(i,len){
        cin>>t;
        if(t<0)
            neg.eb(t);
        else
            pos.eb(t);
    }
    if(!neg.empty())
        radix_sort(neg);
    if(!pos.empty())
        radix_sort(pos);
        
    deque<int>ans;
    for(int x:neg)
        ans.pf(x);
    for(int x:pos)
        ans.pb(x);
    for(int x:ans)
        cout<<x<<" ";
    return 0;
}
