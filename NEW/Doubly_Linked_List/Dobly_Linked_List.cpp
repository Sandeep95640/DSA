
#include<iostream>
using namespace std;

class Node{
    public:
    int val;
    Node* prev;
    Node* next;
    Node(int data){
        val=data;
        prev=NULL;
        next=NULL;
    }
};
class DoublyLinkedList{
    public:
    Node* head;
    Node* tail;
    DoublyLinkedList(){
        head=NULL;
        tail=NULL;
    }
    void insertAtHead(int data){
        Node* new_node=new Node(data);
        if(head==NULL){
            head=new_node;
            tail=new_node;
            return;
        }
        head->prev=new_node;
        new_node->next=head;
        head=new_node;
    }
    void insertAtTail(int data){
        Node* new_node=new Node(data);
        if(tail==NULL){
            head=new_node;
            tail=new_node;
            return;
        }
        tail->next=new_node;
        new_node->prev=tail;
        tail=new_node;
    }
    void insertAtGivenPosition(int data,int pos){
        if(pos==1){
            insertAtHead(data);
            return;
        }
        Node* new_node=new Node(data);
        Node* temp=head;
        int current_pos=1;
        while(current_pos!=pos-1){
            temp=temp->next;
            current_pos++;
        }
        new_node->next=temp->next;
        temp->next->prev=new_node;
        temp->next=new_node;
        new_node->prev=temp;
    }
    void deleteHead(){
        if(head==NULL){
            return;
        }
        Node* temp=head;
        head=temp->next;
        if(head==NULL){
            tail=NULL;
        }
        else{
            head->prev=NULL;
        }
        free(temp);
    }
    void deleteTail(){
        if(tail==NULL){
            return;
        }
        Node* temp=tail;
        tail=temp->prev;
        if(tail==NULL){
            head=NULL;
        }
        else{
            tail->next=NULL;
        }
        free(temp);
    }
    void deleteAtGivenPosition(int pos){
        if(pos==1){
            deleteHead();
            return;
        }
        Node* temp=head;
        int current_pos=1;
        while(current_pos!=pos){
            temp=temp->next;
            current_pos++;
        }
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        free(temp);
    }
    void display(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->val<<" <-> ";
            temp=temp->next;
        }
        cout<<"\n";
    }
};
int main(){
    DoublyLinkedList dll;
    dll.insertAtHead(4);
    dll.insertAtHead(3);
    dll.insertAtHead(2);
    dll.display();
    dll.insertAtHead(1);
    dll.display();
    dll.insertAtTail(5);
    dll.insertAtTail(6);
    dll.display();
    dll.insertAtGivenPosition(10,4);//inserting at 4th position
    dll.display();
    dll.insertAtGivenPosition(100,1);
    dll.display();
    dll.deleteHead();
    dll.deleteHead();
    dll.display();
    dll.deleteTail();
    dll.display();
    dll.deleteAtGivenPosition(3);
    dll.display();
    dll.deleteAtGivenPosition(1);
    dll.display();
}