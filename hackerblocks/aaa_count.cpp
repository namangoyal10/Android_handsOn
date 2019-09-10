#include<iostream>
#include<cstring>
using namespace std;


int givemeans(string arr,int i,int &count){
    if(arr[i]=='\0') { cout<<count<<endl;
            return count;}

    if(arr[i]=='a' && arr[i+1] != '\0' && arr[i+2] != '\0'){
        if(arr[i+1]=='a' && arr[i+2]=='a'){
            ///cout<<i<<endl;
            count=count+1;
        }
    }
    givemeans(arr,i+1,count);
}

int givemeans1(string arr,int i,int count1){
    if(arr[i]=='\0') { cout<<count1<<endl;
            return count1;}

    if(arr[i]=='a' && arr[i+1] != '\0' && arr[i+2] != '\0'){
        if(arr[i+1]=='a' && arr[i+2]=='a'){
            givemeans1(arr,i+3,count1+1);
        }
    }
    else givemeans1(arr,i+1,count1);
}

int main(){
    string s1;
    cin>>s1;
    int count=0,count1=0,i=0;
    ///givemeans(s1,i,count);
    givemeans1(s1,i,count1);
}


