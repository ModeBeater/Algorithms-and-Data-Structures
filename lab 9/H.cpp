#include <iostream>
#include <vector>

using namespace std;
int max_pos = 0;
vector<int> a;
vector<int> prefix_function (string s) {
    int cnt = 0;
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
        // cout << j << " ";
		v[i] = j;
	}
	return v;
}

int main(){
    string s;
    cin >> s;
    vector<int> ans = prefix_function(s);
    int cnt = 0;
    for(int i = 1; i < ans.size(); i++){
        if(ans[i - 1] != 0){
            int a = i - ans[i - 1];
            if(i % a == 0 && (i / a) % 2 == 0){
                cnt++;
            }
        }
    }
    cout << cnt;
}