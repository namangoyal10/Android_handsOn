#include<iostream>
using namespace std;

int main(){
    int n; cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int x=0;
    for(int i=0;i<n;i++){
        int temp=x;
        x=x^arr[i];
        if(temp==x) cout<<x<<endl;
    }
    cout<<x;
}
//7
//1 3 4 3 2 1 4
