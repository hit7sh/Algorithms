vector <int> kmp(string &in) {
	int m = in.size(), cpref = 0;
	vector <int> dp(m, 0);
	
	for(int i = 1; i < (int)in.size(); ++i) {
		while(cpref > 0 && in[cpref] != in[i])
			cpref = dp[cpref - 1];
		
		if(in[cpref] == in[i])
			++cpref;
		dp[i] = cpref;
	}
	
	return dp;
}
