#include<iostream>
#include<string.h>
using namespace std;

void givemeans(string arr,int i,char* arr1,int j){
    if(arr[i]=='\0'){
        arr1[j]='\0';
        cout<<arr1; return;
    }

    if(arr[i]==arr[i+1]){
            arr1[j]=arr[i];
            arr1[j+1]='*';
            givemeans(arr,i+1,arr1,j+2);
    }

    else{ arr1[j]=arr[i];
        givemeans(arr,i+1,arr1,j+1);
    }
}

int main(){
    string arr; cin>>arr;
    ///int n=arr.length();
    char arr1[100];
    givemeans(arr,0,arr1,0);
}
