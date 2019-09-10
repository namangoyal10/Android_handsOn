#include<iostream>
using namespace std;

void print(int* arr){
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void change(int* arr,int* arr1){
    /*int* temp=arr;

    arr=arr1;
    arr1=temp;

    print(arr);
    print(arr1);*/
    swap(arr,arr1);
    print(arr);
    print(arr1);
}


int main(){
    int* arr=new int[5];
    for(int i=0;i<5;i++){
        arr[i]=i+1;
    }

    int* arr1=new int[5];
    for(int i=0;i<5;i++){
        arr1[i]=(i+1)*10;
    }

    print(arr);
    print(arr1);
    change(arr,arr1);
    print(arr);
    print(arr1);

}
