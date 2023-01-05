#include <iostream>

using namespace std;
int arr[1000000];
void mergeSort(int a[], int b[], int n, int m){
    int i = 0;
    int j = 0;
    int k = 0;
    while(i < n && j < m){
        if(a[i] < b[j]){
            arr[k] = a[i];
            k++;
            i++;
        }
        else{
            arr[k] = b[j];
            k++;
            j++;
        }
    }
    for(; i < n; i++){
        arr[k] = a[i];
        k++;
    }
    for(; j < m; j++){
        arr[k] = b[j];
        k++;
    }
}
int main(){
    int n,m;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cin >> m;
    int b[m];
    for(int i = 0; i < m; i++){
        cin >> b[i];
    }
    mergeSort(a,b,n,m);
    for(int i = 0; i < n + m; i++){
        cout << arr[i] << " ";
    }
}