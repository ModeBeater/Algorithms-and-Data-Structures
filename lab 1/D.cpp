#include <iostream>
#include <deque>
using namespace std;
deque<char> dq;
bool check(string s){
    for(int i = 0; i < s.size(); i++){
        if(dq.empty() || dq.back() != s[i]){
            dq.push_back(s[i]);
        }
        else{
            if(dq.empty()){
                return false;
            }
            if(dq.back() == s[i]){
                dq.pop_back();
            }
        }
    }
    if(dq.empty()){
        return true;
    }
    else{
        return false;
    }
}


int main(){
    string s;
    cin >> s;
    if(check(s)){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
}