#include <iostream>
using namespace std;
// int b[100000];
// int c[100000];
void mergeSortOne(int a[], int l, int mid, int r){
    int i,j,k;
    i = l;
    j = mid + 1;
    k = l;
    int b[r + 1];
    while(i <= mid && j <= r){
        if(a[i] < a[j]){
            b[k] = a[i];
            i++;
            k++;
        }
        else{
            b[k] = a[j];
            j++;
            k++;
        }
    }
    for(; i <= mid; i++){
        b[k] = a[i];
        k++;
    }
    for(; j <= r; j++){
        b[k] = a[j];
        k++;
    }
    for(i = l; i <= r; i++){
        // cout << a[i] << " ";
        a[i] = b[i];
    }
    // cout << endl;
}
void mergeSort(int a[], int l, int r){
    if(l < r){
        int mid = (l + r) / 2;
        mergeSort(a,l,mid);
        mergeSort(a,mid + 1, r);
        mergeSortOne(a,l,mid,r);
    }
}
int main(){
    int n,m;
    cin >> n >> m;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    mergeSort(a,0, n - 1);
    int b[m];
    for(int i = 0; i < m; i++){
        cin >> b[i];
    }
    mergeSort(b,0, m - 1);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i] == b[j]){
                cout << a[i] << " ";
                b[j] = -1;
                i++;
                continue;
            }
        }
    }
}