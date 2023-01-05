#include <iostream>
#include <vector>
using namespace std;
vector<long long int> v;
struct Heap{
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
    void push(long long int x){
        v.push_back(x);
        sift_up(v.size() - 1);
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
            swap(v[child], v[i]);
            sift_down(child);
        }
    }
    long long int extractMin(){
        long long int ans = v[1];
        swap(v[1],v[v.size() - 1]);
        v.pop_back();
        if(v.size() > 0){
            sift_down(1);
        }
        return ans;
    }
};
int main(){
    Heap heap;
    int n,c;
    cin >> n >> c;
    v.push_back(-922337203685477580);
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        heap.push(x);
    }
    // for(int i = 0; i < v.size(); i++){
    //     cout << v[i] << " ";
    // }
    int cnt = 0;
    while(v[1] < c){
        long long int a = heap.extractMin();
        long long int b = heap.extractMin();
        // cout << v[1] << endl;
        heap.push(a + 2 * b);
        // cout << v[1] << endl;
        if(v.size() == 2){
            cout << -1 << endl;
            return 0;
        }
        cnt++;
    }
    cout << cnt;
}