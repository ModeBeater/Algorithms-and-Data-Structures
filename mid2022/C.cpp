#include <iostream>
#include <vector>

using namespace std;
vector<int> v;
class Heap{
public:
    int parent(int i){
        return (i - 1) / 2;
    }
    int left(int i){
        return (i * 2) + 1;
    }
    int right(int i){
        return (i * 2) + 2;
    }
    void push(int val){
        v.push_back(val);
        sift_up(v.size() - 1,0);
    }
    void sift_up(int i,int b){
        while(i > 0 && v[i] > v[parent(i)]){
            swap(v[parent(i)], v[i]);
            i = parent(i);
        }
        if(b == 1){
            cout << i + 1 << endl;
        }
    }
    void sift_down(int i){
        if(left(i) > v.size() - 1){
            return;
        }
        int child = left(i);
        if(right(i) < v.size() && v[right(i)] > v[left(i)]){
            child = right(i);
        }
        if(v[child] < v[i]){
            swap(v[child], v[i]);
            sift_down(child);
        }
    }
    void increase(int a,int b){
        v[a - 1] += b;
        sift_up(a - 1,1);
    }
};


int main(){
    int n;
    cin >> n;
    Heap heap;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        heap.push(x);
    }
    int k;
    cin >> k;
    while(k--){
        int a,b;
        cin >> a >> b;
        heap.increase(a,b);
    }
    for(int i = 0; i < n; i++){
        cout << v[i] << ' ';
    }
}