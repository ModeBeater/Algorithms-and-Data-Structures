#include <iostream>
#include <vector>

using namespace std;
vector<int> v;
int cnt = 0;
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
        sift_up(v.size() - 1);
    }
    void sift_up(int i){
        while(i > 0 && v[i] > v[parent(i)]){
            swap(v[parent(i)], v[i]);
            i = parent(i);
        }
    }
    void check(int i){
        if(left(i) > v.size() - 1){
            return;
        }
        if(right(i) < v.size()){
            if(v[left(i)] < v[right(i)]){
                cnt++;
            }
        }
        check(left(i));
        check(right(i));
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
    heap.check(0);
    cout << cnt;
    // for(int i = 0; i < n; i++){
    //     cout << v[i] << ' ';
    // }
}