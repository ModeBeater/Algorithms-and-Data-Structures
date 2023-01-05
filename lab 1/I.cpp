#include <iostream>
#include <deque>
using namespace std;
 
int main(){
    int n;
    cin >> n;
    deque <char> dq;
    deque<char> s;
    deque<char> k;
    for(int i = 0; i < n; i++){
        char x;
        cin >> x;
        dq.push_back(x);
        if(x == 'K'){
            k.push_back(x);
        }
        else{
            s.push_back(x);
        }
    }
    while(!s.empty() && !k.empty()){
        char a = dq.front();
        deque<char> temp;
        dq.pop_front();  
        temp.push_back(a);
        if(a == 'K'){
            int cnt = 1;
            while(dq.front() == 'K'){
                temp.push_back('K');
                dq.pop_front();
                cnt++;
            }
            while(cnt > 0){
                if(dq.front() == 'S'){
                    dq.pop_front();
                    cnt--;
                    s.pop_front();
                    if(s.size() == 0){
                        cout << "KATSURAGI";
                        return 0;
                    }
                }
                else{
                    temp.push_back('K');
                    dq.pop_front();
                    cnt++;
                }
            }
        }  
        if(a == 'S'){
            int cnt = 1;
            while(dq.front() == 'S'){
                temp.push_back('S');
                dq.pop_front();
                cnt++;
            }
            while(cnt > 0){
                if(dq.front() == 'K'){
                    dq.pop_front();
                    cnt--;
                    k.pop_front();
                    if(k.size() == 0){
                        cout << "SAKAYANAGI";
                        return 0;
                    }
                }
                else{
                    temp.push_back('S');
                    dq.pop_front();
                    cnt++;
                }
            }
        }  
        while(!temp.empty()){
            dq.push_back(temp.front());
            temp.pop_front();
        }
    }
    if(k.size() == 0){
        cout << "SAKAYANAGI";
    }
    else{
        cout << "KATSURAGI";
    }
}