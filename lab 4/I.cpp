#include <iostream>
using namespace std;

struct Node{
    int val;
    int count;
    Node* left;
    Node* right;
    Node(int val){
        this->val = val;
        count = 1;
        left = right = NULL;
    }
};
int cnt = 0;
bool ok = true;
class BST{
    Node * root;

    Node* push(Node * cur, int val){
        if (cur == NULL) {
            return new Node(val);
        }
        if(cur -> val == val){
            cur -> count++;
        }
        if (val < cur -> val) cur -> left = push(cur -> left, val);
        if (val > cur -> val) cur -> right = push(cur -> right, val);
        return cur;
    }
    Node* minValue(Node* cur){
        while(cur && cur -> left != NULL){
            cur = cur -> left;
        }
        return cur;
    }
    void check(Node* cur, int x){
        if(cur != NULL){
            if(cur -> val == x && cur -> count != 0){
                cout << cur -> count << endl;
                ok = false;
                return;
            }
            check(cur -> left,x);
            check(cur -> right,x);
        }
    }
    Node* deleteNode(Node* cur, int key){
        if(cur = NULL){
            return cur;
        }
        if(key < cur -> val){
            cur -> left = deleteNode(cur -> left, key);
        }
        else if(key > cur -> val){
            cur -> right = deleteNode(cur -> right, key);
        }
        else{
            if(cur -> left == NULL){
                Node* temp = cur -> right;
                delete(cur);
                return temp;
            }
            else if(cur -> right == NULL){
                Node* temp = cur -> left;
                delete(cur);
                return temp;
            }
            Node* temp = minValue(cur -> right);
            cur -> val = temp -> val;
            cur -> right = deleteNode(cur-> right, temp -> val);
        }
        return cur;
    }
    void inOrder(Node* cur){
        if(cur != NULL){
            cout << cur -> val << " ";
            inOrder(cur -> left);
            inOrder(cur -> right);
        }
    }
    void deleting(Node * cur, int x){
        if(cur != NULL){
            if(cur -> val == x){
                cur -> count--;
                // if(cur -> count == 0){
                //     deleteNode(cur,x);
                // }
            }
            deleting(cur -> left, x);
            deleting(cur -> right,x);
        }
    }
    // Сделай это через Парент 
public:
    BST(){
        root = NULL;
    }
    void push(int val){
        root = push(root, val);
        // a -> count++;
    }
    void check(int x){
        check(root,x);
        if(ok == true){
            cout << 0 << endl;
        }
        ok = true;
    }
    void inOrder(){
        if(root != NULL){
            inOrder(root);
        }
    }
    void deleting(int x){
        deleting(root,x);
    }
    void deleteNode(int x){
        deleteNode(root,x);
    }
};

int main() {
    BST tree;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        if(s == "insert"){
            int x;
            cin >> x;
            tree.push(x);
        }
        if(s == "cnt"){
            int x;
            cin >> x;
            tree.check(x);
        }
        if(s == "delete"){
            int x;
            cin >> x;
            tree.deleting(x);
        }
    }
    // tree.inOrder();
}