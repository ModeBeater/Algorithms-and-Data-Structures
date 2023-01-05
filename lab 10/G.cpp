#include <iostream>
#include <vector>
#include <map>
using namespace std;
vector<int> v[10500];
int New = 0;
int Now = 1;
int closed = 2;
int mode[10500];
bool ok = false;
bool check = true;
int n;
vector<int> a;
void dfs(int i,int from,int to){  
    if(mode[i] == Now){
        ok = true;
        return;
    }
    if(mode[i] == closed){
        return;
    }
    mode[i] = Now;
    for(int j = 0; j < v[i].size(); j++){
        if(v[i][j] == to && i == from){
            continue;
        }
        dfs(v[i][j],from,to);
    }
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
            cout << "NO";
            return 0;
        }
        mp[x] = y;
        v[x].push_back(y);
        if(max1 < x){
            max1 = x;
        }
    }
    for(int i = 0; i < n; i++){
        for(int k = 0; k < v[i].size(); k++){
            check = true;
            for(int j = 1; j <= max1; j++){
                if(mode[j] == New){
                    dfs(j,i, v[i][k]);
                }
                if(ok == true){
                    check = false;
                    break;
                }
            }
            for(int j = 1; j <= max1; j++){
                mode[j] = New;
            }
            if(check == true){
                cout << "YES";
                return 0;
            }
            ok = false;
        }
    }  
    if(check == true){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
}