#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int arr[1005][1005];
vector<pair<int,int> > v;
stack<int> st;
int cnt = 0;
int n,m;
int x[4] = {1, 0, -1, 0};
int y[4] = {0, 1, 0, -1};
void bfs(int i, int j){
    if(i < 0 || j < 0 || i >= n || j >= m || arr[i][j] == 0 || arr[i][j] == 2){
        return;
    }
    if(arr[i][j] == 1){
        arr[i][j] = 2;
        v.push_back(make_pair(i,j));
        st.pop();
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 2){
                v.push_back(make_pair(i,j));
            }
            if(arr[i][j] == 1){
                st.push(1);  
            }
        }
    }
    int i = 0;
    while(!st.empty()){
        int size = v.size();
        int check = st.size();
        for(i; i < size; i++){
            for(int k = 0; k < 4; k++){
                int tox = v[i].first + x[k];
                int toy = v[i].second + y[k];
                bfs(tox, toy);
                if(st.empty()){
                    cout << cnt + 1;
                    return 0;
                }
            }
        }
        i = size;
        if(check == st.size()){
            cout << -1 << endl;
            return 0;
        }
        cnt++;
    }
    cout << cnt;
}