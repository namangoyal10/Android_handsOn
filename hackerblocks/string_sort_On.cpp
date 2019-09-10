#include<iostream>
#include<string.h>
using namespace std;

int main(){
    string arr1; cin>>arr1;
    string arr2=arr1;
    int count=0;
    for(count=1;arr1[count]!='\0';count++){
        if(arr1[count]==arr1[0]) break;
    }
    int repeat=arr1.length()/count;
    int i_temp=0;

    for(int i=0;i<arr1.length();i++){
        if(i>0 && i%repeat==0 ) i_temp++;

        int i_effective=i%repeat;
        int pos=i_effective*count;


        int d=pos+i_temp;;


        arr2[i]=arr1[d];
    }

    cout<<arr2<<endl;

}
