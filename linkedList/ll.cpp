#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next; 
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }   
};

void insertAtHead(Node* &head, int data) {
    if(head == NULL) {
        Node* newNode = new Node(data);
        head = newNode;
        return;
    }
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

void insertAtTail(Node* &tail, int data) {
    if(tail == NULL) {
        Node* newNode = new Node(data);
        tail = newNode;
        return;
    }
    Node* newNode = new Node(data);
    tail->next = newNode;
    tail = newNode;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAtPosition(Node* &head, Node* &tail, int position, int data) {
    if (position == 1) {
        insertAtHead(head, data);
        return;
    }
    
    Node* temp = head;
    int count = 1;
    
    while (count < position - 1 && temp != NULL) {
        temp = temp->next;
        count++;
    }
    
    if (temp == NULL || temp->next == NULL) {
        insertAtTail(tail, data);
        return;
    }
    
    Node* newNode = new Node(data);
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteNode(Node* &head, int position) {
    if (position == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    
    Node* curr = head;
    Node* prev = NULL;
    int count = 1;
    
    while (count < position && curr != NULL) {
        prev = curr;
        curr = curr->next;
        count++;
    }
    
    if (curr == NULL) return; // Position is out of bounds
    
    prev->next = curr->next;
    delete curr;
}

void deleteNodeByValue(Node* &head, int value) {
    if (head == NULL) return;
    
    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    
    Node* curr = head;
    Node* prev = NULL;
    
    while (curr != NULL && curr->data != value) {
        prev = curr;
        curr = curr->next;
    }
    
    if (curr == NULL) return; // Value not found
    
    prev->next = curr->next;
    delete curr;
}
