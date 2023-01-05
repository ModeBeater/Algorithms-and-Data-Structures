#include <iostream>
using namespace std;
int arr[105][105];
bool used[105][105];
int cnt = 0;
int n,m;
void bfs(int i, int j){
    if(i < 0 || j < 0 || i >= n || j >= m || arr[i][j] == 0){
        return;
    }
    if(arr[i][j] == 1 && used[i][j] == true){
        used[i][j] = false;
        bfs(i + 1,j);
        bfs(i - 1,j);
        bfs(i, j + 1);
        bfs(i, j - 1);
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < s.size(); j++){
            arr[i][j] = s[j] - '0';
            if(arr[i][j] == 1){
                used[i][j] = true;
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j] == 1 && used[i][j] == true){
                bfs(i,j);
                cnt++;
            }
        }
    }
    cout << cnt;        
}