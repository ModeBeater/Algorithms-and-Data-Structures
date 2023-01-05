#include <iostream>
#include <deque>

using namespace std;

int main(){
    deque<int> dq;
    char a;
    while(a != '!'){
        cin >> a;
        if(a == '+'){
            int x;
            cin >> x;
            dq.push_back(x);
        }
        if(a == '-'){
            int x;
            cin >> x;
            dq.push_front(x);
        }
        if(a == '*'){
            if(!dq.empty()){
                cout << dq.front() + dq.back() << endl;
                dq.pop_front();
                if(!dq.empty()){
                    dq.pop_back();
                }
            }
            else{
                cout << "error" << endl;
            }
        }
    }
}