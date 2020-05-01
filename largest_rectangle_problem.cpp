/*
A histogram is a polygon composed of a sequence of rectangles aligned at a common base line. 
The rectangles have equal widths but may have different heights. 
For example, the figure on the left shows the histogram that consists of rectangles with 
the heights 2, 1, 4, 5, 1, 3, 3, measured in units where 1 is the width of the rectangles.
The area of maximum rectangle is 4*2=8

Output on a single line the area of the largest rectangle in the specified histogram. 
Remember that this rectangle must be aligned at the common base line.
*/

ll i,n,h,ans=INT_MIN,lh,lp,A[100000];
int main() {
    cin>>n;
	f0(i,n)
	    cin>>A[i];
	A[n]=0;
	stack<int>ps, hs;
	f0(i,n+1){
	    h=A[i];
	    if(hs.empty() || h> hs.top())
	    ps.push(i),hs.push(A[i]);
	    else if(h<hs.top()){
	        while(!hs.empty() and h<hs.top()){
	            lh=hs.top();lp=ps.top();
	            hs.pop();ps.pop();
	            ans=max(ans, lh*(i-lp));
	        }
	        hs.push(h);
	        ps.push(lp);
	    }
	}
	cout<<ans<<endl;
	return 0;
}
