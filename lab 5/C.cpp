#include <iostream>
#include <vector>
using namespace std;
vector<int> v;

struct Heap{
public:
    int parent(int i){
        return (i - 1) / 2;
    }
    int left(int i){
        return i * 2 + 1;
    }
    int right(int i){
        return i * 2 + 2;
    }
    void push(int x){
        v.push_back(x);
        sift_up(v.size() - 1);
    }
    void sift_up(int i){
        while(i > 0 && v[i] > v[parent(i)]){
            swap(v[i],v[parent(i)]);
            i = parent(i);
        }
    }
    void sift_down(int i){
        if(left(i) > v.size() - 1){
            return;
        }
        int child = left(i);
        if(right(i) < v.size() && v[left(i)] < v[right(i)]){
            child = right(i);
        }
        if(v[child] > v[i]){
            swap(v[child], v[i]);
            sift_down(child);
        }
        else{
            return;
        }
    }
    int extractMax(){
        int a = v[0];
        int c;
        if(left(0) < v.size()){
            c = left(0);
        }
        if(right(0) < v.size() && v[right(0)] > v[left(0)]){
            c = right(0);
        }
        v[0]--;
        sift_down(0);
        // print();
        return a;
    }
    void print(){
        for(int i = 0; i < v.size(); i++){
            cout << v[i] << " ";
        }
        cout << endl;
    }
};
int main(){
    Heap heap;
    int n,x;
    cin >> n >> x;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        heap.push(x);
    }
    // heap.print();
    long long sum = 0;
    while(x--){
        int b = heap.extractMax();
        sum += b;
    }
    cout << sum;
}