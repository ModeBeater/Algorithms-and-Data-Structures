#include <iostream>
#include <iomanip>
using namespace std;
void mergeSortOne(string last[], string first[], double gpa[], string temp_last[], string temp_first[], double temp_gpa[],int l, int mid, int r){
    int i,j,k;
    i = l;
    j = mid + 1;
    k = l;
    while(i <= mid && j <= r){
        if(gpa[i] < gpa[j]){
            temp_first[k] = first[i];
            temp_gpa[k] = gpa[i];
            temp_last[k] = last[i];
            i++;
            k++;
        }
        else if(gpa[i] == gpa[j]){
            if(last[i] < last[j]){
                temp_first[k] = first[i];
                temp_gpa[k] = gpa[i];
                temp_last[k] = last[i];
                i++;
                k++;
            }
            else if(last[i] == last[j]){
                if(first[i] < first[j]){
                    temp_first[k] = first[i];
                    temp_gpa[k] = gpa[i];
                    temp_last[k] = last[i];
                    i++;
                    k++;
                }
                else{
                    temp_first[k] = first[j];
                    temp_gpa[k] = gpa[j];
                    temp_last[k] = last[j];
                    j++;
                    k++;
                }
            }
            else{
                temp_first[k] = first[j];
                temp_gpa[k] = gpa[j];
                temp_last[k] = last[j];
                j++;
                k++;
            }
        }
        else{
            temp_first[k] = first[j];
            temp_gpa[k] = gpa[j];
            temp_last[k] = last[j];
            j++;
            k++;
        }
    }
    for(; i <= mid; i++){
        temp_first[k] = first[i];
        temp_gpa[k] = gpa[i];
        temp_last[k] = last[i];
        k++;
    }
    for(; j <= r; j++){
        temp_first[k] = first[j];
        temp_gpa[k] = gpa[j];
        temp_last[k] = last[j];
        k++;
    }
    for(i = l; i <= r; i++){
        first[i] = temp_first[i];
        last[i] = temp_last[i];
        gpa[i] = temp_gpa[i];
    }
}
void mergeSort(string last[], string first[], double gpa[], string temp_last[], string temp_first[], double temp_gpa[],int l, int r){
    if(l < r){
        int mid = l + (r - l) / 2;
        mergeSort(last, first, gpa, temp_last, temp_first, temp_gpa,l,mid);
        mergeSort(last, first, gpa, temp_last, temp_first, temp_gpa,mid + 1, r);
        mergeSortOne(last, first, gpa, temp_last, temp_first, temp_gpa,l,mid,r);
    }
}
int main(){
    int n;
    cin >> n;
    string last[n];
    string first[n];
    double gpa[n];
    string temp_last[n];
    string temp_first[n];
    double temp_gpa[n];
    for(int i = 0; i < n; i++){
        string a,b;
        cin >> last[i] >> first[i];
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
        gpa[i] = sum;
    }
    mergeSort(last, first, gpa, temp_last, temp_first, temp_gpa,0, n - 1);
    for(int i = 0; i < n; i++){
        cout << last[i] << " " << first[i] << " " << fixed << setprecision(3) << gpa[i] << endl;
    }
}