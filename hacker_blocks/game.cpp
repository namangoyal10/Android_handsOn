#include<iostream>
using namespace std;

void givemeans(int* arr1,int* arr2,int si,int ei,int j,int n){
    if(si>ei){
        for(int k=0;k<n;k++) cout<<arr2[k]<<" ";
            cout<<endl;
            return;
    }
    arr2[j]=arr1[si];
    givemeans(arr1,arr2,si+1,ei,j+1,n);

    arr2[j]=arr1[ei];
    givemeans(arr1,arr2,si,ei+1,j+1,n);
}

int main(){
    int n; cin>>n;
    int* arr=new int[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int* arr1=new int[n];
    givemeans(arr,arr1,0,n-1,0,n);

}
