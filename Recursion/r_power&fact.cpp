#include<iostream>
using namespace std;

int power(int x,int y){
    if(y==0) return 1;
    return x*power(x,y-1);
}

int fact(int n){
    if(n==0) return 1;
    return n*fact(n-1);

}

int main(){
    int n; cin>>n;
    cout<<fact(n)<<endl;

    int x,y; cin>>x>>y;
    cout<<power(x,y);
}
