#include<bits/stdc++.h>
#include<stdio.h>
#define ll long long
#define eb(n) emplace_back(n)
#define debug(x) cout<<"#x"<<" is "<<x<<endl
#define INF 10000000000
#define mod 1000000007
#define endl "\n"
#define max(a,b) ((a>b)?(a):(b))
#define min(a,b) ((a<b)?(a):(b))
#define fo(i,n) for(i=0;i<n;i++)
#define f1(i,n) for(i=1;i<=n;i++)
using namespace std;
void sort_str(string& st)
{
    ll i,id=0,c_lw[26]={0},c_up[26]={0};
    for(char x:st)
        if(x>96)(c_lw[x-'a'])++;
        else (c_up[x-'A'])++;
    
    fo(i,26)
    {
        while(c_up[i]--)
            st[id++]=(i+'A');
        while(c_lw[i]--)
            st[id++]=(i+'a');
    }
}
//-------------------------------------------------
/* 
Recursive function to print all possible permutations
of a string. It takes two arguments: count[] to store
frequency of A[i], level to sore level of recursion.
*/
int l,no=0;string st,res="";
void permute(int count[],int level)
{
    if(level==l)cout<<(++no)<<"-> "<<res<<endl;
    
    for(int i=0;i<l;i++)
    {
        if(count[i]==0)
        continue;
        
        res[level]=st[i];
        count[i]--;
        permute(count,level+1);
        count[i]++;
    }
}
//-------------------------------------------------
int main()
{   
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>st;
    sort_str(st);
    l=st.length();
    int c[l]={0},id=0;
    map<char,int>m;res=st;

    for(char x:st) m[x]++;
    for(auto x:m) c[id++]=x.second;

    permute(c,0);
    return 0;
}
