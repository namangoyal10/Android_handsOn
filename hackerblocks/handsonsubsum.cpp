#include<bits/stdc++.h>
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

    void build(node* rt){   /// my_way
        int d;
        cin>>d;
        if(d!=-1) { rt->left=new node(d);
                    build(rt->left);
                  }
        cin>>d;
        if(d!=-1) { rt->right=new node(d);
                    build(rt->right);
                  }
    }


    int sub(node* rt){
        if(rt==NULL) return 0;

        rt->subsum=sub(rt->left)+sub(rt->right);
        return rt->data+rt->subsum;

    }

    void sub(){
        root->data=sub(root);
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
