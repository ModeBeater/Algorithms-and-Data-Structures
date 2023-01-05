#include <iostream>

using namespace std;
char arr[1000000];
int partition(char pivot, int low, int high){
    int i = low - 1;    
    for(int j = low; j <= high - 1; j++){
        if(arr[j] < pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    return i + 1;
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    char x;
    cin >> x;
    int i = partition(x, 0, n - 1);
    if(arr[i] == x && i + 1 != n){
        cout << arr[i + 1];
        return 0;
    }
    if(arr[i] <= x){
        cout << arr[0];
        return 0;
    }
    cout << arr[i];
}