#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n,m;
int p[200005];
pair<int, pair<int,int> > pr[200005];
unsigned long long sum = 0;

int find(int i){
    if(i == p[i]){
        return i;
    }
    return p[i] = find(p[i]);
}

unsigned long long merge(int a, int b, int c){
    int root_a = find(a);
    int root_b = find(b);
    if(root_a == root_b){
        return root_b;
    }
    p[root_a] = root_b;
    sum += c;
    return root_b;
}



int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a,b,c;
        cin >> a >> b >> c;
        pr[i] = {c,{a,b}};
    }    
    for(int i = 1; i <= n; i++){
        p[i] = i;
    }
    sort(pr, pr + m);
    for(int i = 0; i < m; i++){
        int l = pr[i].second.first;
        int r = pr[i].second.second;
        int c = pr[i].first;
        for(int j = l + 1; j <= r; j++){
            j = merge(l,j,c);
            if(j > r){
                break;
            }
        }
    }
    cout << sum;
}