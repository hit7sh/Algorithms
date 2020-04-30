/**
A random question:
Input a string containing brackets:
( ) – round brackets,
< > - angular brackets,
{ } - curly brackets,
[ ] - square brackets.

Your task is to check whether the input is a balanced system of brackets or not.

Example:
INPUT: <<[{()}]>>
OUTPUT: true

INPUT: <>{}[]()
OUTPUT: true

INPUT: ][][][{}(<>)]
OUTPUT: false

INPUT: [{<>}]([)]
OUTPUT: false

INPUT: <><<({[][]})>><>
OUTPUT: true

INPUT: {{{{{{{<<<<<[[[(({{{{}}}}]]]>>>>>}}}}}}}([])
OUTPUT: false

INPUT: (((((<{}>)))))[{[{[{[]}]}]}]
OUTPUT: true
*/

#include <bits/stdc++.h>
#define f0(i,n) for(i=0;i<n;i++)
#define f1(i,n) for(i=1;i<=n;i++)
using namespace std;

int main() {
	string st;bool flag = true;
	cin>>st;
	stack<char>S;
	unordered_map<char, char>M={{'{','}'},{'(',')'},{'<','>'},{'[',']'}};

	for(char x: st)
	    if(M.find(x)!=M.end())
	        S.push(x);
	    else if(!(S.empty()) and M[S.top()]==x)
	            S.pop();
	            
	cout<<(S.empty()?"YES":"NO");
	return 0;
}
