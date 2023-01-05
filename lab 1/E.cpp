#include <iostream>
#include <deque>
using namespace std;

int main(){
    deque<int> dq1(5);
    deque<int> dq2(5);
    int cnt = 0;
    for(int i = 0; i < 5; i++){
        cin >> dq1[i];
    }
    for(int i = 0; i < 5; i++){
        cin >> dq2[i];
    }
    while(cnt < 1000000){
        cnt++;
        int a = dq1.front();
        int b = dq2.front();
        dq1.pop_front();
        dq2.pop_front();
        if(a == 0 && b == 9){
            dq1.push_back(a);
            dq1.push_back(b);
        }
        else if(a == 9 && b == 0){
            dq2.push_back(a);
            dq2.push_back(b);
        }
        else if(a > b){
            dq1.push_back(a);
            dq1.push_back(b);
        }
        else{
            dq2.push_back(a);
            dq2.push_back(b);
        }
        if(dq1.empty()){
            cout << "Nursik " << cnt;
            return 0;
        }
        else if(dq2.empty()){
            cout << "Boris " << cnt;
            return 0;
        }
    }
    cout << "blin nichya";
}