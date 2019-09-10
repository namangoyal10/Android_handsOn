#include<iostream>
#include<cmath>
#include<string.h>
using namespace std;
int r,c;
char key[10][5]={ " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };

void givemeans(char* arr,int i){
    if(arr[i]=='\0'){
            cout<<arr<<endl;
            return;}
    for(int j=2;j<=9;j++){
        int  k=0;
        while(key[j][k]!='\0'){
            if(arr[i]==key[j][k]){ arr[i]=j+'0';}
            k++;
        }
    }
    givemeans(arr,i+1);
}

void givemeans(char* arr1,char* arr2,char* arr3,int i){
    if(arr1[i]=='\0') return;

    if(arr1[i]==arr2[0]){
        int k=0;
        while(arr2[k]!='\0' && arr1[i+k]==arr2[k]){
            k++;
            if(arr2[k]=='\0') {cout<<arr3<<endl; return;}
        }

    }
    givemeans(arr1,arr2,arr3,i+1);

}


int main(){
    char arr1[11][100] = {
            "prateek", "sneha", "deepak", "arnav", "shikha", "palak",
            "utkarsh", "divyam", "vidhi", "sparsh", "akku"};
    char arr2[10];
    char arr3[11][100] = {
            "prateek", "sneha", "deepak", "arnav", "shikha", "palak",
            "utkarsh", "divyam", "vidhi", "sparsh", "akku"};
    cin>>arr2;
    for(int i=0;i<11;i++){
    givemeans(arr1[11-i-1],0);
    givemeans(arr1[10-i],arr2,arr3[11-1-i],0);
    }

}


