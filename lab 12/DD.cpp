#include <iostream> 
#include <vector> 
#include <queue> 
#include <algorithm>
#include <cmath>
using namespace std; 

vector<pair<int,int> > v; 
bool cmp(pair<int,int> p1,pair<int,int> p2){
    if(abs(p1.first - p2.first) > abs(p1.second - p2.second)){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    int m; 
    cin >> m; 
    int max2 = 0;
    for(int i = 0; i < m; i++){ 
        int a,b; 
        cin >> a >> b;
        if(b > max2){
            max2 = b;
        } 
        v.push_back({a,b});
    } 
    if(m == 1){
        cout << 0 << endl;
        return 0;
    }
    queue<int> q; 
    vector<bool> ok = {false};
    q.push(0); 
    sort(v.begin(), v.end(), cmp);
    ok[0] = true; 
    long long sum = 0;
    // if(v.size() > 2){
    //     swap(v[0], v[v.size() - 1]);
    //     v.pop_back();
    // }
    while(!q.empty()){
        int a = q.front(); 
        q.pop(); 
        int index;
        int max1 = max2;
        for(int i = 0; i < v.size(); i++){ 
            int to1 = v[i].first;
            int to2 = v[i].second; 
            if(ok[i] == false){
                if(abs(to1 - v[a].first) + abs(to2 - v[a].second) < max1){
                    max1 = abs(to1 - v[a].first) + abs(to2 - v[a].second);
                    index = i;    
                    // break;  
                }
            }
        } 
        cout << index << " " << max1 << endl;
        if(ok[index] == false){
            // if(v.size() > 2){
            //     swap(v[index], v[v.size() - 1]);
            //     v.pop_back();
            // }
            ok[index] = true;
            q.push(index);
            if(sum < max1){
                sum = max1;
            }
        }
    } 
    cout << sum;
}