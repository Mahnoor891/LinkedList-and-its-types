#include<iostream>
#include<stdlib.h>
using namespace std;
struct Node {
    int data;
    Node *next;
     Node *prev;

};
Node *head = NULL;
void insertAtBeginning(int val) {
 Node* temp = (Node*)malloc(sizeof(Node));
 if(temp == NULL){
    cout<<"Memory allocation failed";
    return;
 }
 temp-> data = val;
 temp->prev = NULL;
temp->next = head;
if(head !=NULL){
     head->prev = temp;
}
 head = temp; 
cout<< "Inserted "<< val << " at beginning"<< endl;
}
void insertAtEnd(int val){
    Node*temp = (Node*)malloc(sizeof(Node));
    temp->data = val;
    temp->next = NULL;
    if(head ==NULL){
        temp->prev = NULL;
        head = temp;
        cout<<" Inserted " << val << " at end "<< endl;
        return;
    }
    // traverse to last node
    Node*curr = head;
    while(curr->next!= NULL){
        curr = curr->next;
    }
    // Linking last node with first node
    curr->next= temp;
    temp->prev = curr;
    cout<<"Inserted "<< val <<" at end"<< endl;
}
void Search(int val){
    Node*curr = head;
    int position = 1;
    while(curr!=NULL){
        if(curr->data == val){
        cout<< "Value " << val << " Found at position: "<< position << endl;
        return;
    }
    curr = curr->next;
    position ++;
}
cout<< " Value not found";
}
void Delete(int val){
    if(head == NULL){
        cout<< "The list is empty";
        return;
    }
    Node*curr= head;
    if(val == curr->data){
    head = head->next;
    head->prev = NULL;
    cout<< "\nDeleted first node: "<<curr->data <<",";
    free(curr);
    return;
}
Node* prev = head;
while(curr!= NULL){
    if(val == curr->data){
        prev->next = curr->next;
        free(curr);
        return;
    }
    prev = curr;
    curr= curr->next;
}
}
void DisplayForward() {
    if(head== NULL){
        cout<<"The list is empty";
        return;
    }
    cout<<"List Backward traversing";
    cout<<"\nList";
    Node*curr= head;
    while(curr!= NULL){
        cout<< curr->data ;
    if(curr->next != NULL){
        cout<<"<->";
    }
    curr = curr->next;
}
    cout<<" <-> NULL\n";
}
void DisplayBackward() {
    Node*curr = head;
    while(curr->next!= NULL){
        curr = curr->next;
    }
    
    while(curr!=NULL){
        cout<<curr->data;
        if(curr->prev != NULL){
            cout<< "<->";
        }
        curr = curr->prev;
    }
    cout<<" <-> NULL"<<endl;
}
    
int main () {
    while(true) {
        int choice;
        cout<<"\n1.Insert at beginning";
        cout<<"\n2.Insert at end";
        cout<<"\n3.Search";
        cout<<"\n4.Delete";
        cout<<"\n5.Display Forward";
        cout<<"\n6.Display Backward";
        cout<< "\n Enter your choice: ";
        cin>>choice;
        int data;
        switch(choice) {
            case 1:
            cout <<"\nEnter the value to insert: ";
            cin>>data;
            insertAtBeginning(data);
            break;
            case 2: 
            cout<< "Enter the data to insert: ";
            cin>> data;
            insertAtEnd(data);
            break;
            case 3:
            cout<< "\n Enter the value to search: ";
            cin>> data;
            Search(data);
            break;
            case 4: 
            cout<< "\n Enter the value to delete: ";
            cin>>data;
            Delete(data);
            break;
            case 5:
            cout<< "\n Displaying forward data: ";
            DisplayForward();
            break;
            case 6:
            cout<<"\n Displaying backward data: ";
            DisplayBackward();
            break;
            default:
            cout<< "\n Invalid data!";
            break;
    }
}
return 0;
}

