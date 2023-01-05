#include <iostream>
#include <deque>
using namespace std;

int main(){
    deque<int> dq;
    int n;
    cin >> n;
    int ok = 0;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        if(x == 1){
            int a;
            cin >> a;
            if(ok == 0){
                dq.push_back(a);
            }
            else{
                dq.push_front(a);
            }
        }
        if(x == 2){
            if(ok == 0){
                ok = 1;
            }
            else{
                ok = 0;
            }
        }
    }
    if(ok == 0){
        while(!dq.empty()){
            cout << dq.front() << " ";
            dq.pop_front();
        }
    }
    else{
        while(!dq.empty()){
            cout << dq.back() << " ";
            dq.pop_back();
        }
    }
}