#include<iostream>
using namespace std;

class Node{
  public:
  int data;
  Node* next;
 Node(int data){
    this->data=data;
    this->next =NULL;
  }

  ~Node(){
    int val = this->data;
    if(this->next != NULL){
      delete next;
      this->next = NULL;
    }
    cout<<"Memory is free for node with data "<<val<<endl;
  }
};

// insertion of node after a given element

void insertNode(Node*& tail,int element, int data){
  if(tail == NULL) {
      Node* newNode = new Node(data); 
      tail = newNode;
      newNode->next = newNode; // Point to itself
      return;
  }
  else{
    Node *newNode = new Node(data);
    Node* curr = tail;
    while(curr->data != element){
      curr = curr->next;
    }

    newNode->next = curr->next;
    curr->next = newNode;
  }
 
}

void print(Node* tail){
  if(tail == NULL){
    cout<<"List is empty"<<endl;
    return;
  }
  Node* temp = tail;
  do{
    cout<<tail->data<<" ";
    tail = tail->next;
  }while(tail != temp);
  cout<<endl;
}

void deleteNode(Node* &tail, int value){
  if(tail == NULL){
    cout<<"List is empty, please check again"<<endl;
    return;
  }
  else{
    Node* prev = tail;
    Node* curr = prev->next;
    while(curr->data != value){
      prev = curr;
      curr = curr->next;
    }
    prev->next = curr->next;

    // 1 node linked list
    if(curr == prev){
      tail = NULL;
    }
    // >=2 node linked list
    else if(tail == curr){
      tail = prev;
    }
    curr->next = NULL;
    delete curr;
  }
}
