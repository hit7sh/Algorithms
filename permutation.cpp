#include<bits/stdc++.h>
using namespace std;

int l,number;string temp;

void permutations(string st, int level=0){
    if(level==l-1)
        cout << ++number << ": " << st << endl;
    for(int i = level; i<l; i++)
        temp=st, swap(temp[level],temp[i]), permutations(temp,level+1);
}

int main(){
    l=4;
    permutations("ABCD");
    return 0;
}
