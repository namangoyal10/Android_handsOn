#include<iostream>
using namespace std;

void printPermutations(string str,int spos,string r){
    if (str[spos]=='\0'){
        if(str[0]!=r[0]) cout<<str<<endl;
        return;
    }
    for (int i=spos; str[i]!='\0';i++){
        ///swap (str[i],str[spos]);
        char temp=str[i];
        for (int j=i;j>spos;j--) str[j]=str[j-1];
        str[spos]=temp;
        printPermutations(str,spos+1,r);
        temp=str[spos];
        for (int j=spos;j<i;j++) str[j]=str[j+1];
        str[i]=temp;
        ///swap (str[i],str[spos]);
    }
}

int main(){
    string str; cin>>str;
    string r=str;
    printPermutations(str,0,r);
}

