#include <iostream>
#include <vector>
using namespace std;
vector<char> b;
vector<char> a;
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
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        char x;
        cin >> x;
        if(x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u'){
            a.push_back(x);
        }
        else{
            b.push_back(x);
        }
    }
    quickSortA(0, a.size() - 1);
    quickSortB(0,b.size() - 1);
    for(int i = 0; i < a.size(); i++){
        cout << a[i];
    }
    for(int i = 0; i < b.size(); i++){
        cout << b[i];
    }
}