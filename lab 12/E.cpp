#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct edge {
    int a, b, cost;
};

int n, m, v;
vector<edge> e;
int max1 = 100000000;
bool ok = false;
void solve() {
    vector<int> d (n, max1);
    d[v] = 0;
    vector<int> p (n, -1);
    int x;
    for (int i = 0; i < n; i++){
        x = -1;
        for (int j = 0; j <n * n; j++){
            if (d[e[j].a] < max1)
                if (d[e[j].b] > d[e[j].a] + e[j].cost) {
                    d[e[j].b] = max (-max1, d[e[j].a] + e[j].cost);
                    p[e[j].b] = e[j].a;
                    x = e[j].b;
                }
        }
    }
    if (x == -1)
        ok = false;
    else{
        int y = x;
        for (int i = 0; i < n; i++)
            y = p[y];

        vector<int> path;
        for (int cur = y; ; cur = p[cur]) {
            path.push_back (cur);
            if (cur == y && path.size() > 1){  
                break;
            }
        }
        reverse (path.begin(), path.end());
        cout << "YES" << endl;
        cout << path.size() << endl;
        for (int i = 0; i < path.size(); i++){
            cout << path[i] + 1 << ' ';
        }
        cout << endl;
        ok = true;
    }
}

int main(){
    cin >> n;
    vector<int> d(n, max1);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            edge cur;
            cin >> cur.cost;
            cur.a = i; cur.b = j;
            e.push_back(cur);
        }
    }
    for (int i = 0; i < n; i ++){
        v = i;
        solve();
        if(ok == true){
            break;
        }
    }
    if(ok == false){
        cout << "NO" << endl;
    }
}