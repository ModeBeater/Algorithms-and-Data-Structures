#include <iostream>

using namespace std;
int arr[1000][1000];
int partition(int a,int low, int high){
    int pivot = arr[high][a];
    int i = low - 1;
    for(int j = low; j <= high - 1; j++){
        if(arr[j][a] > pivot){
            i++;
            swap(arr[i][a], arr[j][a]);
        }
    }
    swap(arr[i + 1][a], arr[high][a]);
    return i + 1;
}

void quickSort(int a,int low, int high){
    if(low < high){
        int pi = partition(a,low, high);
        quickSort(a,low, pi - 1);
        quickSort(a,pi + 1, high);
    }
}
int main(){
    int n,m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }
    for(int i = 0; i < m; i++){
        quickSort(i,0,n - 1);
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}