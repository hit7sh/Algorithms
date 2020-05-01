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

vi sub;
int findNextIndex(int ub, int ele){
    int mid, ans=0, lb=0;
    while(lb<=ub){
        mid=lb+(ub-lb)/2;       //uses binary search to find index of first element>=current
        if(sub[mid]>=ele)
            ub=mid-1,ans=mid;
        else
            lb=mid+1;
    }
    return ans;
}

int main() {
    int i,n;
    cin>>n;
    int A[n];
    f0(i,n)
        cin>>A[i];
    sub.eb(A[0]);
    f1(i,n-1){
        if(A[i]>sub.back())
            sub.eb(A[i]);
        else
            sub[findNextIndex(sub.size()-1,A[i])]=A[i];
    }
    for(auto x:sub)
        cout<<x<<" ";
    return 0;
}
