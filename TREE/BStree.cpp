#include<iostream>
#include<queue>
using namespace std;

class node{
private:
    node* left;
    node* right;
    int data;

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

    bool search(node* rt,int k){
    if(rt==NULL) return false;
    if(rt->data == k) return true;

    if(rt->data > k ) search(rt->left,k);
    else search(rt->right,k);

    }


public:
    tree(){ root=NULL ;}

    node* build(node* rt,int d){
        if(rt==NULL) return new node(d);

        if(d < rt->data ) rt->left=build(rt->left,d);  /// jab tak mein kuch return hi nahi karunga
        else rt->right=build(rt->right,d);    /// tab tak muje left aur right mein kuch nahi milega

        return rt;          ///isliye meine return rt kar diya

    }

    node* build1(node* &rt,int d){
    if(rt==NULL) return new node(d);

    if(rt->data >d ) build(rt->left,d);
    else build(rt->right,d);

        return rt;
    }

    void build(){
      int arr[10]={15,8,9,21,19,28, 2, 7, 14,25 };
        for(int i=0;i<10;i++){
            root=build(root,arr[i]);
            ///root=build1(root,arr[i]);
            }
    }

    node* build1(node* rt,int* arr,int si,int ei){
        if(si>=ei) return NULL;
        int mid=( si+ei )/2;
        rt=new node(arr[mid]);
        rt->left=build1(rt->left,arr,si,mid);
        rt->right=build1(rt->right,arr,mid+1,ei);

        return rt;
    }


    void fillsortedarr(){
        int arr[10]={ 2   ,7,   8  , 9 ,    14  ,15 , 19   ,21   ,25,   28};

        root=build1(root,arr,0,9);
        ///root=build2(root,arr,0,9);

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

    void searchk(int k){
        cout<<"Element "<<k<<" STATUS : "<<search(root,k)<<endl;
    }


    node* deletenode(node* rt,int k){
        if(rt==NULL) return NULL;

        if(rt->data == k){

            if(rt->left ==NULL && rt->right== NULL) {
                delete rt; return NULL;
            }
            if(rt->left==NULL && rt->right != NULL){
                node* temp=rt->right;
                delete rt; return temp;
            }
            if(rt->left!=NULL && rt->right == NULL){
                node* temp=rt->left;
                delete rt; return temp;
            }
            if(rt->left!=NULL && rt->right != NULL){
                node* temp=rt->left;
                while(temp->right != NULL) temp=temp->right;
                swap (rt->data, temp->data);

                rt->left= deletenode(rt->left,k);
                /*delete temp;
                temp=NULL;
                return rt;*/
            }

        }
        else{
            if(rt->data > k) rt->left=deletenode(rt->left,k);
            else rt->right=deletenode(rt->right,k);
        }

    return rt;
    }

    void deletenode(int d){
        root=deletenode(root,d);
        print();

    }
};

int main(){
tree t;
///t.build();
t.fillsortedarr();
t.print();

t.searchk(3);
t.searchk(21);

///t.deletenode(25);
t.deletenode(15);
///t.deletenode(28);


}


///15 8 9 21 19 28 2 7 14 25
