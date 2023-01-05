#include <iostream>
#include <algorithm>
using namespace std;
int arr[10000005];
int binSearchL(int l, int r, int x){
    if(arr[l + 1] > x){
        return 0;
    }
    while(l + 1 < r){
        int mid = (l + r) / 2;
        if(arr[mid] >= x){
            r = mid;
        }
        else{
            l = mid;
        }
    }
    return r;
}
int binSearchR(int l, int r, int x){
    if(arr[r - 1] < x){
        return r - 1;
    }
    while(l + 1 < r){
        int mid = (l + r) / 2;
        if(arr[mid] >= x){
            l = mid;
        }
        else{
            r = mid;
        }
    }
    return l;
}
int main(){
    int n,k;
    cin >> n >> k;
    bool ok[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr, arr + n);
    for(int i = 0; i < n; i++){
        ok[i] = false;
    }
    while(k--){
        int cnt = 0;
        int l1,r1,l2,r2;
        cin >> l1 >> r1 >> l2 >> r2;
        int l = binSearchL(-1,n - 1, l1);
        int r = binSearchR(0,n, r1);
        cout << l << " " << r << endl;
        for(int i = l; i <= r; i++){
            cnt++;
            ok[i] = true;    
        }
        int ll = binSearchL(-1,n - 1, l2);
        int rr = binSearchR(0,n, r2);
        for(int i = ll; i <= rr; i++){
            if(ok[i] == false){
                cnt++;
            }    
        }
        for(int i = l; i <= r; i++){
            ok[i] = false;
        }
        cout << cnt << endl;
    }
}