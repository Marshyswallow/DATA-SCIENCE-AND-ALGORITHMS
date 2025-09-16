#include<iostream>
using namespace std;

struct Node{
  int data;
  Node* next;
};

void display(struct Node *p){
  while(p!=NULL){
    cout<<p->data<<" ";
    p=p->next;
  }
}
int main(){
  Node* x=new Node();
  x->data=9;
  x->next=NULL;

  display(x);

  
}
