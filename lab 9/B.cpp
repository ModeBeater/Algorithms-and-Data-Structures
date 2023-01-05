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
    int a;
    cin >> s >> a >> t;
    vector<int> p = prefix_function(s + "#" + t);
    vector<int> ans;
    for(int i = 0; i < p.size(); i++){
        if(p[i] == s.size()){
            ans.push_back(i - 2 * s.size() + 1);
        }
        // cout << p[i] << " ";
    }
    if(ans.size() >= a){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
}