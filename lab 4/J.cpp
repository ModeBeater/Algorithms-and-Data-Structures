#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
void print(int l, int r){
    int mid = (l + r) / 2;
    cout << v[mid] << " ";
    if(l == r){
        return;
    }
    print(l,mid - 1);
    print(mid + 1, r);
}
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < pow(2,n) - 1; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    print(0,v.size() - 1);
}