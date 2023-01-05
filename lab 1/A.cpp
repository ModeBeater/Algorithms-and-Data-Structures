#include <iostream>
#include <deque>
#include <stack>
#include <queue>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        queue<int> q;
        vector<int> a(1005);
        for(int i = 1; i <= n; i++){
            q.push(i);
        }
        int i = 1;
        while(!q.empty()){
            int j = 0;
            while(j < i){
                int x = q.front();
                q.pop();
                q.push(x);
                j++;
            }
            int x = q.front();
            if(a[x] != 0){
                cout << -1 << endl;
                return 0;
            }
            a[x] = i;
            q.pop();
            i++;
        }
        for (int i = 1; i <= n; i ++){
            cout << a[i] << " ";
        }
        cout << endl;
    }

}