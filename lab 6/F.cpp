#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
vector<pair<pair<string,string>, double> > v;
int partition(int low, int high){
    double pivot = v[high].second;
    int i = low - 1;
    for(int j = low; j <= high - 1; j++){
        if(v[j].second < pivot){
            i++;
            swap(v[i], v[j]);
        }
        else if(v[j].second == pivot){
            if(v[j].first.first < v[high].first.first){
                swap(v[j],v[high]);
                pivot = v[high].second;
            }
            else if(v[j].first.first == v[high].first.first){
                if(v[j].first.second < v[high].first.second){
                    swap(v[j],v[high]);
                    pivot = v[high].second;
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
        string a,b;
        cin >> a >> b;
        int m;
        cin >> m;
        double total = 0;
        double sum = 0;
        double credits = 0;
        for(int j = 0; j < m; j++){
            double mark = 0;
            string c;
            cin >> c;
            double d;
            cin >> d;
            if(c[0] == 'F'){
                total += 0;
                credits += d;
                continue;
            }
            if(c[0] == 'A'){
                mark += 3.75;
                if(c[1] == '+'){
                    mark += 0.25;
                }
                mark = mark * d;
                total += mark;
                credits += d;
                continue;
            }
            if(c.size() == 2){
                mark += 0.5;
            }
            if(c[0] == 'B'){
                mark += 3;
            }
            if(c[0] == 'C'){
                mark += 2;
            }
            if(c[0] == 'D'){
                mark += 1;
            }
            mark = mark * d;
            total += mark;
            credits += d;
        }
        sum = total / credits;
        // string ans = a + " " + b;
        v.push_back(make_pair(make_pair(a,b),sum));
    }
    quickSort(0, n - 1);
    for(int i = 0; i < v.size(); i++){
        cout << v[i].first.first << " " << v[i].first.second << " " << fixed << setprecision(3) << v[i].second << endl;
    }
    // cout << setprecision(3) << 1.11245 << endl;
}