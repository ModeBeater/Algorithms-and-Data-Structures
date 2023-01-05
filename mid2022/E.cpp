#include <iostream>
#include <stack>
using namespace std;


int main(){
    int n;
    cin >> n;
    int max1 = 0;
    stack<int> st;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        if(s == "add"){
            int x;
            cin >> x;
            st.push(x);
            if(x > max1){
                max1 = x;
            }
        }
        if(s == "delete"){
            if(!st.empty()){
                if(st.top() == max1){
                    st.pop();
                    max1 = 0;
                    stack<int> temp;
                    while(!st.empty()){
                        if(st.top() > max1){
                            max1 = st.top();
                        }
                        temp.push(st.top());
                        st.pop();
                    }
                    while(!temp.empty()){
                        st.push(temp.top());
                        temp.pop();
                    }
                }
                else{
                    st.pop();
                }
            }
        }
        if(s == "getcur"){
            if(!st.empty()){
                cout << st.top() << endl;
            }
            else{
                cout << "error" << endl;
            }
        }
        if(s == "getmax"){
            if(!st.empty()){
                cout << max1 << endl;
            }
            else{
                cout << "error" << endl;
            }
        }
    }
}