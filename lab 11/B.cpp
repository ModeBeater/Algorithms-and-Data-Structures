#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v;
    int min1 = 999999;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        if(x < min1){
            min1 = x;
        }
        v.push_back(x);
    }
    unsigned long long sum = 0;
    bool ok = false;
    for(int i = 0; i < v.size(); i++){
        if(ok == true && v[i] == min1){
            sum += (v[i] + min1);
        }
        if(v[i] != min1){
            sum += (v[i] + min1);
        }
        if(v[i] == min1){
            ok = true;
        }
    }
    cout << sum;
}