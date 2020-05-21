#include<iostream>
using namespace std;

int main(){
    int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, i, mid, lb = 0 ,rb = 10 , number_to_search = 7;
    
    while(lb<rb){
        mid=(lb + rb)/2;
        
        if(number_to_search<=A[mid])
            rb = mid;
        else
            lb = mid + 1;
    }
    
    cout<<"Number to search :: "<<number_to_search;
    
    cout<<"\nINDEX :: ";
    for(i=0;i<10;i++)
        cout << i << " ";
        
    cout << "\nNUMS  :: ";
    for(i=0;i<10;i++)
        cout << A[i] << " ";
        
    cout << "\n7 is at index: " << lb;          //lb or rb both are same..
    cout<<"\nlb = " << lb << ", rb = " << rb;
    
    return 0;
}
