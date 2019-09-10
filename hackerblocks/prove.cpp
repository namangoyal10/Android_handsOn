#include<iostream>
using namespace std;

class node{
private:
    int data;
    node* next;

public:
    node(int d=0){
        data=d;
        next=NULL;
    }
    friend class linkedlist;
};
class linkedlist{
private:
    node* head;

public:
    linkedlist(){
        head=NULL;
    }

     void insertatbegin(int d){
     if(head==NULL) {
     head=new node(d);
     return;
     }
     node* nn=new node(d);
     nn->next=head;
     head=nn;
     }

     void print(){
        node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<"  ";
            temp=temp->next;
        }
     }
};

int main(){
    linkedlist l;
    l.insertatbegin(5);
    l.insertatbegin(4);
    l.insertatbegin(3);
    l.insertatbegin(2);
    l.insertatbegin(1);
    l.print();
}
