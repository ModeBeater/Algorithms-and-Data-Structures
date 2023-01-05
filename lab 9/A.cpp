#include <iostream>
#include <vector>
#include <set>
using namespace std;
int max1 = 0;
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
        if(j > max1){
            max1 = j;
        }
		v[i] = j;
	}
	return v;
}

int main(){
	string s,t;
	cin >> s >> t;
    vector<int> ans = prefix_function(t + "#" + s);
    if(max1 == t.size()){
        cout << 1;
        return 0;
    }
    max1 = 0;
    int b = t.size() / s.size();
    string m = s;
    while(b--){
        s += m;
    }
    s += m;
    ans = prefix_function(t + "#" + s);
    if(max1 != t.size()){
        cout << -1;
        return 0;
    }
    s = m;
	ans = prefix_function(t + "#" + s);
    if(ans[ans.size() - 1] <= t.size()){
        int a = 0;
        if(ans[ans.size() - 1] > 0){
            a++;
        }
        a += (t.size() - ans[ans.size() - 1]) / s.size();
        if(t.size() - ans[ans.size() - 1] % s.size() != 0){
            a++;
        }
        cout << a;  
    }
}