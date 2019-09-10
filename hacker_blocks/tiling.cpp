#include<iostream>
using namespace std;

void givemean















s(int n,int m,int i,int &sum,char* arr){





    if(i==n){2
        for(int j=0;j<n;j++) cout<<arr[j]<<endl;
        cout<<endl;
        sum++;
        return;
    }



    if(i+m<n){
        i=i+m;
        arr[i]='=';
        givemeans(n,m,i,sum,arr);
        arr[i]='x';
    }

    i=i+1;
    arr[i]='=';
    givemeans(n,m,i,sum,arr);
    arr[i]='x';

}

int main(){
    int n,m;
    cin>>n>>m;
    int sum=0;
    char arr[n];
    for(int i=0;i<=n;i++) arr[i]='x';
    givemeans(n,m,-1,sum,arr);
    cout<<sum;
}
