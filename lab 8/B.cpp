#include <iostream>
#include <vector>
#include <map>
#define ll long long

using namespace std;
map<int,int> mp;

int main(){
    string s,t,m;
    cin >> s >> t >> m;
    if(m.size() > t.size() || m.size() > s.size()){
        cout << 0 << endl;
        return 0;
    }
    ll p_pow[s.size()];
    ll p = 31;
    p_pow[0] = 1; 
    for (int i = 1; i < s.size(); i++) {
        p_pow[i] = p_pow[i - 1] * p;
    }
    vector<ll> hs(s.size());
    for (int i = 0; i < s.size(); i++) {
        hs[i] = (s[i] - 96) * p_pow[i];
        if (i > 0) hs[i] += hs[i - 1];
    }
    ll p_pow2[t.size()];
    p_pow2[0] = 1; 
    for (int i = 1; i < t.size(); i++) {
        p_pow2[i] = p_pow2[i - 1] * p;
    }
    vector<ll> hs2(t.size());
    for (int i = 0; i < t.size(); i++) {
        hs2[i] = (t[i] - 96) * p_pow2[i];
        if (i > 0) hs2[i] += hs2[i - 1];
    }
    ll hm = 0;
    int cnt = 0;
    for (int i = 0; i < m.size(); i++) {
        hm += (m[i] - 'a' + 1) * p_pow[i];
    }
    for (int i = 0; i + m.size() - 1 < s.size(); i++) {
        ll cur = hs[i + m.size() - 1];
        if (i > 0)
            cur -= hs[i - 1];
        if (hm * p_pow[i] == cur) 
            mp[i] = 1;
    }   
    hm = 0;
    for (int i = 0; i < m.size(); i++) {
        hm += (m[i] - 'a' + 1) * p_pow2[i];
    }
    for (int i = 0; i + m.size() - 1 < t.size(); i++) {
        ll cur = hs2[i + m.size() - 1];
        if (i > 0)
            cur -= hs2[i - 1];
        if (hm * p_pow[i] == cur) 
            if(mp.find(i) != mp.end()){
                cnt++;
            }
            mp[i] = 1;
    }   
    cout << cnt;
}