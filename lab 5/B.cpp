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
        if(right(i) < v.size() - 1 && v[left(i)] < v[right(i)]){
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
        int c = left(0);
        if(right(0) < v.size() - 1 && v[right(0)] > v[left(0)]){
            c = right(0);
        }
        int ans = v[0] - v[c];
        swap(v[0], v[v.size() - 1]);
        swap(v[c], v[v.size() - 2]);
        v.pop_back();
        v.pop_back();
        return ans;
    }
};
int main(){
    Heap heap;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        heap.push(x);
    }
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    while(v.size() > 1){
        int b = heap.extractMax();
        heap.push(b);
        for(int i = 0; i < v.size(); i++){
            heap.sift_up(i);
        }
    }
    if(v.size() == 1){
        cout << v[0];
    }
    else{
        cout << 0;
    }
    // cout << v[0];
}