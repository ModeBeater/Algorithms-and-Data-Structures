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
int res = 0;
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
    void inOrder(Node*cur){
        if(cur != NULL){
            if(cur -> right != NULL && cur -> left != NULL){
                res = max(res, height(cur -> left) + height(cur -> right) + 1);
            }
            inOrder(cur -> left);
            inOrder(cur -> right);
        }
    }
    int height(Node* cur){
        if(cur == NULL){
            return 0;
        }
        return max(height(cur -> left),height(cur -> right)) + 1;
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
    void height(){
        res = height(root);
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
    tree.height();
    cout << res << endl;
}