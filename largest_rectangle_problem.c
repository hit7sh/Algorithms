/*
A histogram is a polygon composed of a sequence of rectangles aligned at a common base line. 
The rectangles have equal widths but may have different heights. 
For example, the figure on the left shows the histogram that consists of rectangles with 
the heights 2, 1, 4, 5, 1, 3, 3, measured in units where 1 is the width of the rectangles.
The area of maximum rectangle is 4*2=8

Output on a single line the area of the largest rectangle in the specified histogram. 
Remember that this rectangle must be aligned at the common base line.
*/


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
