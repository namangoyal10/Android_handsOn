#include<iostream>
using namespace std;

void print(int n){
    if(n==0) { cout<<endl; return;}
    cout<<"*    ";
    print(n-1);
}
void givemeans(int n,int i){
    if(i>n) return;
    print(i);
    givemeans(n,i+1);
}

int main(){
    int n; cin>>n;
    givemeans(n,1);
}
