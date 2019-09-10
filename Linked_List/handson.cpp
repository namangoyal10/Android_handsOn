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
    friend class LinkedList;
};

class LinkedList{
private:
    node* head;

public:
    LinkedList(){ head=NULL; }

    void insertatbegin(int d){
        if(head==NULL){
            head=new node(d);
            return;
        }
        node* nn=new node(d);
        nn->next=head;
        head=nn;
    }


    void insertatend(int d){
        if(head==NULL){
            insertatbegin(d);
        }

        node* temp=head;
        while(temp->next!=NULL) temp=temp->next;

        temp->next=new node(d);
    }


    void insertatpos(int d,int k){
        int count=1;
        node* temp=head;

        while(count<k-1){
            if(temp==NULL) {insertatend(d);
                cout<<"out of bounds"<<endl;
                        return;  }
            count++;
            temp=temp->next;
        }
    node* nn=new node(d);
    nn->next=temp->next;
    temp->next=nn;
    }


    void deleteatbegin(){
        if(head==NULL) return;
        node* temp=head;
        head=head->next;
        cout<<"Data deleted = "<<temp->data<<" from begining . "<<endl;
        delete temp;
      }


    void deleteatend(){
        if(head==NULL) return;
        node* temp=head;
        while(temp->next->next!=NULL) temp=temp->next;
        node* nn=temp->next;
        temp->next=NULL;
        cout<<"Data deleted = "<<nn->data<<" from end . "<<endl;
        delete nn;

    }

    void deleteatpos(int pos){
        if(head==NULL ) return;
        if(pos==1) {deleteatbegin(); return;}

    int count=1;
    node* temp=head;
    while(count<pos-1){

            temp=temp->next;
            if(temp==NULL){
                deleteatend();
                return;
            }
            count++;
        }
        node* nn=temp->next;
        temp->next=nn->next;
        cout<<"Data deleted = "<<nn->data<<" from pos "<<pos<<endl;
        delete nn;
    }


    void print(){
        node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<"  ";
            temp=temp->next;
        }
        cout<<endl;
    }

    void reverse(){
    if(head==NULL) return;

    node* c=head,*p=NULL,*n;

    while(c!=NULL){
        n=c->next;
        c->next=p;
        p=c;
        c=n;
    }
    head=p;
    print();
    }

    void mid(){
        node *slow=head,*fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
    cout<<"Mid : "<<slow->data<<endl;
    }


    void merge(LinkedList l2){
        node* temp1=head,*temp2=l2.head;
        if(temp1->data > temp2->data){
                swap(temp1,temp2);
        }
        node* p=temp1;
        temp1=temp1->next;

        while(temp1!=NULL && temp2!=NULL){
                if(temp2->data < temp1->data ){
                    node* nn=new node(temp2->data);
                    nn->next=temp1;
                    p->next=nn;

                    p=p->next;
                    temp2=temp2->next;
                }

                else{ p=temp1;
                        temp1=temp1->next;

                }

        }

        if(temp1==NULL){
            while(temp2!=NULL){
                node* nn=new node(temp2->data);
                temp1->next=nn;
                temp2=temp2->next;
            }
        }


    }

    void createcycle(int pos){
        node* temp=head,*temp1;
        int count=1;
        while(temp->next!=NULL){
            if(count==pos) temp1=temp;
            count++;
            temp=temp->next;
        }

        temp->next=temp1;
        cout<<temp->data<<"     "<<temp->next->data<<endl;
    }

    void detectcycle(){
        node* slow=head,*fast=head;

        while(slow!=fast){
            slow=slow->next;
            fast=fast->next->next;
        }
        if(slow==fast) cout<<"done  ";
        slow=head;

        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
        }
        cout<<slow->data<<endl;
    }



};

int main(){
    LinkedList l,l1,l2;
    l.insertatbegin(5);
    l.insertatbegin(4);
    l.insertatbegin(2);
    l.insertatbegin(1);
    l.insertatbegin(0);
    l.insertatend(6);
    l.insertatpos(3,4);
    l.insertatpos(7,77);

    l.print();

    l.deleteatbegin();
    l.deleteatend();
    l.deleteatpos(4);
    l.print();

    l.insertatpos(4,4);
    l.reverse();
    l.reverse();

    l.mid();
    l.insertatpos(7,23);
    l.print();
    l.mid();
    l.createcycle(3);

    l.detectcycle();

    l1.insertatbegin(14);
    l1.insertatbegin(9);
    l1.insertatbegin(5);
    l1.insertatbegin(2);
    l1.insertatbegin(1);

    l2.insertatbegin(12);
    l2.insertatbegin(11);
    l2.insertatbegin(8);
    l2.insertatbegin(4);
    l2.insertatbegin(3);


    l1.merge(l2);
    l1.print();
}
///cycle detect is wrong approach
