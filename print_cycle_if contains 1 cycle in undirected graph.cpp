    int n;
		cin >> n;
		vector<set<int>> g(n);
		for (int i = 0; i < n; ++i) {
			int x, y;
			cin >> x >> y;
			--x, --y;
			g[x].insert(y);
			g[y].insert(x);
		}
		vector<int> val(n, 1);
		queue<int> leafs;
		for (int i = 0; i < n; ++i) {
			if (g[i].size() == 1) {
				leafs.push(i);
			}
		}
	while(!leafs.empty())
		print(leafs.front()), leafs.pop();
