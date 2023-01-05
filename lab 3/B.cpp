#include <iostream>
#include <vector>

using namespace std;
vector<int> v;
long long getBlocksCount(long long sz, int n) {
    long long cur = 0, res = 0;
    for(int i = 0; i < n; i++){
        if(v[i] > sz)
            return 1e18+123;
        if(cur + v[i] > sz) {
            res++;
            cur = v[i];
        } else
            cur += v[i];
    }
    if(cur != 0)
        res++;
    return res;
}
int main(){
    int n,k;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    long long l = 0;
    long long r = 1e18 + 2;
    while(l + 1 < r){
        long long mid = (l + r) / 2;
        long long blocks = getBlocksCount(mid,n);
        if(blocks <= k)
            r = mid;
        else
            l = mid;
    }
    cout << r;
}