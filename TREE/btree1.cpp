#include<iostream>
#include<queue>
using namespace std;
                    ///input x 2 , printing x 4 , height, element ki depth, print all leaves, print all elements at depth k

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


    void build(node* rt){ ///majorly in backtrack we are doing some work
        int d; cin>>d;
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


    void loinput(){
        queue<node*>q;
        int d; cin>>d;
        root=new node(d);
        q.push(root);

        while(q.empty()!=1){
            node* temp=q.front();
            q.pop();

            cin>>d;
            if(d!=-1) {temp->left=new node(d); q.push(temp->left);}
            cin>>d;
            if(d!=-1) {temp->right=new node(d); q.push(temp->right);}

        }
     }


    void inorder(node* rt){
        if(rt==NULL) return;

        inorder(rt->left);
        cout<<rt->data<<"   ";
        inorder(rt->right);
    }

    void preorder(node* rt){
        if(rt==NULL) return;

        cout<<rt->data<<"   ";
        inorder(rt->left);
        inorder(rt->right);
    }

    void postorder(node* rt){
        if(rt==NULL) return;

        inorder(rt->left);
        inorder(rt->right);
        cout<<rt->data<<"   ";
    }

    void levelorder(){
        queue<node*>q;
        q.push(root);
        q.push(NULL);

        while(!q.empty()){
            node* temp=q.front();
            q.pop();

            if(temp!=NULL){
                    if(temp->data==-2){
                     cout<<"-   ";
                    }
                    else{
                cout<<temp->data<<"     ";
                node* nn=new node(-2);
                if(temp->left!=NULL) q.push(temp->left);
                if(temp->left==NULL) q.push(nn);
                if(temp->right!=NULL) q.push(temp->right);
                if(temp->right==NULL) q.push(nn);
                    }
            }
            else{
                cout<<endl;
                if(q.empty()==1) return;
                q.push(NULL);
            }

        }
    }

    void print(){
        cout<<"INORDER :  ";
        inorder(root); cout<<endl;

        cout<<"PREORDER :  ";
        preorder(root); cout<<endl;

        cout<<"POSTORDER :  ";
        postorder(root); cout<<endl;

        cout<<"LEVEL ORDER: "<<endl;
           levelorder(); cout<<endl;
    }

    void printleaves(node* rt){
            if(rt==NULL) return;

        if(rt->left==NULL && rt->right==NULL) cout<<rt->data<<"    ";
        printleaves(rt->left);
        printleaves(rt->right);

    }

    void printleaves(){
        cout<<"LEAVES OF THE TREE ARE : ";
        printleaves(root);
        cout<<endl;
    }

    int height(node* rt){
         if(rt==NULL) return 0;

         return max(height(rt->left),height(rt->right))+1;
    }
    void height(){
        cout<<"height"<<height(root)<<endl;
    }

    int maximum(node* rt){
            if(rt==NULL) return INT_MIN;
            int mymax=rt->data;
            int tempmax=max(maximum(rt->left),maximum(rt->right));
            return max(mymax ,tempmax);
    }

    void maximum(){
        cout<<"MAX : "<<maximum(root)<<endl;;
    }

    int depthofnode(node* rt,int d,int cur_depth){
        if(rt==NULL) return -1;
        if(rt->data==d) return cur_depth;

        int ldepth=depthofnode(rt->left,d,cur_depth+1);
        if(ldepth!= -1 ) return ldepth;

        else return depthofnode(rt->right,d,cur_depth+1);
    }

    void depthofnode(int d){
        cout<<"Depth of node : "<<d<<" = "<<depthofnode(root,d,0)<<endl;
    }

    void printatdepthk(node* rt,int k,int cur_depth){
            if(rt==NULL) return ;
            if(cur_depth>k) return;
            if(cur_depth==k) cout<<rt->data<<"      ";
            printatdepthk(rt->left,k,cur_depth+1);
            printatdepthk(rt->right,k,cur_depth+1);

    }

    void printatdepthk(int k){
        cout<<"AT DEPTH "<<k<<" THE ELEMENTS ARE : ";
        printatdepthk(root,k,0);
        cout<<endl;
    }

    int noofnodes(node* rt){
        if(rt==NULL) return 0;
        return 1+noofnodes(rt->left)+noofnodes(rt->right);
    }

     void noofnodes(){
        cout<<"TOTAL NODES = "<<noofnodes(root)<<endl;

     }


     int noofnodesgreaterthank(node* rt,int k){
        if(rt==NULL) return 0;
        int my_value=0;
        if(rt->data >= k) my_value=1;
        return my_value+noofnodesgreaterthank(rt->left,k)+noofnodesgreaterthank(rt->right,k);
     }


     void noofnodesgreaterthank(int k){
        cout<<noofnodesgreaterthank(root,k);
     }
};

int main(){

    tree t;
    t.build();
   // t.loinput();
    t.print();
    t.printleaves();
    t.height();
    t.maximum();
    t.depthofnode(9);
    t.printatdepthk(2);
    t.noofnodes();
    t.noofnodesgreaterthank(3);
}
///1 2 4 -1 8 -1 -1 5 -1 -1 3 6 -1 9 -1 -1 7 -1 -1
