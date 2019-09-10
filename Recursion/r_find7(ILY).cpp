#include<iostream>
using namespace std;

int firstr(int* arr,int n,int i,int search){
    if(i==n) return -1;
    if(arr[i]==search) return i;
    firstr(arr,n,i+1,search);
}
void firstb(int* arr,int n,int i,int search,int &index){
    if(i==n)  return;
    firstb(arr,n,i+1,search,index);
    if(arr[i]==search) index=i;
}

void allindex(int* arr,int n,int i,int search){
    if(i==n){ cout<<endl<<"ALL INDEX BACK TO FRONT = "; return;}
    if(arr[i]==search) cout<<i<<" ";
    allindex(arr,n,i+1,search);
    if(arr[i]==search) cout<<i<<" ";
}
int main(){
    int n; cin>>n;
    int* arr= new int[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int search; cin>>search;

    cout<<"First elements = "<<endl;
    cout<<firstr(arr,n,0,search)<<endl;
    int index=-1;
    firstb(arr,n,0,search,index);
    cout<<index<<endl;;

    cout<<"ALL INDEX front to back = ";
    allindex(arr,n,0,search);
}
