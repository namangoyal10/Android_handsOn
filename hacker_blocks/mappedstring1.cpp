    #include<iostream>
    #include<string.h>
    using namespace std;

    void givemeans(int* arr,int i,int n,int* arr1,int j){
        if(i==n) {
                for(int k=0;k<j;k++) { char a='A';
                                    int d=arr1[k];
                                    a=a+d-1;
                        cout<<a;}
                cout<<endl;
                return;
        }

        arr1[j]=arr[i];
        givemeans(arr,i+1,n,arr1,j+1);

        if(i+1<n){
        arr1[j]=(arr[i]*10)+arr[i+1];
        if(arr1[j]<=26)     givemeans(arr,i+2,n,arr1,j+1);
        }
    }

    int main(){
        string s; cin>>s;
        int n=s.length();
        int* arr=new int[n];
        for(int i=0;i<n;i++){
            arr[i]=s[i]-'0';
        }
        int arr1[n]={};
        givemeans(arr,0,n,arr1,0);
    }
