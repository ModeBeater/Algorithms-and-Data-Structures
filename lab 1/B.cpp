#include <iostream>
#include <deque>
using namespace std;

int main(){
    int n;
    cin >> n;
    deque<int> dq;
    deque<int> ans;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        dq.push_back(x);
    }
    ans.push_back(-1);
    for(int i = 1; i < dq.size(); i++){
        int j = i - 1;
        while(j >= 0){
            if(dq[j] <= dq[i]){
                ans.push_back(dq[j]);
                break;
            }
            if(j == 0){
                ans.push_back(-1);
            }
            j--;
        }
    }
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
}