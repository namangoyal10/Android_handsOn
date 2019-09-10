#include<iostream>>
using namespace std;

int main(){
long long int n; cin>>n;
long  int* arr=new long int[n];
long long int count=0;

for(int i=0;i<n;i++) cin>>arr[i];

    for(int i=0;i<n-1;i++){
        int cur_max=arr[i];
        for(int j=i+1;j<n;j++){
            if(arr[j]>cur_max) cur_max=arr[j];
            if(arr[i]*arr[j]<=cur_max) {
                    cout<<i+1<<"  "<<j+1<<endl;
                    count++;
                                        }
                             }
                        }
    cout<<endl;
    cout<<count;
}
