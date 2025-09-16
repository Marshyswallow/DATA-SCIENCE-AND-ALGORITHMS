#include<iostream>
using namespace std;

class Node{
  public:
  int data;
  Node* prev;
  Node* next;
  Node(int data){
    this->data = data;
    this->prev = NULL;
    this->next = NULL;
  } 
};


void getLength(Node* head){
  Node* temp = head;
  int len = 0;
  while(temp != NULL){
    len++;
    temp = temp->next;
  }
  cout<<"Length: "<<len<<endl;
}


void insertAtHead(Node* &head, int data){

  if(head == NULL) {
      Node* newNode = new Node(data);
      head = newNode;
      return;
  }
  Node* newNode = new Node(data);
  newNode->next = head;
  if(head != NULL){
    head->prev = newNode;
  }
  head = newNode;
}

void insertAtTail(Node* &tail, int data){
  if(tail == NULL) {
      Node* newNode = new Node(data);
      tail = newNode;
      return;
  }
  Node* newNode = new Node(data);
  tail->next = newNode;
  newNode->prev = tail;
  tail = newNode;
}

void printList(Node* head){
  Node* temp = head;
  while(temp != NULL){
    cout<<temp->data<<" ";
    temp = temp->next;
  }
  cout<<endl;
}

void insertAtPosition(Node* &head, Node* &tail, int position, int data){
  if(position == 1){
    insertAtHead(head, data);
    return;
  }

  Node* temp = head;
  int count = 1;

  while(count < position - 1 && temp != NULL){
    temp = temp->next;
    count++;
  }

  if(temp == NULL || temp->next == NULL){
    insertAtTail(tail, data);
    return;
  }

  Node* newNode = new Node(data);
  newNode->next = temp->next;
  newNode->prev = temp;
  temp->next->prev = newNode;
  temp->next = newNode;
}

void deleteNode(Node* &head, int position){
  if(position == 1){
    Node* temp = head;
    head = head->next;
    if(head != NULL){
      head->prev = NULL;
    }
    delete temp;
    return;
  }

  Node* curr = head;
  Node* prev = NULL;
  int count = 1;

  while(count < position && curr != NULL){
    prev = curr;
    curr = curr->next;
    count++;
  }

  if(curr == NULL){
    return; // Position is out of bounds
  }

  prev->next = curr->next;
  if(curr->next != NULL){
    curr->next->prev = prev;
  }
  delete curr;    
    
}


int main(){
  Node* node1 = new Node(10);
  Node* head = node1;
  Node* tail = node1;

  insertAtPosition(head, tail, 1, 20);
  printList(head);
  cout<<"Head: "<<head->data<<endl;
  cout<<"Tail: "<<tail->data<<endl;

  insertAtTail(tail, 30);
  printList(head);
  cout<<"Head: "<<head->data<<endl;
  cout<<"Tail: "<<tail->data<<endl;

  insertAtPosition(head, tail, 2, 25);  
  printList(head);
  cout<<"Head: "<<head->data<<endl;
  cout<<"Tail: "<<tail->data<<endl;

  insertAtPosition(head, tail, 4, 5);
  printList(head);
  cout<<"Head: "<<head->data<<endl;
  cout<<"Tail: "<<tail->data<<endl;


  insertAtTail(tail, 40);
  printList(head);
  cout<<"Head: "<<head->data<<endl;
  cout<<"Tail: "<<tail->data<<endl;
  
  return 0;
}