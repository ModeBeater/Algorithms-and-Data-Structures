#include <iostream>
#include <vector>
using namespace std;
vector<pair<string,string> > v;
int partition(int low, int high){
    string pivot = v[high].first;
    int i = low - 1;
    for(int j = low; j <= high - 1; j++){
        if(v[j].first < pivot){
            i++;
            swap(v[i], v[j]);
        }
    }
    swap(v[i + 1], v[high]);
    return i + 1;
}
void quickSort(int low, int high){
    if(low < high){
        int pi = partition(low, high);
        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
    }
}
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string s,t;
        cin >> s >> t;
        v.push_back(make_pair(s,t));
    }
    for(int i = 0; i < v.size(); i++){
        for(int j = i + 1; j < v.size(); j++){
            if(v[i].second == v[j].first){
                v[i].second = v[j].second;
                int a = j - 1;
                v.erase(v.begin() + j);
                // continue;
                j = a;
            }
        }
    }
    if(v.size() > 1){
        quickSort(0, v.size() - 1);
    }
    // quickSort(0, n - 1);
    cout << v.size() << endl;
    for(int i = 0; i < v.size(); i++){
        cout << v[i].first << " " << v[i].second << endl;
    }
}