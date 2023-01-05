#include <iostream> 
#include <vector> 
#include <queue> 
using namespace std; 

vector<int>g_road[410]; 
vector<int>g_air[410]; 
int arr[405][405]; 

int main(){ 
    int n,m; 
    cin >> n >> m; 
    for(int i=0;i<m;i++){ 
        int a,b; 
        cin >> a >> b; 
        a--; 
        b--; 
        g_road[a].push_back(b); 
        g_road[b].push_back(a); 
        arr[a][b] = 1; 
        arr[b][a] = 1; 
    } 
    for (int i = 0; i < n; i ++){ 
        for (int j = 0; j < n; j ++){ 
            if (arr[i][j] == 0 && i != j){ 
                g_air[i].push_back(j); 
            } 
        } 
    } 
    queue<int>q1; 
    vector<int>d1(n+1); 
    vector<bool>ok1(n+1); 
    q1.push(0); 
    ok1[0] = true; 
    while(!q1.empty()){ 
        int a = q1.front(); 
        q1.pop(); 
        for(int i=0;i<g_road[a].size();i++){ 
            int to = g_road[a][i]; 
            if(ok1[to] == false){ 
                ok1[to] = true; 
                q1.push(to); 
                d1[to] = d1[a]+1; 
            } 
        } 
    } 
    queue<int>q2; 
    vector<int>d2(n+1); 
    vector<bool>ok2(n+1); 
    q2.push(0); 
    ok2[0] = true; 
    while(!q2.empty()){ 
        int a = q2.front(); 
        q2.pop(); 
        for(int i=0;i<g_air[a].size();i++){ 
            int to = g_air[a][i]; 
            if(ok2[to] == false){ 
                ok2[to] = true; 
                q2.push(to); 
                d2[to] = d2[a]+1; 
            } 
        } 
    } 
    if (ok1[n-1] == false || ok2[n-1] == false){ 
        cout << -1; 
    } 
    else { 
        cout << max(d1[n-1], d2[n-1]); 
    } 
}