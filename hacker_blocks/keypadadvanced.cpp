#include<iostream>
#include<cmath>
#include<string.h>
using namespace std;
int r,c;
char key[10][5]={ " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };

void givemeans(string arr1,int i,char* arr2,int j){
    if(arr1[i]=='\0'){
        arr2[j]='\0';
        cout<<arr2<<endl;
        return;
    }
    int n=arr1[i]-'0';

    int k=0;
    int l;
    if(n==1) l=4;
    while(key[n][k]!='\0'){
        arr2[j]=key[n][k];
        givemeans(arr1,i+1,arr2,j+1);
        k++;
    }


}

int main(){
    string arr1; cin>>arr1;
    int rows=pow(3,arr1.length());
    char arr2[100];
    givemeans(arr1,0,arr2,0);

}

