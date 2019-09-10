#include<iostream>
#include<queue>
using namespace std;

class Node{
public:
    int data;
    Node* left, *right;

    Node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
};

class BST{
private:
    Node * root;
public:
    BST(){root=NULL;}

    Node* FillBST(Node* rt, int d){
        if (rt==NULL){
            return new Node(d);
        }
        if (d<=rt->data){
            rt->left=FillBST(rt->left,d);
        } else {
            rt->right=FillBST(rt->right,d);
        }
        return rt;
    }

    void FillBST(){

        int n; cin>>n;
        for (int i=0;i<n;i++){
            int d; cin>>d;
             if(d>0 )   root=FillBST(root,d);
        }
    }



    void PrintInOrder(Node* rt,int &highest,int &lower,int &ans){
        if (rt==NULL) return;
        PrintInOrder(rt->left,highest,lower,ans);

        if(highest==-1) {
                highest=rt->data;
                if(highest!=1) ans=1;
                return;
        }
        else{
            lower=highest;
            if (lower!= rt->data-1 || lower!= rt->data) {
                if(ans==-1) {ans=lower;
                return;
                }
            }
            highest=rt->data;
        }

        PrintInOrder(rt->right,highest,ans,lower);
    }

   void PrintInOrder(){///public function
        if(root==NULL) {cout<<1<<endl; return;}
        if(root->left==NULL && root->right==NULL && root->data==1){cout<<2<<endl; return;}

        int ans=-1;

        int highest=-1; int lower;
        PrintInOrder(root,highest,lower,ans);
        cout<<"---------"<<ans<<endl;
        cout<<highest<<endl;
        }

};

int main(){
    int n; cin>>n;
    while(n--){
    BST t;
    t.FillBST();
    t.PrintInOrder();

}
///2 3 7 6 8  -1  -10 15
///2 3 -7 6 8 1 -10 15
}
