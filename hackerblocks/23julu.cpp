#include<iostream>
#include<cstring>
using namespace std;
void subsequences(char *arr1,char *arr2,int i,int j,int l,int &maxl){

    if(arr1[i]=='\0'){
        if(l>=2 && arr2[0]>arr2[l-1] && l>maxl){  maxl=l;}
        ///arr2[j]='\0'; cout<<l<<" : "<<arr2<<endl;
        return;
    }

    arr2[j]=arr1[i];
    subsequences(arr1,arr2,i+1,j+1,l+1,maxl);

    subsequences(arr1,arr2,i+1,j,l,maxl);


}


int main(){
int t; cin>>t;
while(t--){
    char s[10],s1[10];
    int n; cin>>n;
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    s[n]='\0';
    ///cout<<s<<endl;
    int max=0;
    subsequences(s,s1,0,0,0,max);
    cout<<max<<endl;
    }

}
