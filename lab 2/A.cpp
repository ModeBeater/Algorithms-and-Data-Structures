#include <iostream>
#include <cmath>
using namespace std;
int ans = 0;
struct Node{
    int val;
    Node* next;
    Node* prev;
    Node(int val){
        this->val = val;
        this->prev = NULL;
        this->next = NULL;
    }
};
class LinkedList{
public:
    Node* head = NULL;
    Node* tail = NULL;
    void push(int val){
        Node* NewNode = new Node(val);
        if(head == NULL){
            head = tail = NewNode;
        }
        else{
            tail -> next = NewNode;
            NewNode -> prev = tail;
            tail = NewNode;
        }
    }
    void find(int x){
        Node* cur = head;
        int dif = 1000000;
        int cnt = 0;
        while(cur != NULL){
            if(abs(cur -> val - x) < dif){
                dif = abs(cur -> val - x);
                ans = cnt;
            }
            if(cur -> val == x){
                ans = cnt;
                break;
            }
            cnt++;
            cur = cur -> next;
        }
    }
};

int main(){
    int n;
    cin >> n;
    LinkedList list;
    while(n--){
        int a;
        cin >> a;
        list.push(a);
    }
    int x;
    cin >> x;
    list.find(x);
    cout << ans;
}