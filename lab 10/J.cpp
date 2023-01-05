#include <iostream>
#include <vector>
using namespace std;
bool ok[100500] = {false};
vector<int> v[100500];
int cnt = 0;
void dfs(int i){
    ok[i] = true;
    if(v[i].size() == 0){
        return;
    }
    for(int j = 0; j < v[i].size(); j++){
        if(v[i].size() < v[v[i][j]].size()){
            cnt++;
        }
        dfs(v[i][j]);
    }
}


int main(){
    int n,m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
    }
    for(int i = 1; i <= n; i++){
        if(ok[i] == false){
            dfs(i);
            cnt++;
        }
    }
    cout << cnt;
}