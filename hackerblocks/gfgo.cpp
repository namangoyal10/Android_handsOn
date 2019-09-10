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
            root=FillBST(root,d);
        }
    }

    void printit(queue<int> q){
        while(q.empty()!=1){
            cout<<q.front()<<endl;
            q.pop();
        }
    }

    void PrintInOrder(Node* rt,queue<int> &q,int &spn){
        if (rt==NULL) return;
        PrintInOrder(rt->left,q,spn);
        ///cout<<rt->data<<" ";

        if(rt->data >0) q.push(rt->data);

        PrintInOrder(rt->right,q,spn);
    }

   void PrintInOrder(int &ans){///public function

        queue<int>q;
        //cout<<"InOrder:";
        int spn;
        PrintInOrder(root,q,spn);
        ///cout<<endl;        printit(q);

        if(q.empty()==1 || q.front() >1) {///cout<<"no pos no ==1 "<<endl;
         ans=1;
         cout<<"we are in 1 case "<<endl;
         return;}
        q.pop();
        if(q.empty()==1 ) {
          ///  cout<<"top element was 1 ==2 ";
          cout<<"we are in 2 case "<<endl;
            ans=2;
            return;
        }

        int lower=1,higher=q.front();
        while(higher-1 == lower || higher == lower){
            lower=higher;
            q.pop();
            if(q.empty()!=1) higher=q.front();
            else break;
        }
        cout<<"we are in 3 case "<<endl;
        //cout<<"lower + "<<lower+1;
        ans=lower+1;

    }

};

int main(){
    int n; cin>>n;
    while(n--){
    BST t;
    t.FillBST();
    ////t.PrintLevelOrder();
    int ans=1;
    t.PrintInOrder(ans);
    cout<<ans<<endl;
}
///2 3 7 6 8  -1  -10 15
///2 3 -7 6 8 1 -10 15
}
