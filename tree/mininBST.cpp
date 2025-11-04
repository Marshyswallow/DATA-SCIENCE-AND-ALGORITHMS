#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

Node* insert(Node* root, int key) {
    if (!root) return new Node(key);
    if (key < root->data) root->left = insert(root->left, key);
    else root->right = insert(root->right, key);
    return root;
}

Node* findMin(Node* root) {
    while (root && root->left) root = root->left;
    return root;
}

Node* findMax(Node* root) {
    while (root && root->right) root = root->right;
    return root;
}

Node* findPredecessor(Node* root, int key) {
    Node* pre = NULL;
    while (root) {
        if (key <= root->data) root = root->left;
        else {
            pre = root;
            root = root->right;
        }
    }
    return pre;
}

Node* findSuccessor(Node* root, int key) {
    Node* suc = NULL;
    while (root) {
        if (key >= root->data) root = root->right;
        else {
            suc = root;
            root = root->left;
        }
    }
    return suc;
}

int main() {
    Node* root = NULL;
    vector<int> vals = {20, 8, 22, 4, 12, 10, 14};
    for (int v : vals) root = insert(root, v);

    Node* mn = findMin(root);
    Node* mx = findMax(root);
    Node* pre = findPredecessor(root, 10);
    Node* suc = findSuccessor(root, 10);

    cout << "Min: " << mn->data << endl;
    cout << "Max: " << mx->data << endl;
    if (pre) cout << "Predecessor of 10: " << pre->data << endl;
    else cout << "No predecessor\n";
    if (suc) cout << "Successor of 10: " << suc->data << endl;
    else cout << "No successor\n";
}
