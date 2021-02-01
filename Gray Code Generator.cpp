void generateCode(int n)
{
	
	vector<string> a, temp;
	a.push_back("0");
	a.push_back("1");

	for(int i=0;i<n-1;i++){
		for(int j=0;j<a.size();j++){
			temp.push_back("0"+a[j]);
		}
		for(int j=a.size()-1;j>=0;j--){
			temp.push_back("1"+a[j]);
		}
		a=temp;
		temp.clear();
	}

	for (string& g:a)
	  cout << g << endl;
}
