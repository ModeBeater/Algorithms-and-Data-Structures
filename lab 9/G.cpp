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
    string s;
    cin >> s;
    vector<int> p = prefix_function(s);
    cout << s.size() - p[p.size() - 1] << endl;
}