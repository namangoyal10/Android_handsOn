#include<iostream>
using namespace std;

void dothat(int* arr,int i){
    if(i==5) return;
    int temp=i;
    dothat(arr,i+1);
    cout<<temp<<endl;
}

void dothat(string naman,int i){
    if(naman[i]=='\0') return;
    naman[i]=i+70;
    dothat(naman,i+1);
    cout<<naman[i]<<endl;

}

void dothat(char* naman,int i){
    if(naman[i]=='\0') return;
    naman[i]=i+70;
    dothat(naman,i+1);
    cout<<naman[i]<<endl;

}
/*void display(int arr[i][j],int i,int j){
    for(int m=0;m<i;m++){
        cout<<arr[m][0]<<endl;
    }
}*/
int main(){

    int arr9[2][3]={ {1,2,3},{4,5,6}};
    //dsiplay(arr,2,3);
    int* arr=new int[5];

    (int*)* arr10=new int[5][3];
    arr[0]=10;
    arr[1]=20;
    arr[2]=30;
    arr[3]=40;
    arr[4]=50;



    ///dothat(arr,0);

    string naman="naman";
    dothat(naman,0);

    char drive[6]="drive";
    dothat(naman,0);
}
