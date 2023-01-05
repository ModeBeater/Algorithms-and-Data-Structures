#include <iostream>
#include <vector>
#include <cmath>
#include <deque>
using namespace std;
bool ok[100500] = {false};

int main(){
    deque<int> q;
    int a,b;
    cin >> a >> b;
    if(a == b){
        cout << 0;
        return 0;
    }
    q.push_back(a);
    ok[a] = true;
    vector<int> v(100500);
    vector<int> ans;
    int i = 0;
    while(true){
        int to1 = q.front() * 2;
        int to2 = q.front() - 1;
        if(ok[to1] == false && to1 > 0 && to1 < 10000){
            v[to1] = q.front();
            q.push_back(to1);
            ok[to1] = true;
        }
        if(ok[to2] == false && to2 < 10000){
            v[to2] = q.front();
            q.push_back(to2);
            ok[to2] = true;
        }
        if(to1 == b){
            ans.push_back(to1);
            to1 = to1 / 2;
            if(to1 != a){
                ans.push_back(to1);
            }
            if(to1 == a){
                break;
            }
            while(v[to1] != a){
                ans.push_back(v[to1]);
                to1 = v[to1];
            }
            break;
        }
        if(to2 == b){
            ans.push_back(to2);
            to2++;
            if(to2 != a){
                ans.push_back(to2);
            }
            if(to2 == a){
                break;
            }
            while(v[to2] != a){
                ans.push_back(v[to2]);
                to2 = v[to2];
            }
            break;
        }
        q.pop_front();
    }
    cout << ans.size() << endl;
    for(int i = ans.size() - 1; i >= 0; i--){
        cout << ans[i] << " ";
    }
}