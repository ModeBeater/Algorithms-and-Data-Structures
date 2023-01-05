#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int arr[1000005];
int binSearch(int x, int l, int r){
    while(l + 1 < r){
        int mid = (l + r) / 2;
        if(arr[mid] <= x){
            l = mid;
        }
        else{
            r = mid;
        }
    }
    return l;
}
int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr, arr + n);
    v[0] = arr[0];
    for(int i = 1; i < n; i++){
        v[i] = arr[i] + v[i - 1];
    }
    int k;
    cin >> k;
    while(k--){
        int cnt = 0;
        int sum = 0;
        int x; 
        cin >> x;
        if(x < arr[0]){
            cout << 0 << " " << 0 << endl;
        }
        else{
            int a = binSearch(x,0,n);
            cout << a + 1 << " " << v[a] << endl;
        }
    }   
}