#include<iostream>
using namespace std;

class node{
private:
    node* next;
    int data;

public:
    node(int d){
        data=d;
        next=NULL;
    }

    friend class linkedlist;

};

class linkedlist{

private:
    node* head;

public:
    linkedlist(){ head=NULL;}

    void insertatbegin(int d){
        node* nn=new node(d);
        nn->next=head;
        head=nn;

    }
    void insertatend(int d){
        if(head==NULL) { insertatbegin(d); return;}

        node* temp=head;
        node* nn=new node(d);


        while(temp->next!=NULL){
            temp=temp->next;
        }

        temp->next=nn;

}
    void print(){
        node* temp=head;

        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;

        }
    }


    node* bubblesort(node* h,node* kahatak){
        if(h==kahatak||h->next==kahatak) return h;

        node* p=NULL, *c=h, *n=h->next;

        while(c->next!=kahatak){
            n=c->next;
            if(c->data>n->data){
                    if(p==NULL) h=n;
                    else { p->next=n; }
                c->next=n->next;
                n->next=c;
                p=n;
            }

          else{  p=c;
                 c=n;
              }
            }
         return bubblesort(h,c);
    }

   void bubblesort(){
    head=bubblesort(head,NULL);
   }


};

int main(){
    int n; cin>>n;
    linkedlist l;
    for(int i=1;i<=n;i++){
        int k; cin>>k;
        l.insertatend(k);
    }

    l.bubblesort();

    return 0;

}
