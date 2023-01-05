#include <iostream>
#include <vector>
using namespace std;
vector<int> v[105];
bool ok[105] = {false};
int min1 = 999999;
void find(int i, int cnt, int x){
    cnt++;
    ok[i] = true;
    if(i == x){
        if(cnt < min1){
            min1 = cnt;
        }
        return;
    }
    if(v[i].size() == 0){
        return;
    }
    for(int a = 0; a < v[i].size(); a++){
        if(ok[v[i][a]] == false){
            find(v[i][a],cnt,x);
        }
    }
}
int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int x;
            cin >> x;
            if(x == 1){
                v[i].push_back(j);
            }
        }
    }
    int a,b;
    cin >> a >> b;
    for(int i = 0; i < v[a].size(); i++){
        if(ok[v[a][i]] == false){
            find(v[a][i],0,b);
        }
        for(int j = 1; j <= n; j++){
            ok[j] = false;
        }
    }
    if(min1 == 999999){
        cout << -1;
    }
    else{
        cout << min1;
    }
}