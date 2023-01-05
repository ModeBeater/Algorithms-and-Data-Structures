#include <iostream>
#include <vector>
#define ll long long
using namespace std;
int main() {
    int n;
    cin >> n;
    ll p_pow[n];
    p_pow[0] = 1; 
    for (int i = 1; i < n; i++) {
        p_pow[i] = p_pow[i - 1] * 2;
    }
    ll x;
    ll sum = 0;
    string s;
    vector<ll> v;
    for (int i = 0; i < n; i++) {
        cin >> x;
        v.push_back(x);
        // cout << v[v.size() - 1] << endl;
        if(i != 0){
            s += char((x - v[v.size() - 2]) / p_pow[i] + 97);
        }
        // cout << char((sum - x) / p_pow[i] + 97);
        else{
            s += char(x / p_pow[i] + 97);
        }
    }
    cout << s;
} 