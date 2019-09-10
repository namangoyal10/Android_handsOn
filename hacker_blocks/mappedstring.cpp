#include<iostream>
#include<string.h>
using namespace std;

void givemeans(string s,int i,char* arr,int j){
    if(s[i]=='\0') {arr[j]='\0';
                cout<<arr<<endl;
            cout<<endl; return;}

    ///case 1 single piece
    char c=s[i]-'1'+'A';
    arr[j]=c;
    givemeans(s,i+1,arr,j+1
            );

    ///case 2 double
    if(s[i+1]!='\0'){
            int d=(s[i]-'0')*10 + (s[i]-'0');
            if(d<=26){
            char c='A'+d-1;
            arr[j]=c;
            givemeans(s,i+2,arr,j+2);
            }
    }
}

int main(){
        string s;   cin>>s;
        char arr[10];
        givemeans(s,0,arr,0);
}
