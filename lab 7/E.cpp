#include <iostream>
#include <vector>

using namespace std;
vector<pair<vector<long long int>, long long int> > v;


void mergeSortOne(int l, int mid, int r){
    int i,j,k;
    i = l;
    j = mid + 1;
    k = l;
    vector<pair<vector<long long int>, long long int> > b(r + 1);
    while(i <= mid && j <= r){
        if(v[i].second > v[j].second){
            b[k] = v[i];
            i++;
            k++;
        }
        else if(v[i].second < v[j].second){
            b[k] = v[j];
            j++;
            k++;
        }
        else if(v[i].second == v[j].second){
            for(int c = 0; c < v[j].first.size(); c++){
                if(v[i].first[c] < v[j].first[c]){
                    b[k] = v[i];
                    k++;
                    i++;
                    c = v[j].first.size();
                }
                else if(v[i].first[c] > v[j].first[c]){
                    b[k] = v[j];
                    k++;
                    j++;
                    c = v[j].first.size();
                }
                else if(c == v[j].first.size() - 1){
                    b[k] = v[i];
                    k++;
                    i++;
                    c = v[j].first.size();
                }
            }
        }
    }
    for(; i <= mid; i++){
        b[k] = v[i];
        k++;
    }
    for(; j <= r; j++){
        b[k] = v[j];
        k++;
    }
    for(i = l; i <= r; i++){
        v[i] = b[i];
    }
}
void mergeSort(int l, int r){
    if(l < r){
        int mid = (l + r) / 2;
        mergeSort(l,mid);
        mergeSort(mid + 1, r);
        mergeSortOne(l,mid,r);
    }
}



int main(){
    int n,m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        long long int sum = 0;
        vector<long long int> a;
        for(int j = 0; j < m; j++){
            long long int x;
            cin >> x;
            a.push_back(x);
            sum += x;
        }
        v.push_back(make_pair(a,sum));
    }
    mergeSort(0, n - 1);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << v[i].first[j] << " ";
        }
        cout << endl;
    }
}