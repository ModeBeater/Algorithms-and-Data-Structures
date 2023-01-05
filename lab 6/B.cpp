#include <iostream>

using namespace std;
int a[1000000];
int b[1000000];
int partitionA(int low, int high){
    int pivot = a[high];
    int i = low - 1;
    for(int j = low; j <= high - 1; j++){
        if(a[j] < pivot){
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[high]);
    return i + 1;
}

void quickSortA(int low, int high){
    if(low < high){
        int pi = partitionA(low,high);
        quickSortA(low, pi - 1);
        quickSortA(pi + 1, high);
    }
}
int partitionB(int low, int high){
    int pivot = b[high];
    int i = low - 1;
    for(int j = low; j <= high - 1; j++){
        if(b[j] < pivot){
            i++;
            swap(b[i], b[j]);
        }
    }
    swap(b[i + 1], b[high]);
    return i + 1;
}

void quickSortB(int low, int high){
    if(low < high){
        int pi = partitionB(low,high);
        quickSortB(low, pi - 1);
        quickSortB(pi + 1, high);
    }
}
int main(){
    int n,m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < m; i++){
        cin >> b[i];
    }
    quickSortA(0, n - 1);
    quickSortB(0, m - 1);
    for(int i = 0; i < n; i++){
        for(int j = 0;j < m; j++){
            if(a[i] == b[j]){
                cout << a[i] << " ";
                swap(b[j], b[m - 1]);
                m--;
                break;
            }
        }
    }
}