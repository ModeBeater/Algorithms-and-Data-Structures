#include <iostream>

using namespace std;
int a[805];
void binarySearch(int x, int l, int r){
    int R = r;
    while(l <= r){
        int mid = (l + r) / 2;
        if(a[mid] == x){
            cout << "Yes" << endl;
            return;
        }
        else if(a[mid] > x){
            l = mid + 1;
        }
        else if(a[mid] < x){
            r = mid - 1;
        }
    }
    l = 0;
    r = R;
    while(l <= r){
        int mid = (l + r) / 2;
        if(a[mid] == x){
            cout << "Yes" << endl;
            return;
        }
        else if(a[mid] < x){
            l = mid + 1;
        }
        else if(a[mid] > x){
            r = mid - 1;
        }
    }
    cout << "No" << endl;
}


int main(){
    int k;
    cin >> k;
    for(int i = 0; i < k; i++){
        cin >> a[i];
    }
    int x;
    cin >> x;
    binarySearch(x,0,k - 1);
}