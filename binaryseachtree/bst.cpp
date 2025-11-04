#include <iostream>
using namespace std;

class Node
{
public:
  int data;
  Node *left;
  Node *right;

  Node(int d)
  {
    this->data = d;
    this->left = NULL;
    this->right = NULL;
  }
};

bool Rsearch(Node *t, int key)
{
  if (t == NULL)
  {
    return false;
  }

  if (key == t->data)
  {
    return true;
  }

  else if (key > t->data)
    return Rsearch(t->right, key);
  else
    return Rsearch(t->left, key);
}

// Inorder Traversal (left->Node->right)
void inorder(Node *root)
{
  if (root == nullptr)
    return;
  inorder(root->left);
  cout << root->data << " ";
  inorder(root->right);
}

// Preorder Traversal (Root → Left → Right)
void preorder(Node *root)
{
  if (root == nullptr)
    return;
  cout << root->data << " ";
  preorder(root->left);
  preorder(root->right);
}

// Postorder Traversal (Left → Right → Root)
void postorder(Node *root)
{
  if (root == nullptr)
    return;
  postorder(root->left);
  postorder(root->right);
  cout << root->data << " ";
}

Node *insertIntoBst(Node *&root, int d)
{
  if (root == NULL)
  {
    root = new Node(d);
    return root;
  }

  if (d > root->data)
    root->right = insertIntoBst(root->right, d);

  else
    root->left = insertIntoBst(root->left, d);

  return root;
}

void inputData(Node *&root)
{
  int data;
  cin >> data;
  while (data != -1)
  {
    insertIntoBst(root, data);
    cin >> data;
  }
}

int main()
{
  Node *root = NULL;
  cout << "enter elements to create bst" << endl;
  inputData(root);
  cout << "tree traversal: ";
  inorder(root);

  cout << endl
       << "searching for data: ";
  int key;
  cin >> key;
  Rsearch(root, key) == 1 ? cout << "true" : cout << "false";
}