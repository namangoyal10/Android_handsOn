#include<iostream>
using namespace std;

void shifting(char* arr,int i){
    if(arr[i]=='\0')    return;
   arr[i]=arr[i+1];
    shifting(arr,i+1);


}

void replace(char* arr,int i,int count){
    if(arr[i]=='\0') {
        arr[i+count]='\0';
        while(count>0){
            arr[i+count-1]='x';
            count--;
        }
        cout<<arr;
                        return;}

       if(arr[i]=='x'){
           count++;
                shifting(arr,i);
        }
       else i++;

       replace(arr,i,count);

    }


int main(){

    char arr1[100];
    cin>>arr1;
    replace(arr1,0,0);

}
