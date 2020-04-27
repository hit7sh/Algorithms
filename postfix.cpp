#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
    int tt;cin>>tt;
    while(tt--)
    {
        string st;cin>>st;
        stack<int>S;
        for(char x:st)
        {
            if(islower(x))
                cout<<x;
            else if(x==')')
            {cout<<(char)S.top();S.pop();}
            else if(x=='(')
                continue;
            else S.push(x);
        }
        cout<<endl;
    }
    return 0;
}
