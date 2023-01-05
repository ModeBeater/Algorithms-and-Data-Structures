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
int arr[100000];
int j = 0;
int cnt1 = 0;
int cnt2 = 0;
int cnt = 0;
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
    void check(Node* cur){
        if(cur -> left){
            cnt1++;
            check(cur -> left);
        }
        if(cur -> right){
            cnt2++;
            check(cur -> right);
        }
    }
    void check_left(Node* cur){
        if(cur != NULL){
            cnt1++;
            check_left(cur -> left);
        }
    }
    void check_right(Node* cur){
        if(cur != NULL){
            cnt2++;
            check_right(cur -> right);
        }
    }
    void inOrder(Node * cur){
        if(cur != NULL){
            if(cur -> left && cur -> right){
                arr[0]++;
                check_left(cur -> left);
                check_right(cur -> right);
                if(cnt1 > cnt2){
                    cnt1 = cnt2;
                }
                else if(cnt2 > cnt1){
                    cnt2 = cnt1;
                }
                while(cnt1 > 1){
                    arr[cnt1 - 1]++;
                    cnt1--;
                }
                cnt1 = 0;
                cnt2 = 0;
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
    // cout << endl;
    for(int i = 0; i < n - 1; i++){
        cout << arr[i] << " ";
    }
}