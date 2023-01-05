#include <iostream>

using namespace std;
int arr[100000];
int partition(int low, int high){
    int pivot = arr[high];
    int i = low - 1;
    for(int j = low; j <= high - 1; j++){
        if(arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int low, int high){
    if(low < high){
        int pi = partition(low, high);
        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
    }
}
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    quickSort(0, n - 1);
    int min = 9999999;
    for(int i = 0; i < n - 1; i++){
        if(arr[i + 1] - arr[i] < min){
            min = arr[i + 1] - arr[i];
        }
    }
    for(int i = 0; i < n - 1; i++){
        if(arr[i + 1] - arr[i] == min){
            cout << arr[i] << " " << arr[i + 1] << " ";
        }
    }
}