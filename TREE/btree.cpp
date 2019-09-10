#include<iostream>
#include<queue>
using namespace std;

class node{
private:
    int data;
    node* left;
    node* right;

public:
    node(int d=0){
        data=d;
        left=NULL;
        right=NULL;
    }
    friend class tree;
};

class tree{
private:
     node* root;
public:
    tree(){ root=NULL;}

    void build(node* rt){
        int d;
        cin>>d;
        if(d!=-1) {rt->left=new node(d);
                    build(rt->left);
                 }
      cin>>d;
        if(d!=-1) {rt->right=new node(d);
                    build(rt->right);
                 }
    }

    void build(){
    int d; cin>>d;
    root=new node(d);
    build(root);
    }



    void levelorderprint(){

    if(root==NULL) return;
     queue<node*>q;
     q.push(root);
     q.push(NULL);
        cout<<root->data<<" "<<endl   ;

    while(!q.empty()){
            node* temp=q.front();
            q.pop();

            if(temp!=NULL){
                if(temp->left!=NULL){cout<<temp->left->data<<" ";
                q.push(temp->left);
                }

                if(temp->right!=NULL){cout<<temp->right->data<<" ";
                q.push(temp->right);
                }
            }

            else{ if(!q.empty()) {cout<<endl;
                q.push(NULL);}
                }
            }
        }

};

int main(){
tree t;
t.build();
t.levelorderprint();


}
