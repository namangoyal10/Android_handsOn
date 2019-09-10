#include<iostream>
#include<cmath>
#include<string.h>
using namespace std;
int r,c;
char key[9][5]={"abc","def","ghi","jkl","mno","pqrs","tuv","wx","yz"};

void givemeans(string arr1,int i,char* arr2,int j){
    if(arr1[i]=='\0'){
        arr2[j]='\0';
        cout<<arr2<<" ";
        return;
    }
    int n=arr1[i]-'0';

    arr2[j]=key[n-1][0];
    givemeans(arr1,i+1,arr2,j+1);


    arr2[j]=key[n-1][1];
    givemeans(arr1,i+1,arr2,j+1);

    arr2[j]=key[n-1][2];
    givemeans(arr1,i+1,arr2,j+1);

}

int main(){
    string arr1; cin>>arr1;
    int rows=pow(3,arr1.length());
    char arr2[100];
    givemeans(arr1,0,arr2,0);
    cout<<endl<<rows;
}
