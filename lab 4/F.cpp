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
int cnt = 0;
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
    void check(Node* cur){
        if(cur != NULL){
            if(cur -> left && cur -> right){
                cnt++;
            }
            check(cur -> left);
            check(cur -> right);
        }
    }
public:
    BST(){
        root = NULL;
    }
    void push(int val){
        root = push(root, val);
    }
    void check(){
        check(root);
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
    tree.check();
    cout << cnt;
}