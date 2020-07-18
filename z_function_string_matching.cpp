#include<bits/stdc++.h>
using namespace std;

vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

int main(){
    string st, pat;
    cin >> st >> pat;
    string r = pat + "#" + st;
    vector<int> z(r.length());
    z = z_function(r);
    vector<int>pos;
    for(int i=1; i<r.length(); ++i)
        if(z[i] == pat.length())
            pos.push_back(i-pat.length()-1);
    
    for(int x:pos)
        cout << x << ' ';
        
    return 0;
}
