#include<iostream>
using namespace std;

char* givemeans(int* arr,int n){
    if(n==0) return "true";
    if(arr[n]<arr[n]-1) return  "false";
    givemeans(arr,n-1);
}

int main(){
    int n; cin>>n;
    int* arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<givemeans(arr,n-1);
}
