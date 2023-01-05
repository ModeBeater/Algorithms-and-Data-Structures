#include <iostream>
#include <vector>
#define ll long long
using namespace std;


int main(){

    while(true){
        int n;
        cin >> n;
        if(n == 0){
            return 0;
        }
        string arr[n];
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        string s;
        cin >> s;
        ll p_pow[s.size()];
        ll p = 31;
        p_pow[0] = 1; 
        for (int i = 1; i < s.size(); i++) {
            p_pow[i] = p_pow[i - 1] * p;
        }
        vector<ll> hs(s.size());
        for (int i = 0; i < s.size(); ++i) {
            hs[i] = (s[i] - 96) * p_pow[i];
            if (i > 0) hs[i] += hs[i - 1];
        }
        vector<pair<string,int> > v;
        int max1 = 0;
        for(int j = 0; j < n; j++){
            int cnt = 0;
            string t = arr[j];
            ll ht = 0;
            for (int i = 0; i < t.size(); i++) {
                ht += (t[i] - 'a' + 1) * p_pow[i];
            }
            for (int i = 0; i + t.size() - 1 < s.size(); i++) {
                ll cur = hs[i + t.size() - 1];
                if (i > 0)
                    cur -= hs[i - 1];
                if (ht * p_pow[i] == cur) 
                    // cout << i << " ";
                    cnt++;
            }   
            // cout << endl;
            if(cnt > max1){
                max1 = cnt;
            }
            v.push_back(make_pair(t,cnt));
        }
        cout << max1 << endl;
        for(int i = 0; i < v.size(); i++){
            if(v[i].second == max1){
                cout << v[i].first << endl;
            }
        }
    }
}