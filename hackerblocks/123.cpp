
#include<iostream>
#include<queue>
using namespace std;
/// 2ways of inputting 4 printing leaves,search,height,maxmin,depthofnode,printatdepthk,noofnodes,nodnode>k

class node{
private:
    int data;
    node *left;
    node *right;
    int subsum;
public:
    node(int d=0){
        data=d;
        left=NULL;
        right=NULL;
        subsum=0;
    }
    friend class tree;
};

class tree{
 private:
    node* root;

    bool searching(int k,node* rt){
        return rt->data==k || searching(k,rt->left) || searching(k,rt->right);
    }

 public:
    tree(){  root=NULL; }

    node* build2(){
        int d; cin>>d;
        if(d==-1) return NULL;
        node* rt=new node(d);
        rt->left=build2();
        rt->right=build2();

        return rt;

    }

    void build(){

        root=build2();

    }

    int sub(node* rt){
        if(rt==NULL) return 0;

        rt->subsum=sub(rt->left)+sub(rt->right);
        return rt->data+rt->subsum;

    }

    void sub(){
        int temp=root->data;
        root->data=sub(root);
        root->data=temp;
    }

    void levelorder1(){
    if(root==NULL) return;
    queue<node*>q;
    q.push(root);
    q.push(NULL);

        while(q.empty()!=1){
            node* temp=q.front();
            q.pop();

            if(temp!=NULL){
                if(temp->data==-2) cout<<"-     ";
                else{
                cout<<temp->data<<"     ";
                if(temp->left!=NULL) q.push(temp->left);
                if(temp->left==NULL) q.push(new node(-2));

                if(temp->right!=NULL) q.push(temp->right);
                if(temp->right==NULL) q.push(new node(-2));
                    }
                }
            else{   cout<<endl;
                    if(q.empty()!=1) q.push(NULL);
                }

        }
    }

    void levelorder(){
    if(root==NULL) return;
    queue<node*>q;
    q.push(root);
    q.push(NULL);

        while(q.empty()!=1){
            node* temp=q.front();
            q.pop();

            if(temp!=NULL){
                if(temp->data==-2) cout<<"-     ";
                else{
                cout<<temp->data<<"="<<temp->subsum<<"     ";
                if(temp->left!=NULL) q.push(temp->left);
                if(temp->left==NULL) q.push(new node(-2));

                if(temp->right!=NULL) q.push(temp->right);
                if(temp->right==NULL) q.push(new node(-2));
                    }
                }
            else{   cout<<endl;
                    if(q.empty()!=1) q.push(NULL);
                }

        }
    }

};
int main(){
tree t;
t.build();

t.levelorder1();
t.sub();
t.levelorder();

}
///pre 1 2 4 -1 7 10 -1 -1 -1 -1 3 5 8 -1 11 -1 -1 -1 6 -1 9 12 -1 -1 13 -1 -1
