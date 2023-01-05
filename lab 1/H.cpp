#include <iostream>

using namespace std;

bool check(int a){
    for(int i = 2; i <= a / 2; i++){
        if(a % i == 0){
            return false;
        }
    }
    return true;
}


int main(){
    int n;
    cin >> n;
    if(n == 1){
        cout << "NO" << endl;
        return 0;
    }
    if(check(n)){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}