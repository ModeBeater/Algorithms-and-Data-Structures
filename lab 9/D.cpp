#include <iostream>
#include <vector>
#include <algorithm>
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
    s[0] = tolower(s[0]);
    vector<int> ans = prefix_function(s);
    int max1 = 0;
    vector<pair<string,int> > v;
    int n;
    cin >> n;
    while(n--){
        string t;
        cin >> t;
        t[0] = tolower(t[0]);
        vector<int> pi = prefix_function(t + "#" + s);
        v.push_back(make_pair(t,pi[pi.size() - 1]));
        if(pi[pi.size() - 1] > max1 && pi[pi.size() - 1] != 0){
            max1 = pi[pi.size() - 1];
        }
    }
    vector<string> a;
    for(int i = 0; i < v.size(); i++){
        if(v[i].second == max1 && max1 != 0){
            v[i].first[0] = toupper(v[i].first[0]);
            a.push_back(v[i].first);
        }
    }
    cout << a.size() << endl;
    for(int i = 0; i < a.size(); i++){
        cout << a[i] << endl;
    }
}