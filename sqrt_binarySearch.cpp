#include<bits/stdc++.h>
using namespace std;

int main(){
    float n, lb = 0, rb, root = 0;
    cin>>n,rb = n;
    while(1){
        root = (lb+rb)/2;
        if(fabs(n-root*root) < 1e-5)
            break;
        if(root*root > n)
            rb = root;
        else
            lb = root;
    }
    cout<<root;
    return 0;
}
