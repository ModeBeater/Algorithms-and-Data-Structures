#include <iostream>
#include <set>
#include <unordered_set>
#include <vector>
#define ll long long
using namespace std;

int main(){
    string s;
    cin >> s;
    ll p = 31;
    ll m = 9948424647760667;
    ll arr[s.size()];
    for(int i = 0; i < s.size(); i++){
        arr[i] = s[i] - 'a' + 1;
    }
    unordered_set<ll> st;
    for(int i = 0; i < s.size(); i++){
        ll cur = arr[i];
        st.insert(cur);
        for(int j = i + 1; j < s.size(); j++){
            cur = (cur * p + arr[j]) % m;
            st.insert(cur);
        }
    }
    cout << st.size();
}