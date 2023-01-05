#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n,q;
    cin >> n >> q;
    int arr[n + 1][n + 1];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> arr[i][j];
        }
    }
    for(int c = 0; c < q; c++){
        int i,j,k;
        cin >> i >> j >> k;
        if(arr[i][j] == 1 && arr[j][k] == 1 && arr[i][k] == 1){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}