#include<iostream>
using namespace std;

void print321(int n){
    if(n==0){ cout<<endl;
    return;}
    cout<<n<<"  ";
    print321(n-1);

}

void print123(int n){
    if(n==0) return;
    print123(n-1);
    cout<<n<<"  ";
}

void print321123(int n){
    if(n==0) return;
    cout<<n<<"  ";
    print321123(n-1);
    cout<<n<<"  ";
}

void print123321(int n){
    print123(n);
    print321(n);
}


int main(){
    int n; cin>>n;
    print321(n);
    print123(n);
    cout<<endl;
    print321123(n);
    cout<<endl;
    print123321(n);
}
