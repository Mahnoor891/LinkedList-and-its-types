
#include<iostream>
#include<stdlib.h>
using namespace std;
// Circular Linked List
struct Node {
    int data;
    Node *next;
};
Node*head = NULL;
void insert(int val) {
    Node*newNode = (Node*) malloc(sizeof(Node));
    newNode->data = val;
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    }
    else {
        Node*temp = head;
        while(temp->next != head){
            temp = temp ->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
}
void display() {
    if(head == NULL) {
        cout <<"List is empty";
        return;
    }
    Node*temp = head;
    do {
        cout<< temp->data << "->";
        temp = temp ->next;
    }
    while( temp != head);
    cout<<temp->data;
}
void search(int val){
    if(head == NULL){
        cout<< "\n List is empty";
        return;
    }
    Node *temp = head;
    int pos = 1;
    do
     {
    if (temp->data == val) {
        cout << "\nValue found at position: " << pos;
        return;
    }
    temp = temp->next;
    pos++;
} 
while(temp != head);
cout << "\n Value not found";
}
void Delete (int val) {
    // case 1 : Empty list
    if(head == NULL) {
        cout<< "\n Not possible as list is empty.";
        return;
    }
    Node*curr = head;
    Node*prev = NULL;
    // deleting head node
    if(head->data == val) {
        if(head->next == head){
            free(head);
            head = NULL;
            return;
        }
        // If multiple nodes, find the last node
        while(curr->next != head){
            curr = curr->next;
        }

    
    Node*temp = head;
    head = head->next; // Move head to next node
    curr->next = head;  // Last node now points to new head
    free(temp);         // Free old head
    return;
}
prev = head;
curr = head->next;
do {
    if(curr->data == val){
        prev ->next = curr->next;
        free(curr);
        cout<<"\n Node deleted successfully";
        return;
    }
    prev = curr;
    curr = curr->next;
} while(curr!= head);
cout<< "\nValue not found in the list";
}
int main() {
    while(true) {

    int choice ;
    int data;
    cout<< "\n1. Insert";
     cout<< "\n2. Search";
     cout<< "\n3. Delete";
     cout<< "\n4. Display";
     cout<< "\n5. Exit";
     cout<< "\nEnter your choice: ";
     cin>> choice;
     
    
    // menu driven program


    switch(choice) {
        case 1: 
            cout<< " Enter value to insert: ";
            cin>> data;
            insert(data);
            break; 
        case 2: 
            cout<< "Enter value to search: ";   
            cin>> data;
            search(data);
        break;
        case 3:
            cout<< "Enter value to delete: ";   
            cin>> data;
            Delete(data);
            break; 
        case 4:
            display();
            break; 
        case 5 : cout << "EXITING";
        break;

        default: 
        cout<< "Invalid choice";    
    }
    }
return 0;
}




