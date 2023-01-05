#include <iostream>
using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int val){
        this->val = val;
        left = right = NULL;
    }
};
class BST{
    Node * root;

    Node* push(Node * cur, int val){
        if (cur == NULL) {
            return new Node(val);
        }
        if (val < cur -> val) cur -> left = push(cur -> left, val);
        if (val > cur -> val) cur -> right = push(cur -> right, val);
        return cur;
    }
    void check(Node * cur){
        if(cur != NULL){
            cout << cur -> val << " ";
            check(cur -> left);
            check(cur -> right);
        }
    }
    void find(Node * cur,int x){
        if(cur != NULL){
            if(cur -> val == x){
                check(cur);
                return;
            }
            find(cur -> left,x);
            find(cur -> right,x);
        }
    }
    void inOrder(Node * cur ){
        if (cur != NULL){
            inOrder(cur -> left);
            cout << cur -> val << endl;
            inOrder(cur -> right);
        }
    }
public:
    BST(){
        root = NULL;
    }
    void push(int val){
        root = push(root, val);
    }
    void find(int x){
        find(root,x);
    }
    void inOrder(){
        inOrder(root);
    }
};

int main() {
    BST tree;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        tree.push(x);
    }
    int x;
    cin >> x;
    tree.find(x);
}