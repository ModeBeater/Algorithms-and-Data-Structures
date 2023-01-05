#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n + 1][n + 1];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> arr[i][j];
        }
    }
    int parent[n + 1];
    int key[n + 1];
    bool check[n + 1];
    for(int i = 1; i <= n; i++){
        key[i] = 101;
        check[i] = false;
    }
    key[1] = 0;
    parent[1] = -1;
    int sum = 0;
    for(int i = 0; i < n - 1; i++){
        int index;
        int min = 101;
        for(int j = 1; j <= n; j++){
            if(check[j] == false && key[j] < min){
                // cout << j << " " << key[j] << endl;
                min = key[j];
                index = j;
            }
        }
        check[index] = true;
        for(int j = 1; j <= n; j++){
            if(arr[index][j] < key[j] && check[j] == false){
                parent[j] = index;
                key[j] = arr[index][j];
            }
        }
        // sum += key[j];
    }
    for(int j = 1; j <= n; j++){
        sum += key[j];
        cout << parent[j] << " " << key[j] << endl;
    }
    cout << sum;
}