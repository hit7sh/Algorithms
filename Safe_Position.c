/* 
  Problem: There are n(INPUT) captured prisoners standing in a circular queue positioned 1 to n
           A Guy hops in front of them.
           He starts shooting from s(INPUT) and skips one ALIVE then kills NEXT ALIVE and so on\
           till there is only one guy left who is set free.
           
  Task :   You are one of the prisoners
           Your task is to stand in a safe postion such that you are not killed.
           You know the starting postiton and number of prisoners.
  Example: n=5 s=1
           1 2 3 4 5
           - 2 3 4 5    first 1 is killed
           - 2 - 4 5    skip one alive i.e 2 and kill next i.e 3
           - 2 - 4 -    process continues killed 5
           - 2 - - -    Dont kill the one who is already killed, Here we skipped next ALIVE after 5 in circular Queue i.e 4
           Hence 2 is the safe position.
*/

#include<stdio.h>
int main()
{
	int n,s,i,c=0;
	scanf("%d %d",&n,&s);
	int A[n+1];
	for(i=1;i<=n;i++)A[i]=i;

	for(i=s;;)
	{
		int p=i%n==0?n:i%n;
		A[p]=0;
		if(++c>=n-1)break;

		for(int x=0;x<2;x++)
		do p=(++i)%n==0?n:i%n;
		while(A[p]==0);           // finding next alive
	}
	for(i=0;++i<=n;)if(A[i]!=0)printf("%d",i);  //Printing the safe position
    return 0;
}
