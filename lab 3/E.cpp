#include <iostream>
#include <vector>
using namespace std;
vector<pair<pair<int,int>,pair<int,int> > > v(1000005);
int main(){
    int n,k;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        v[i].first.first = x1;
        v[i].first.second = y1;
        v[i].second.first = x2;
        v[i].second.second = y2;
    }
    int l = 0;
    int r = 1e9 + 2;
    while(l + 1 < r){
        int mid = (l + r) / 2;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(v[i].first.first <= mid && v[i].first.second <= mid && v[i].second.first <= mid && v[i].second.second <= mid){
                cnt++;
            }
        }
        if(cnt >= k){
            r = mid;
        }
        else{
            l = mid;
        }
    }
    cout << r;
}