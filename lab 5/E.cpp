#include <iostream>
#include <vector>

using namespace std;
int m;
vector<int> v;
struct Heap{
    int parent(int i){
        return i / 2;
    }
    int left(int i){
        return i * 2;
    }
    int right(int i){
        return i * 2 + 1;
    }
    void push(int x){
        if(v.size() - 1 < m){
            v.push_back(x);
            sift_up(v.size() - 1);
        }
        else{
            check(x);
        }

    }
    void sift_up(int i){
        while(i > 0 && v[i] < v[parent(i)]){
            swap(v[i],v[parent(i)]);
            i = parent(i);
        }
    }
    void sift_down(int i){
        if(left(i) > v.size() - 1){
            return;
        }
        int child = left(i);
        if(right(i) < v.size() && v[left(i)] > v[right(i)]){
            child = right(i);
        }
        if(v[child] < v[i]){
            swap(v[i],v[child]);
            sift_down(child);
        }
    }
    void check(int x){
        int a = extractMax(x);
        if(a != 0){
            v.push_back(x);
            sift_up(v.size() - 1);
        }
    }
    int extractMax(int x){
        int ans = v[1];
        if(x > ans){
            swap(v[1],v[v.size() - 1]);
            v.pop_back();
            if(v.size() > 1){
                sift_down(1);
            }
            return x;
        }
        else{
            return 0;
        }
    }
};
int main(){
    Heap heap;
    int n;
    cin >> n >> m;
    v.push_back(-999999999);
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        if(s == "print"){
            if(v.size() == 1){
                cout << 0 << endl;
            }
            else{
                long long sum = 0;
                for(int j = 1; j <= m; j++){
                    if(j == v.size()){
                        break;
                    }
                    // cout << v[j] << " ";
                    sum += v[j];
                }
                cout << sum << endl;
            }
        }
        if(s == "insert"){
            int x;
            cin >> x;
            heap.push(x);
        }
    }
}