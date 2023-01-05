#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int val){
        this->val = val;
        left = right = NULL;
    }
};
int max1 = 0;
int cnt = 0;
class BST{
    Node * root;

    Node* push(Node * cur, int val){
        if (cur == NULL) {
            // v[0] = val;
            return new Node(val);
        }
        if (val < cur -> val){
            cnt++;
            cur -> left = push(cur -> left, val);
        }
        if (val > cur -> val){
            cnt++;
            cur -> right = push(cur -> right, val);
        }
        if(max1 < cnt){
            max1 = cnt;
        }
        return cur;
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
        v[cnt] += val;
        cnt = 0;
    }
};

int main() {
    BST tree;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        v.push_back(0);
    }
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        tree.push(x);
    }
    cout << max1 + 1 << endl;
    for(int i = 0; i <= max1; i++){
        cout << v[i] << " ";
    }
}