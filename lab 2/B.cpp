#include <iostream>

using namespace std;

struct Node{
    string val;
    Node* next;
    Node* prev;
    Node(string val){
        this -> val = val;
        next = NULL;
        prev = NULL;
    }
};
class LinkedList{
    Node* head;
    Node* tail;
    void cyclicShift(Node * head, int k){
        if(k == 0){
            Node * cur = head;
            while(cur != NULL){
                cout << cur -> val << " ";
                cur = cur -> next;
            }
            return;
        }
        Node* NewNode = new Node(head -> val);
        tail -> next = NewNode;
        NewNode -> prev = tail;
        tail = NewNode;
        Node* temp = head;
        head = temp -> next;
        head -> prev = NULL;
        k--;
        cyclicShift(head,k);
    }
public:
    LinkedList(){
        head = NULL;
        tail = NULL;
    }
    void push(string val){
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
    void cyclicShift(int k){
        cyclicShift(head,k);
    }
    void print(){
        Node* cur = head;
        while(cur != NULL){
            cout << cur -> val << " ";
            cur = cur -> next;
        }
    }
};
int main(){
    int n,k;
    cin >> n >> k;
    LinkedList list;
    while(n--){
        string a;
        cin >> a;
        list.push(a);
    }
    list.cyclicShift(k);
    // list.print();
}