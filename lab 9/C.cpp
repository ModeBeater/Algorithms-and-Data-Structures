#include <iostream>
#include <vector>

using namespace std;

vector<int> prefix_function (string s) {
	int n = s.length();
	vector<int> v(n);
	for (int i = 1; i < n; i++) {
		int j = v[i - 1];
		while (j > 0 && s[i] != s[j]){
			j = v[j - 1];
		}
		if (s[i] == s[j]){
			j++;
		}
		v[i] = j;
	}
	return v;
}

int main(){
    string s,t;
    cin >> s >> t;
    vector<int> ans = prefix_function(s + "#" + t + t);
    for(int i = 0; i < ans.size(); i++){
		// cout << ans[i] << " ";
        if(ans[i] == s.size()){
            cout << i - 2 * s.size() << " ";
            return 0;
        }
    }
    cout << -1 << endl;
}