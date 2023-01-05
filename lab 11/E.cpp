#include <iostream>
#include <vector>

using namespace std;
int p[1000000];
int r[1000000];
int find(int i){
    if(p[i] == i){
        return i;
    }
    return p[i] = find(p[i]);
}

bool check(int a,int b){
    int root_a = find(a);
    int root_b = find(b);
    if(root_a == root_b){
        return true;
    }
    else{
        if(r[root_a] < r[root_b]){
            p[root_a] = root_b;
        }
        else if(r[root_b] < r[root_a]){
            p[root_b] = root_a;
        }
        else{
            p[root_a] = root_b;
            r[root_b]++;
        }
        return false;
    }
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> v[n + 1];
    for(int i = 1; i <= n; i++){
        p[i] = i;
    }
    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int cnt = 0;
    vector<int> a;
    for(int i = n; i > 1; i--){
        cnt++;
        for(int j = 0; j < v[i].size(); j++){
            if(v[i][j] > i && find(i) != find(v[i][j])){
                cnt--;
                check(i,v[i][j]);
            }
        }
        a.push_back(cnt);
    }
    for(int i = a.size() - 1; i >= 0; i--){
        cout << a[i] << endl;
    }
    cout << 0 << endl;
}