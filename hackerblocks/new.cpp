#include<iostream>
using namespace std;
void give(int n){
    n=n-1;
}

int givemeans1(int n,int i){
	if(n==0) {
			return i;
		}
		i=i+n;
		givemeans1(n-1,i);
}

int main(){
int n;
cin>>n;
//cout<<n<<endl;
//give(n);
//cout<<n<<endl;

cout<<givemeans1(n,0);
}
