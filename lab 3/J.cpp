#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
    int n,h;
    cin >> n >> h;
    double arr[n];
    int max = -9999999;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(max < arr[i]){
            max = arr[i];
        }
    }
    double k = 1;
    if(n == h){
        cout << max << endl;
        return 0;
    }
    while(true){
        int sum = 0;
        for(int i = 0; i < n; i++){
            // cout << ceil(arr[i] / k) << " ";
            sum += ceil(arr[i] / k);
            if(sum > h){
                break;
            }
        }
        // cout << endl;
        if(sum <= h){
            cout << k << endl;
            break;
        }
        k++;
    }
}