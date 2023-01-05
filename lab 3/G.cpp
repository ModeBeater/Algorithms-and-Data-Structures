#include <iostream>
#include <vector>

using namespace std;
vector <int> v;
int getWorkTime(int bucketSize, int n) {
    int timeToWork = 0;
    for(int i = 0; i < n; i++){
        timeToWork += v[i] / bucketSize;
        if(v[i] % bucketSize)
            timeToWork++;
    }
    return timeToWork;
}

int main(){
    int n,k;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    int l = 0;
    int r = 1e9 + 2;
    while(l + 1 < r) {
        int mid = (l+r)/2;
        int timeToSanta = getWorkTime(mid,n);
        if(timeToSanta <= k)
            r = mid;
        else
            l = mid;
    }
    cout << r;
}