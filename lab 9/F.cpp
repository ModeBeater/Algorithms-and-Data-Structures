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
    vector<int> p = prefix_function(t + "#" + s);
    vector<int> ans;
    for(int i = 0; i < p.size(); i++){
        if(p[i] == t.size()){
            ans.push_back(i - 2 * t.size() + 1);
        }
        // cout << p[i] << " ";
    }
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
}