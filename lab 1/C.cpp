#include <iostream>
#include <stack>
using namespace std;

int main(){
    stack <char> a;
    stack <char> b;
    string s,t;
    cin >> s >> t;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '#' && !a.empty()){
            a.pop();
        }
        if(s[i] != '#'){
            a.push(s[i]);
        }
    }
    for(int i = 0; i < t.size(); i++){
        if(t[i] == '#' && !b.empty()){
            b.pop();
        }
        if(t[i] != '#'){
            b.push(t[i]);
        }
    }
    if(a.size() != b.size()){
        cout << "No" << endl;
        return 0;
    }
    else{
        while(!a.empty()){
            if(a.top() != b.top()){
                cout << "No" << endl;
                return 0;
            }
            a.pop();
            b.pop();
        }
        cout << "Yes" << endl;
    }
}