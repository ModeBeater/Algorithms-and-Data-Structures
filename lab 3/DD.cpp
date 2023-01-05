#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
pair<int , int> getRange(int lx, int rx) { 
    pair<int, int> res;
    res.first = -1;
    res.second = -2; 
 
    // if(v.back() < lx || v[0] > rx) 
    //     return res; 
 
    int l = -1, r = v.size()-1; 
 
    while(l + 1 < r) { 
        int mid = (l+r)/2; 
        if(v[mid] >= lx) 
            r = mid; 
        else 
            l = mid; 
    } 
    res.first = r; 
 
    l = 0; 
    r = v.size(); 
 
    while(l + 1 < r) { 
        int mid = (l+r)/2; 
        if(v[mid] <= rx) 
            l = mid; 
        else 
            r = mid; 
    } 
 
    res.second = l - 1; 
 
    return res; 
} 
int main(){
    int n,k;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    while(k--){
        int l1,r1,l2,r2;
        cin >> l1 >> r1 >> l2 >> r2;
        // int l = -1;
        // int r = n - 1;
        // while(l + 1 < r) { 
        //     int mid = (l+r)/2; 
        //     if(v[mid] >= l1) 
        //         r = mid; 
        //     else 
        //         l = mid; 
        // } 
        // l1 = r;
        // l = 0;
        // r = n;
        // while(l + 1 < r) { 
        //     int mid = (l+r)/2; 
        //     if(v[mid] <= r1) 
        //         l = mid; 
        //     else 
        //         r = mid; 
        // }
        // r1 = l - 1;
        // cout << l1 << " " << r1 << endl;
        cout << getRange(l1,r1).first << " " << getRange(l1,r1).second << endl;
        cout << getRange(l2,r2).first << " " << getRange(l2,r2).second << endl;
    }
}