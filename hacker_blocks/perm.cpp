#include<iostream>
using namespace std;

void printPermutations(char str[],int spos){
    if (str[spos]=='\0'){
        cout<<str<<endl; return;
    }
    for (int i=spos; str[i]!='\0';i++){
        swap (str[i],str[spos]);

        printPermutations(str,spos+1);

        swap (str[i],str[spos]);
    }
}

int main(){
    char str[]="abc";
    printPermutations(str,0);
}

