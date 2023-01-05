#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;
deque<int> dq;
int n,m,q;
int min1 = 999999;
vector<int> v[50005];
bool ok[50005] = {false};
bool check[50005] = {false};
void find(int i){
    check[i] = true;
    if(ok[i] == true){
        min1 = 1;
        return; 
    }
    for(int a = 0; a < v[i].size(); a++){
        if(check[v[i][a]] == false){
            dq.push_back(v[i][a]);
        }
    }
}
int main(){
    cin >> n >> m >> q;
    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    while(q--){
        int a,b;
        cin >> a >> b;
        if(a == 1){
            ok[b] = true;
        }
        else{
            if(ok[b] == true){
                cout << 0 << endl;
            }
            else{
                int cnt = 1;
                check[b] = true;
                for(int j = 0; j < v[b].size(); j++){
                    dq.push_back(v[b][j]);
                }
                int ans = dq.size();
                int temp = 0;
                while(!dq.empty()){
                    int d = dq.front();
                    if(check[d] == false){
                        find(dq.front());
                    }
                    if(ok[d] == true){
                        min1 = 1;
                        while(!dq.empty()){
                            dq.pop_front();
                        }
                        break;
                    }
                    temp++;
                    if(ans == temp){
                        cnt++;
                        ans = dq.size() - 1;
                        temp = 0;
                    }
                    dq.pop_front();
                }
                if(min1 == 999999){
                    cout << -1 << endl;
                }
                else{
                    cout << cnt << endl;
                }
                min1 = 999999;
                for(int j = 1; j <= n; j++){
                    check[j] = false;
                }
            }
        }
    }
}