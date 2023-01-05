#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

bool cmp(pair<int,pair<int,int> > p1, pair<int,pair<int,int> > p2){
    if(abs(p1.second.first - p2.second.first) > abs(p1.second.second - p2.second.second)){
        return true;
    }
    else{
        return false;
    }
}



int main(){
    int n;
    cin >> n;
    vector<pair<int,pair<int,int> > > v;
    for(int i = 0; i < n; i++){
        int x,y;
        cin >> x >> y;
        v.push_back({i + 1,{x,y}});
    }
    sort(v.begin(), v.end(),cmp);
    long long max1= 0;
    for(int i = 0; i < v.size() - 1; i++){
        // cout << v[i + 1].first << " " << v[i + 1].second << endl;
        long long a = abs(v[i].second.first - v[i + 1].second.first) + abs(v[i].second.second - v[i + 1].second.second);
        // cout << a << endl;
        if(max1 < a){
            max1 = a;
        }
    }
    cout << max1;
}