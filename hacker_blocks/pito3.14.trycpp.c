#include<iostream>
using namespace std;

void shifting(char* arr,int i){
    if(arr[i]=='\0') {
            arr[i+2]='\0';
            return;}
    shifting(arr,i+1);
    arr[i+2]=arr[i];

}

void replace(char* arr,int i){
    if(arr[i]=='\0') {  cout<<arr<<endl;
                        return;}

       if(arr[i]=='p'&&arr[i+1]=='i'){
              shifting(arr,i+2);
              arr[i]='3';
              arr[i+1]='.';
              arr[i+2]='1';
              arr[i+3]='4';
              i=i+4;
       }
       i++;
       replace(arr,i);

    }


int main(){
    int n; cin>>n;
    while(n--){
    char arr1[100];
    cin.getline()>>arr1;


    replace(arr1,0);
    }
}

///abcpixyz
///
