#include<iostream>
using namespace std;
class Node{
public:
    int val;
    Node* next;
    Node(int data){
        val = data;
        next = NULL;
    }
};
void insertAtHead(Node* &head,int data){
    Node* new_node=new Node(data);
    new_node->next=head;
    head=new_node;
};
void insertAtTail(Node* &head,int data){
    Node* new_node=new Node(data);
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    //we reached at tail
    temp->next=new_node;
}
void insertAtGivenPosition(Node* &head,int data,int pos){
    if(pos==0){
        insertAtHead(head,data);
        return;
    }
    Node* new_node=new Node(data);
    Node* temp=head;
    int current_pos=0;
    while(current_pos!=pos-1){
        temp=temp->next;
        current_pos++;
    }
    //temp reaches position where we want to insert
    new_node->next=temp->next;
    temp->next=new_node;
}
void updateAtGivenPosition(Node* &head,int value,int k){
    if(k==0){
        head->val=value;
        return;
    }
    Node* temp=head;
    int current_pos=0;
    while(current_pos!=k){
        temp=temp->next;
        current_pos++;
    }
    //temp will be pointing to kth position
    temp->val=value; 
}
void deleteHead(Node* &head){
    Node* temp=head;//node to be deleted
    head=temp->next;
    free(temp);
}
void deleteAtTail(Node* &head){
    Node* second_last=head;
    while(second_last->next->next!=NULL){
        second_last=second_last->next;
    }
    Node* temp=second_last->next;//node to be deleted
    second_last->next=NULL;
    free(temp);
}
void deleteAtGivenPosition(Node* &head,int k){
    if(k==0){
        deleteHead(head);
        return;
    }
    Node* prev=head;
    int current_pos=0;
    while(current_pos!=k-1){
        prev=prev->next;
        current_pos++;
    }
    Node* temp=prev->next;//node to be deleted
    prev->next=prev->next->next;
    free(temp);
}
int size(Node* head){
    Node* temp=head;
    int count=1;
    while(temp->next!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}
void display(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->val<<" -> ";
        temp=temp->next;
    }
    cout<<"NULL"<<"\n";
}
int main(){
    Node* head=NULL;
    insertAtHead(head,2);
    display(head);
    insertAtHead(head,1);
    display(head);
    insertAtTail(head,3);
    display(head);
    insertAtTail(head,4);
    display(head);
    insertAtGivenPosition(head,5,2);
    display(head);
    insertAtGivenPosition(head,6,3);
    display(head);
    insertAtGivenPosition(head,10,0);
    display(head);
    updateAtGivenPosition(head,20,3);
    cout<<"size"<<" "<<size(head)<<"\n";
    display(head);
    deleteHead(head);
    display(head);
    deleteAtTail(head);
    display(head);
    deleteAtGivenPosition(head,2);
    display(head);
    cout<<"size"<<" "<<size(head)<<"\n";
}