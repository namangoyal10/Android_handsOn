#include<iostream>
using namespace std;

void duplicate(string s1,char* s2,int i,int j){
    if(s1[i]=='\0'){
        s2[j]='\0';
        cout<<s2;
        return;
    }

    if(s1[i]!=s1[i-1]){
        s2[j]=s1[i];
        j++;
    }
    duplicate(s1,s2,i+1,j);

}

int main(){
    string s1; cin>>s1;
    char s2[100];
    s2[0]=s1[0];
    duplicate(s1,s2,1,1);

}
