#include<iostream>
#include<queue>
using namespace std;

int main(){
    int n; cin>>n;
    int* arr=new int[n];
    queue<int>q;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        q.push(arr[i]);

    }
    int sum=0,borrow=0;

    for(int i=0;i<n;i++){
            ///cout<<arr[i];
            sum=sum+arr[i]+1;
        int j=1,count=arr[i];
        while(arr[i]==arr[i+j] && count>0 && i+j<n){
            j++;
            count--;
        }
        j--;

        ///cout<<"            "<<j;
        i=i+j;
        ///cout<<"          "<<i<<endl;
    }
    cout<<sum;
}
