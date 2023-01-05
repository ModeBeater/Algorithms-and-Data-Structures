#include <iostream>
#include <vector>
using namespace std;
vector<long long int> v;
class Heap{
public:
    int parent(int i){
        return i / 2;
    }
    int left(int i){
        return i * 2;
    }
    int right(int i){
        return i * 2 + 1;
    }
    void sift_up(int i){
        while(i > 0 && v[i] < v[parent(i)]){
            swap(v[parent(i)], v[i]);
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
            swap(v[child],v[i]);
            sift_down(child);
        }
    }
    long long int extractMin(){
        long long int ans = v[1];
        swap(v[1], v[v.size() - 1]);
        v.pop_back();
        if(v.size() > 0){
            sift_down(1);
        }
        return ans;
    }
    void push(long long int x){
        v.push_back(x);
        sift_up(v.size() - 1);
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
    int n;
    cin >> n;
    v.push_back(-922337203685477580);
    for(int i = 0; i < n; i++){
        long long int x;
        cin >> x;
        heap.push(x);
    }
    unsigned long long sum = 0;
    while(v.size() > 2){
        long long int a = heap.extractMin();
        long long int b = heap.extractMin();
        sum += a + b;
        heap.push(a + b);
    }
    cout << sum;
}