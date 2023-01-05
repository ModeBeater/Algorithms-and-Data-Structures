#include <iostream>
#include <vector>
using namespace std;
vector <int> v;
int binSearch(int l,int r, int x){
    while(l + 1 < r){
        int mid = (l + r) / 2;
        if(v[mid] > x){
            r = mid;
        }
        else{
            l = mid;
        }
    }
    return l;
}

int main(){
    int n;
    cin >> n;
    for(int i = 2; i <= n; i++){
        bool ok = false;
        for(int j = 2; j * j <= i; j++){
            if(i % j == 0){
                ok = true;
                break;
            }
        }
        if(ok == false){
            v.push_back(i);
        }
    }
    for(int i = v.size() - 1; i >= 0; i--){
        int x = n - v[i];
        if(x >= v[0] && x <= v[v.size() - 1]){
            int j = binSearch(0,v.size(),x);
            // cout << j << endl;
            if(v[i] + v[j] == n){
                cout << v[j] << " " << v[i];
                return 0;
            }
        }
        v.pop_back();
    }
}