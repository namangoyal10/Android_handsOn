#include<iostream>
using namespace std;

int givemeans(int n,int a,int b){
    if(n==0) return a+b;
    givemeans(n-1,b,a+b);
}


int main(){
    int n; cin>>n;
    cout<<givemeans(n-2,0,1);
}
