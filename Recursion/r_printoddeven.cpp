#include<iostream>
using namespace std;

void givemeans(int n){
    if(n<1) {   cout<<endl;return;}
    ///cout<<n-(n%2-1);
    if(n%2==1) cout<<n<<"   ";
    givemeans(n-1);
    if(n%2==0) cout<<n<<"   ";
}

int main(){
    int n; cin>>n;
    givemeans(n);
}
