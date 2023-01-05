#include <iostream>
#include <vector>
using namespace std;
int n;
int cnt = 0;
vector<string> a;
vector<vector<string> > v(100000);
void mergeSortOne(int a,int l, int mid, int r){
    int i,j,k;
    i = l;
    j = mid + 1;
    k = l;
    string b[r + 1];
    while(i <= mid && j <= r){
        if(v[a][i].size() < v[a][j].size()){
            b[k] = v[a][i];
            i++;
            k++;
        }
        else if(v[a][i].size() > v[a][j].size()){
            b[k] = v[a][j];
            j++;
            k++;
        }
        else{
            b[k] = v[a][i];
            i++;
            k++;
        }
    }
    for(; i <= mid; i++){
        b[k] = v[a][i];
        k++;
    }
    for(; j <= r; j++){
        b[k] = v[a][j];
        k++;
    }
    for(i = l; i <= r; i++){
        v[a][i] = b[i];
    }
}
void mergeSort(int a,int l, int r){
    if(l < r){
        int mid = (l + r) / 2;
        mergeSort(a,l,mid);
        mergeSort(a,mid + 1, r);
        mergeSortOne(a,l,mid,r);
    }
}
void solve(int i){
    string s;
    getline(cin >> ws,s);
    s += " "; 
    string t = "";
    for(int j = 0; j < s.size(); j++){
        if(s[j] == ' '){
            v[i].push_back(t);
            t = "";
        }
        else{
            t += s[j];
        }
    }
    mergeSort(i,0, v[i].size() - 1);
    for(int j = 0; j < v[i].size(); j++){
        cout << v[i][j] << " ";
    }
    cout << endl;
}
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        solve(i);
    }
}