#include<bits/stdc++.h>
using namespace std;

int find_pivot(int A[],int n){
    int lb=0,rb=n-1,pivot=0,mid;
    while(lb<=rb){
        mid=lb+(rb-lb)/2;
        if(A[mid]>A[mid+1]){
            pivot=mid+1;
            break;
        }
        if(A[lb]>A[mid])
            rb=mid-1;
        else
            lb=mid+1;
    }
    return pivot;
}

void b_search(int A[],int n,int ns,int pivot){
    int lb=0,rb=n-1,mid;
    if(ns<=A[n-1])
        lb=pivot;
    else
        rb=pivot-1;
    while(lb<=rb){
        mid=lb+(rb-lb)/2;
        if(A[mid]==ns){
            cout<<"Number is at "<<mid+1;return;
        }
        if(ns>A[mid])
            lb=mid+1;
        else
            rb=mid-1;
    }
    cout<<"NO";
}

int main(){
    int n;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++)
        cin>>A[i];
    int ns;
    cin>>ns;
    b_search(A,n,ns,find_pivot(A,n));
    return 0;
}
