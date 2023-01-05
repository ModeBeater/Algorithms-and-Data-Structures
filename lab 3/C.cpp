#include <iostream>

using namespace std;


int main(){
    int n, k;
    cin >> n >> k;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    while(k--){
        int cnt = 0;
        int l1,r1,l2,r2;
        cin >> l1 >> r1 >> l2 >> r2;
        for(int i = 0; i < n; i++){
            if(arr[i] >= l1 && arr[i] <= r1){
                cnt++;
            }
            else if(arr[i] >= l2 && arr[i] <= r2){
                cnt++;
            }
        }
        cout << cnt << endl;
    }
}