#include <iostream>
#include <vector>

using namespace std;
vector <int> v;
int binarysearch(int l, int r, int x){
    while(l + 1 < r){
        int mid = (l + r) / 2;
        if(v[mid] >= x){
            r = mid;
        }
        else{
            l = mid;
        }
    }
    return r + 1;
}
int main(){
    int n,m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        v.push_back(x);
        if(i != 0){
            v[i] += v[i - 1];
        }
    }
    while(m--){
        int x;
        cin >> x;
        cout << binarysearch(-1 ,n - 1,x) << endl;
    }
}