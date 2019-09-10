#include<bits/stdc++.h>
using namespace std;
/// 2ways of inputting 4 printing leaves,search,height,maxmin,depthofnode,printatdepthk,noofnodes,nodnode>k

class node{
private:
    int data;
    node *left;
    node *right;
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

    node* build1(node* &rt){ /// game of animations
        int d; cin>>d;
        if(d==-1) return NULL;
        rt=new node(d);
        build1(rt->left);
        build1(rt->right);

        return rt;
    }

    node* build2(){
        int d; cin>>d;
        if(d==-1) return NULL;
        rt->left=build2();
        node* rt=new node(d);
        rt->right=build2();

        return rt;

    }

    void loinput(){
        queue<node*>q;
        int d; cin>>d;
        if(d!=-1){
            root=new node(d);
            q.push(root);
        }
    while(q.empty()!=1){
        node* temp=q.front();
        q.pop();
        cin>>d;
        if(d!=-1){
            temp->left=new node(d);
            q.push(temp->left);
        }
         cin>>d;
        if(d!=-1){
            temp->right=new node(d);
            q.push(temp->right);
        }
    }

    }

    void build(){
       /// int d; cin>>d; if(d!=-1) root=new node(d);
        ///build(root);

        ///root=build1(root);
        root=build2();
        /// loinput();
    }


    void preorder(node* rt){
        if(rt==NULL) return;

        cout<<rt->data<<"   ";
        preorder(rt->left);
        preorder(rt->right);
    }
    void inorder(node* rt){
        if(rt==NULL) return;

        inorder(rt->left);
        cout<<rt->data<<"   ";
        inorder(rt->right);
    }
    void postorder(node* rt){
        if(rt==NULL) return;

        postorder(rt->left);
        postorder(rt->right);
        cout<<rt->data<<"   ";
    }

    void print(){
        cout<<"PREORDER  : ";
        preorder(root); cout<<endl;

        cout<<"INORDER  : ";
        inorder(root); cout<<endl;

        cout<<"POSTORDER : ";
        postorder(root); cout<<endl;

        cout<<"LEVEL ORDER  :"<<endl;
        levelorder();
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

    void search(int k){
        cout<<"SEARCH : "<<k<<" : "<<searching(k,root)<<endl;
    }

    int noofnodes(node* rt){
        if(rt==NULL) return 0;

        return 1+noofnodes(rt->left)+noofnodes(rt->right);
    }

    void noofnodes(){
        cout<<"TOTAL NO OF NODE : "<<noofnodes(root)<<endl;
    }


    int noofnodesgreaterthan(node* rt,int k){
        if(rt==NULL) return 0;
        if(rt->data > k) return 1+noofnodesgreaterthan(rt->left,k)+noofnodesgreaterthan(rt->right,k);
        else return noofnodesgreaterthan(rt->left,k)+noofnodesgreaterthan(rt->right,k);
    }

    void noofnodesgreaterthan(int k){
        cout<<"NO OF NODES > "<<k<<" : "<<noofnodesgreaterthan(root,k)<<endl;
    }

    int maximum(node* rt){
        if(rt==NULL) return INT_MIN;

        int my_max=rt->data;
        int child_max= max ( maximum(rt->left) , maximum(rt->right) );
        return max(my_max,child_max);
    }

    void maximum(){
        cout<<"MAX ELEMENT : "<<maximum(root)<<endl;
    }

    int minimum(node* rt){
        if(rt==NULL) return INT_MAX;

        int my_min=rt->data;
        int child_min= min ( minimum(rt->left) , minimum(rt->right) );
        return min(my_min,child_min);
    }

    void minimum(){
        cout<<"MIN ELEMENT : "<<minimum(root)<<endl;
    }


    int height(node* rt){
        if(rt==NULL) return 0;
        return 1+max(height(rt->left),height(rt->right));
    }

    void height(){
        cout<<"HEIGHT : "<<height(root)<<endl;
    }


    int depthofnode(node* rt,int k,int cur_depth){
        if(rt==NULL) return -1;

        if(rt->data==k) return cur_depth;
        int ans=depthofnode(rt->left,k,cur_depth+1);  /// check left mein k present hai ki nahi
            if(ans!=-1) return ans;
           else return depthofnode(rt->right,k,cur_depth+1); /// then it has to be in right
                                                            /// if it is still not in right it will return int coresp to NULL
        }

    void depthofnode(int k){
        cout<<"DEPTH OF NODE "<<k<<" : "<<depthofnode(root,k,1)<<endl;
    }

    void printatdepth(node* rt,int k,int cur_depth){
        if(rt==NULL) return;
        if(cur_depth > k) return;
        if(cur_depth==k) cout<<rt->data<<"      ";
        printatdepth(rt->left,k,cur_depth+1);
        printatdepth(rt->right,k,cur_depth+1);

    }

    void printatdepth(int k){
        cout<<"DATA AT DEPTH "<<k<<" : ";
        printatdepth(root,k,1);
        cout<<endl;
    }



};

int main(){
    tree t;
    t.build();
    t.print();

    t.search(1);
    t.search(2);

    t.maximum();
    t.minimum();

    t.noofnodes();
    t.noofnodesgreaterthan(9);

    t.height();

    t.depthofnode(5);
    t.printatdepth(3);



}
///lo 1 2 3 4 -1 5 6 -1 7 8 -1 -1 9 10 -1 -1 11 12  13 -1 -1 -1 -1 -1 -1 -1 -1
///pre 1 2 4 -1 7 10 -1 -1 -1 -1 3 5 8 -1 11 -1 -1 -1 6 -1 9 12 -1 -1 13 -1 -1
