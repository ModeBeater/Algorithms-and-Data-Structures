#include <iostream>

using namespace std;

struct Node{
    int val;
    Node* next;
    Node* prev;
    Node(int val){
        this -> val = val;
        next = NULL;
        prev = NULL;
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
    // void clear(){
    //     Node* cur = head;
    //     while(cur != NULL && cur -> next != NULL){
    //         Node* temp = cur -> next;
    //         cur -> next = cur -> next -> next;
    //         cur -> next -> prev = cur;
    //         delete temp;
    //         cur = cur -> next;
    //     }
    // }
    void print(){
        Node* slow = head;
        Node* fast = head -> next;
        while(fast != NULL || slow != NULL){
            cout << slow -> val << " ";
            if(fast -> next == NULL){
                return;
            }
            slow = fast -> next;
            while(fast != slow -> next){
                fast = fast -> next;
                if(fast -> next == NULL){
                    cout << slow -> val << " ";
                    return;
                }
            }
        } 
        // Node* cur = head;
        // while(cur != NULL){
        //     cout << cur -> val << " ";
        //     cur = cur -> next;
        // }
    }
};

int main(){
    int n;
    cin >> n;
    LinkedList list;
    while(n--){
        int x;
        cin >> x;
        list.push(x);
    }
    // list.clear();
    list.print();
}