#include <iostream>
#include <vector>
using namespace std;
int cnt = 1;
int a = 3;
vector<int> v;
bool check(int c){
    for(int i = 2; i <= c / 2; i++){
        if(c % i == 0){
            return false;
        }
    }
    return true;
}
void solve(int a){
    for(int i = 2; i <= a / 2; i++){
        if(a % i == 0){
            return;
        }
    }
    cnt++;
    if(check(cnt)){
        v.push_back(a);
    }
}

int main(){
    int n;
    cin >> n;
    while(v.size() != n){
        solve(a);
        a++;
    }
    a--;
    cout << v[n - 1] << " ";
}