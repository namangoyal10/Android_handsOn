#include<iostream>
using namespace std;

void givemeans(int* arr,int n,int i,int sum,int &d){
    if(i==n){
        if(sum==0) d++;
        return;
    }

    givemeans(arr,n,i+1,sum,d);

    sum=sum+arr[i];
    givemeans(arr,n,i+1,sum,d);

}

int main(){
    int n; cin>>n;
    int* arr=new int[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int sum=0,d=0;
    givemeans(arr,n,0,sum,d);
    if(d>1) cout<<"Yes";
    else cout<<"No";
}
