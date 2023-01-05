#include <iostream>

using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int val){
        this-> val = val;
        left = right = NULL;
    }
};
int sum = 0;
class BST{
    Node* root;
    Node* push(Node*cur,int val){
        if(cur == NULL){
            return new Node(val);
        }
        if(cur -> val < val){
            cur -> right = push(cur -> right, val);
        }
        if(cur -> val > val){
            cur -> left = push(cur -> left, val);
        }
        return cur;
    }
    void inOrder(Node* cur){
        if(cur != NULL){
            if(cur -> left == NULL && cur -> right == NULL){
                sum++;
            }
            inOrder(cur -> left);
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
    void inOrder(){
        inOrder(root);
    }
};

int main(){
    int n;
    cin >> n;
    BST tree;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        tree.push(x);
    }
    tree.inOrder();
    cout << sum;
}