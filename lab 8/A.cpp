#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

int main(){
    int n;
    cin >> n;
    unsigned long long m = 1e9 + 7;
    vector<pair<string,string> > c;
    map<string,string> mp;
    for(int i = 0; i < n * 2; i++){
        string s;
        cin >> s;
        unsigned long long hs = 0;
        unsigned long long p_pow = 1;
        for(int i = 0; i < s.size(); i++){
            unsigned long long cur = (s[i] - '0' + 1) * p_pow % m;
            hs = (hs + cur) % m;
            p_pow = p_pow * 11 % m;
        }
        string ans;
        ans = to_string(hs);
        mp[s] = ans;
        c.push_back(make_pair(s,ans));
    }
    int cnt = 0;
    for(int i = 0; i < c.size(); i++){
        if(cnt == n){
            break;
        }
        if(mp.find(c[i].second) != mp.end()){
            cnt++;
            cout << "Hash of string " << '"' << c[i].first << '"' << " is " << c[i].second << endl;
        }
    }
}