#include<iostream>
using namespace std;

void givemeans(int* arr,int s,int e,int sum1,int sum2,int &max,int c){
    if(s>e){
        cout<<endl<<sum1<<" "<<sum2;
        if(sum1>sum2){
            if(max<sum1) max=sum1;
            cout<<" YES ";
        }
        cout<<endl;
        return;
    }
    if(c%2==0){
        sum1=sum1+arr[s];
        cout<<" s1 = "<<arr[s];
        givemeans(arr,s+1,e,sum1,sum2,max,1);

        sum1=sum1+arr[e];
        cout<<" s1 = "<<arr[e];
        givemeans(arr,s,e-1,sum1,sum2,max,1);
    }

    else{
        sum2=sum2+arr[s];
        cout<<" s2 = "<<arr[s];
        givemeans(arr,s+1,e,sum1,sum2,max,0);

        sum2=sum2+arr[e];
        cout<<" s2 = "<<arr[s];
        givemeans(arr,s,e-1,sum1,sum2,max,0);

    }

}


int main(){
int n; cin>>n;
int* arr=new int[n];
for(int i=0;i<n;i++){
    cin>>arr[i];
    }
    int sum=0,sum1=0,sum2=0;
    givemeans(arr,0,n-1,sum1,sum2,sum,0);
    cout<<sum;
}
