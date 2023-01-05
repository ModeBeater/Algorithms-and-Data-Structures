#include <bits/stdc++.h>
using namespace std;


class Heap{
    long long int a[200005];
public:
    int size;
    Heap() {
        size = 0;
        a[0] = LONG_LONG_MIN;
    }
    int parent(int i) {
        return i/2;
    }
    
    int left(int i) {
        return i*2;
    }

    int right(int i) {
        return i * 2 + 1;
    }

    void sift_up(int i) {
        while(i > 0 && a[parent(i)] > a[i]) {
            swap(a[parent(i)], a[i]);
            i = parent(i);
        }
    }

    void insert(long long int val) {
        size++;
        a[size] = val;
        sift_up(size);
    }

    void heapify(int i) {
        int l = left(i);
        int r = right(i);
        int minChild = left(i);
        if(l > size) return;
        if(r <= size) {
            if(a[r] < a[l]) minChild = r;
        }
        if(a[i] > a[minChild]) {
            swap(a[i], a[minChild]);
            heapify(minChild);
        }
    }

    long long int ExtractMin() {
        long long int ans = a[1];
        swap(a[1], a[size]);
        size--;
        if(size > 0) heapify(1);
        return ans;
    }
};


int main() {
    Heap heap;
    int n;
    cin>>n;
    for(int i=0;i<n;i++) {
        long long int x;
        cin>>x;
        heap.insert(x);
    }

    long long int sum = 0;
    while(heap.size > 1) {
        long long int a = heap.ExtractMin();
        long long int b = heap.ExtractMin();
        sum += a + b;
        heap.insert(a + b);
    }
    cout<<sum<<endl;
    return 0;
}