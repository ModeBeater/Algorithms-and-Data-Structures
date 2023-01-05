#include <iostream>
#include <vector>
#define ll long long
using namespace std;

string check(string s, string t){
    int l = -1;
    int r = 0;
    ll hs = 0;
    ll m = 1e9;
    int a[100000] = {0};
    int cnt = 0;
    for(int i = 0; i < t.size(); i++){
        ll ht = 0;
        hs = (t[i] - 'a' + 1) % m;
        for(int j = s.size() - 1; j >= 0; j--){
            ht = (s[j] - 'a' + 1) % m;
            if(hs == ht){
                a[j + 1] = a[j] + 1;
            }
            else{
                a[j + 1] = 0;
            }
            if(a[j + 1] > r){
                r = a[j + 1];
                l = j - r + 1;
            }
        }
    }
    if(r == 0){
        return "";
    }
    else{
        return s.substr(l,r);
    }
}



int main(){
    int n;
    cin >> n;
    vector<string> v;   
    string min1;
    ll min = 9999999;
    vector<ll> a;
    while(n--){
        string s;
        cin >> s;
        v.push_back(s);
        if(s.size() < min){
            min = s.size();
            min1 = s;
        }
    }
    for(int i = 0; i < v.size(); i++){
        if(v[i] != min1){
            min1 = check(min1,v[i]);
        }
    }
    cout << min1;
}