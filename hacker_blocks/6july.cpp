#include<iostream>
#include<algorithm>
using namespace std;

int main(){

    int n; cin>>n;
    int* arr1=new int[n];
    for(int i=0;i<n;i++) cin>>arr1[i];
    int* arr2=new int[n];
    for(int i=0;i<n;i++) cin>>arr2[i];
    int count[100]={};
    sort(arr1,arr1+n);
    sort(arr2,arr2+n);
    cout<<"[";
    for(int i=0;i<n;i++) count[arr1[i]]++;
    int c=0;
    for(int i=0;i<n;i++){
        if(count[arr2[i]]>0){
            if(c==0)cout<<arr2[i];
            else cout<<", "<<arr2[i];
            c++;
            count[arr2[i]]--;
        }

    }
    cout<<"]";
}
