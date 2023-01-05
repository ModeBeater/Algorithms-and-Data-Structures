#include <iostream>

using namespace std;
int arr[805][805];
void binarySearch(int x, int j, int l, int r){
    int R = r;
    while(l <= r){
        int mid = (l + r) / 2;
        if(arr[j][mid] == x){
            cout << j << " " << mid << endl;
            return;
        }
        else if(arr[j][mid] > x){
            l = mid + 1;
        }
        else if(arr[j][mid] < x){
            r = mid - 1;
        }
    }
    l = 0;
    r = R;
    while(l <= r){
        int mid = (l + r) / 2;
        if(arr[j][mid] == x){
            cout << j << " " << mid << endl;
            return;
        }
        else if(arr[j][mid] < x){
            l = mid + 1;
        }
        else if(arr[j][mid] > x){
            r = mid - 1;
        }
    }
    cout << -1 << endl;
}


int main(){
    int k;
    cin >> k;
    int a[k];
    bool ok[k];
    for(int i = 0; i < k; i++){
        cin >> a[i];
        ok[i] = false;
    }
    int n,m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }
    for(int i = 0; i < k; i++){
        for(int j = 0; j < n; j++){
            if(j % 2 == 0){
                if(arr[j][0] >= a[i] && arr[j][m - 1] <= a[i]){
                    binarySearch(a[i], j, 0, m - 1);
                    ok[i] = true;
                    continue;
                }
            }
            if(j % 2 == 1){
                if(arr[j][0] <= a[i] && arr[j][m - 1] >= a[i]){
                    binarySearch(a[i], j, 0, m - 1);
                    ok[i] = true;
                    continue;
                }
            }
        }
        if(!ok[i]){
            cout << -1 << endl;
        }
    }
}