#include<bits/stdc++.h>
using namespace std;
bool myComp(string s1,string s2){
    string s12=s1+s2;
    string s21=s2+s1;
    return s12<s21;
}
int main(){
    int n;
    cin>>n;
    string arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];

    }

    return;
cout<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }

cout<<endl;
    sort(arr,arr+n,myComp);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
}
