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

    void PrintInOrder(Node* rt,queue<int> &q){
        if (rt==NULL) return;
        PrintInOrder(rt->left,q);

        if(rt->data >0) q.push(rt->data);

        PrintInOrder(rt->right,q);
    }

   void PrintInOrder(){
        queue<int>q;
        PrintInOrder(root,q);


        if(q.empty()==1 || q.front() >1) {
         cout<<1<<endl;
      ///   cout<<"we are in 1 case "<<endl;
         return;}

        q.pop();
        if(q.empty()==1 ) {
          ///  cout<<"top element was 1 ==2 ";
   ///       cout<<"we are in 2 case "<<endl;
            cout<<2<<endl;
            return;
        }

        int lower=1,higher=q.front();
        while(higher-1 == lower || higher == lower){
            lower=higher;
            q.pop();
            if(q.empty()!=1) higher=q.front();
            else break;
        }
///        cout<<"we are in 3 case "<<endl;
        //cout<<"lower + "<<lower+1;
        cout<<lower+1<<endl;

    }

};

int main(){
    int n; cin>>n;
    while(n--){
    BST t;
    t.FillBST();

    t.PrintInOrder();

    }
}
