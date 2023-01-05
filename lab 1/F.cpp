#include <iostream>

using namespace std;
int cnt = 1;
int a = 3;
void solve(int a){
    for(int i = 2; i <= a / 2; i++){
        if(a % i == 0){
            return;
        }
    }
    cnt++;
}

int main(){
    int n;
    cin >> n;
    if(n == 1){
        cout << 2 << endl;
        return 0;
    }
    while(cnt != n){
        solve(a);
        a++;
    }
    a--;
    cout << a;
}