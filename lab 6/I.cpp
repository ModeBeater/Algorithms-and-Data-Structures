#include <iostream>
using namespace std;
string s;

int partition(int low, int high){
    int pivot = s[high];
    // cout << pivot << endl;
    int i = low - 1;    
    for(int j = low; j <= high - 1; j++){
        if(s[j] < pivot){
            i++;
            swap(s[i],s[j]);
        }
    }
    swap(s[i + 1], s[high]);
    return i + 1;
}
void quickSort(int low, int high){
    if(low < high){
        // cout << s << " " << low << " " << high << endl;
        int pi = partition(low,high);
        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
        // cout << s << endl;
    }
}

int main(){
    cin >> s;
    quickSort(0,s.size() - 1);
    for(int i = 0; i < s.size(); i++){
        cout << s[i];
    }
}