#include <iostream>
#include <vector>

using namespace std;
int max_pos = 0;
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
        if(j != 0){
            max_pos = i;
        }
		v[i] = j;
	}
	return v;
}

int main(){
    string s;
    cin >> s;
    vector<int> ans = prefix_function(s);
    int cnt = 0;
    for(int i = 1; i <= max_pos; i++){
        if(ans[i] == 0){
            continue;
        }
        if((i + 1 - ans[i]) / 2 <= ans[i] / 2 && (i + 1) % 2 == 0 && i + 1 < s.size()){
            if(s.substr(0,(i + 1) / 2) == s.substr((i + 1) / 2, (i + 1) / 2)){
                cnt++;
            }
        }
    }
    cout << cnt;
}