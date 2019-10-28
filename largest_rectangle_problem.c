#include<stdio.h>
int main()
{
    int n,i,j,c,max;
    scanf("%d",&n);int A[n];
    for(i=0;i<n;i++)scanf("%d",&A[i]);
    max=A[i-1];
    for(i=0;i<n;i++)
    {
        c=1;
        j=i;
        while(A[--j]>=A[i]&&j>-1)
        c++;
        j=i;
        while(A[++j]>=A[i]&&j<n)
        c++;
        if((A[i]*c)>max)max=A[i]*c;
    }
    printf("\n%d",max);
    return 0;
}
