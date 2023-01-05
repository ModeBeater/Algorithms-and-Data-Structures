#include <iostream>
#include <vector>
// #include <algorithm>

using namespace std;
vector <int> v;

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
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    // sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++){
        if(v[i] <= 3000){
            cout << i + 1 << endl;
        }
        else{
            int x = v[i] - 3000;
            int j = binSearch(0, v.size(), x);
            // cout << v[j + 1] << endl;
            if(v[j] < x){
                cout << i + 1 - j - 1 << endl;
            }
            else{
                cout << i + 1 - j << endl;
            }
            // cout << i + 1 - (j + 1) << endl;
        }
    }
}