#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<string> v;
    for(int i = 0; i < n; i++){
        long long int x;
        cin >> x;
        string s;
        while(x > 0){
            if(x % 2 == 1){
                s += '1';
            }
            if(x % 2 == 0){
                s += '0';
            }
            x = x / 2;
        }
        v.push_back(s);
    }
    for(int i = 0; i < n; i++){
        stack<char> st;
        string s = v[i];
        bool ok = false;
        for(int j = s.size() - 1; j >= 0; j--){
            if(s[j] == '1'){
                st.push('1');
            }
            else{
                if(st.empty()){
                    ok = true;
                    cout << "NO" << endl;
                    break;
                }
                else{
                    st.pop();
                }
            }
        }
        if(!st.empty()){
            cout << "NO" << endl;
        }
        else if(ok == false){
            cout << "YES" << endl;
        }
    }
}