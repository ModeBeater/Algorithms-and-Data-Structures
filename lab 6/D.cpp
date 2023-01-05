#include <iostream>
#include <vector>
using namespace std;
vector<pair<string,pair<string,string> > > v;

int partition(int low, int high){
    string pivot = v[high].first;
    int i = low - 1;
    for(int j = low; j <= high - 1; j++){
        if(v[j].first < v[high].first){
            i++;
            swap(v[i], v[j]);
        }
        else if(v[j].first == pivot){
            if(v[j].second.first < v[high].second.first){
                swap(v[j],v[high]);
                pivot = v[high].first;
            }
            else if(v[j].second.first == v[high].second.first){
                if(v[j].second.second < v[high].second.second){
                    swap(v[j], v[high]);
                    pivot = v[high].first;
                }
            }
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
        string s;
        cin >> s;
        string d;
        string m;
        d += s[0];
        d += s[1];
        m += s[3];
        m += s[4];
        string y;
        for(int j = 6; j < s.size(); j++){
            y += s[j];
        }
        v.push_back(make_pair(y, make_pair(m,d)));
    }
    quickSort(0, n - 1);
    for(int i = 0; i < v.size(); i++){
        cout << v[i].second.second << "-" << v[i].second.first << "-" << v[i].first << endl;
    }
}