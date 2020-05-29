#include<bits/stdc++.h>
using namespace std;

int l,number;string temp;

int lcs(string s1,string s2,int a=0,int b=0){
    if(a==s1.length()||b==s2.length())
        return 0;
    if(s1[a]==s2[b])
        return 1+lcs(s1,s2,a+1,b+1);
    else
        return max(lcs(s1,s2,a+1,b), lcs(s1,s2,a,b+1));
}

int main(){
    cout<< lcs("1234","123");
    return 0;
}
