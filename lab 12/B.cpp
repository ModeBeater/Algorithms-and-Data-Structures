#include <iostream> 
#include <vector> 
#include <set> 
using namespace std; 

int max1 = 1000000000; 
vector<pair<int,int> > v[200005]; 
vector<int> a(200005, max1); 
int n,m; 

int deikstra(int c, int end){ 
    a.clear(); 
    for(int i=0;i < 200005;i++){ 
        a[i] = max1; 
    } 
    a[c] = 0; 
    set < pair<int,int> > q; 
    q.insert(make_pair(a[c],c)); 
    while(!q.empty()){ 
        int b = q.begin()->second; 
        q.erase(q.begin()); 
        for(int j = 0;j < v[b].size();j++){ 
            int to = v[b][j].first; 
            int len = v[b][j].second; 
            if(a[b] + len < a[to]){ 
                q.erase(make_pair(a[to], to)); 
                a[to] = a[b] + len; 
                q.insert(make_pair(a[to], to)); 
            } 
        } 
    } 
    return a[end]; 
} 



int main(){ 
    cin >> n >> m; 
    for (int i = 0; i < m; i++){ 
        int a,b,c; 
        cin >> a >> b >> c; 
        v[a].push_back({b,c}); 
        v[b].push_back({a,c}); 
    } 
    int q,w,e,r; 
    cin >> q >> w >> e >> r; 
    int a,b; 
    a = deikstra(q,w) + deikstra(w,e) + deikstra(e,r); 
    b = deikstra(q,e) + deikstra(e,w) + deikstra(w,r) ; 
    if(min(a,b) <= max1){ 
        cout << min(a,b); 
    }
    else{ 
        cout << -1; 
    } 
    return 0; 
}