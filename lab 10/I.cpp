#include <iostream>
#include <vector>
#include <map>
using namespace std;
vector<int> v[105000];
int New = 0;
int Now = 1;
int closed = 2;
int mode[105000];
bool ok = false;
int n;
vector<int> a;
void dfs(int i){  
    if(mode[i] == Now){
        ok = true;
        return;
    }
    if(mode[i] == closed){
        return;
    }
    mode[i] = Now;
    for(int j = 0; j < v[i].size(); j++){
        dfs(v[i][j]);
    }
    a.push_back(i);
    mode[i] = closed;
}

int main(){
    int m;
    cin >> n >> m;
    int max1 = 0;
    map<int,int> mp;
    for(int i = 0; i < m; i++){
        int x,y;
        cin >> x >> y;
        if(mp[y] == x && n > 2){
            cout << "Impossible";
            return 0;
        }
        mp[x] = y;
        v[x].push_back(y);
        if(max1 < x){
            max1 = x;
        }
    }
    for(int i = 1; i <= n; i++){
        if(mode[i] == New){
            dfs(i);
        }
    }
    if(ok == true){
        cout << "Impossible";
    }
    else{
        cout << "Possible" << endl;
        for(int i = a.size() - 1; i >= 0; i--){
            cout << a[i] << " ";
        }
    }
}