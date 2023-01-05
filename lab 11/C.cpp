#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(){
    int n,m,x,y;
    cin >> n >> m >> x >> y;
    vector<pair<int,int> > v[n + 1];
    bool check[n + 1] = {false};
    for(int i = 0; i < m; i++){
        string s;
        cin >> s;
        int a,b,c;
        cin >> a >> b >> c;
        long long sum;
        if(s == "both"){
            sum = c * min(x,y);
        }
        if(s == "small"){
            sum = c * y;
        }
        if(s == "big"){
            sum = c * x;
        }
        v[a].push_back({b,sum});
        v[b].push_back({a,sum});
    }
    long long total = 0;
    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > q;
    q.push({0,1});
    while(!q.empty()){
        pair<int,int> d = q.top();
        q.pop();
        if(check[d.second] == true){
            continue;
        }
        check[d.second] = true;
        total += d.first;
        for(int i = 0; i < v[d.second].size(); i++){
            if(check[v[d.second][i].first] == false){
                q.push({v[d.second][i].second, v[d.second][i].first});
            }
        }
    }
    cout << total;
}