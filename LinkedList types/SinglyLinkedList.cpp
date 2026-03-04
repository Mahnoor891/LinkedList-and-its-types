#include<iostream>
#include<stdlib.h>
using namespace std;
// Singly Linked List
struct Node {
    int data;
    Node *next;
};
Node *list = NULL; // Head Pointer

void insert (int val) {
    Node *temp;
    temp = (Node*)malloc(sizeof(Node));
    temp->data= val;
    temp->next = NULL;
    if(list == NULL) {
        list = temp;
    }
    else {
        Node *cur = list;
        while (cur->next!= NULL){
        cur = cur->next;
    }
     cur->next = temp;
  }
}
void display() {
    Node *cur = list;
    if(cur == NULL){
        cout<< "\nList is empty";
        return;
    }
    cout<< "\nLinked List: ";
    while(cur != NULL) {
        cout<<cur->data<<"->";
    cur = cur-> next;
    }
    cout<<"NULL\n";
}
void search(int val){
    Node *cur = list;
    int pos = 1;
    while(cur != NULL) {
    if (cur->data == val) {
        cout << "\nValue found at position: " << pos;
        return;
    }
    cur == cur->next;
    pos++;
}
cout << "\n Value not found";
}
void Delete (int val) {
    if(list == NULL) {
        cout<< "\n Not possible as list is empty.";
        return;
    }
    Node *cur = list;
    if(val == list->data)
    {
        list = list->next;
        free(cur);
        return;
    }
    Node *prev = list;
    cur = list->next;
    while(cur!= NULL) {
        if(val == cur->data){
        prev -> next = cur ->next;
        free(cur);
        return;
        }
        cur = cur-> next;
        prev = prev->next;
    }
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
    if(choice==5) 
    break;
}
return 0;
}





