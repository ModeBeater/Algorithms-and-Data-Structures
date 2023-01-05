#include <iostream>
#include <vector>
#include <set>
#define ll long long
using namespace std;

int main(){
    set<int> st;
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
    int n;
    cin >> n;
    while(n--){
        string t;
        cin >> t;
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
                for(int j = 0; j < t.size(); j++){
                    st.insert(i + j);
                }
                // st.insert(i);
        }   
    }
    // cout << st.size() << endl;
    if(st.size() >= s.size()){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
}
