#include <iostream>
#include <vector>
using namespace std;
bool ok[1005000] = {false};
vector<int> v[1005000];
bool check = false;
void find(int i, int x){
    ok[i] = true;
    if(i == x){
        check = true;
        return;
    }
    if(v[i].size() == 0){
        return;
    }
    for(int a = 0; a < v[i].size(); a++){
        if(ok[v[i][a]] == false){
            find(v[i][a],x);
        }
    }
}
int main(){
    int n,m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x,y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int a,b;
    cin >> a >> b;
    for(int i = 0; i < v[a].size(); i++){
        ok[a] = true;
        if(ok[v[a][i]] == false){
            find(v[a][i],b);
            if(check == true){
                cout << "YES";
                return 0;
            }
        }
        for(int j = 1; j <= n; j++){
            ok[j] = false;
        }
    }
    if(check == true){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
}