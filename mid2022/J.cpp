#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> v;

int binSearch(int l, int r, int x){
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
    int a;
    cin >> a;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    for(int i = v.size() - 1; i >= 0; i--){
        int x = a - v[i];
        // cout << x << endl;
        if(x >= v[0] && x <= v[v.size() - 1]){
            int j = binSearch(0, v.size(), x);
            // cout << x << endl;
            // cout << v[i] << " " << v[j] << endl;
            if(v[i] + v[j] == a){
                cout << v[j] << " " << v[i];
                return 0;
            }
        }
        v.pop_back();
    }
}