#include<iostream>
using namespace std;

void givemeans(int* arr,int i,int n,int &sum){
    if(n==0){cout<<sum<<endl; return;}

    if(arr[0]>=arr[n-1]){
        if(i%2==1) sum=sum+arr[0];
        givemeans(arr+1,i+1,n-1,sum);
    }
    else{
            if(i%2==1) sum=sum+arr[n-1];
        givemeans(arr,i+1,n-1,sum);
    }
}


int main(){
int n; cin>>n;
int* arr=new int[n];
for(int i=0;i<n;i++){
    cin>>arr[i];
    }
    int sum=0;
    givemeans(arr,1,n,sum);

}
