#include<iostream>
using namespace std;
int j=0;

void sorting(string &s){

    for(int i=0;s[i+1]!='\0';i++){
        int temp_index=i;
        for(int j=i+1;s[j]!='\0';j++){
                if(s[j]<s[temp_index]) temp_index=j;
        }
        swap(s[i],s[temp_index]);
    }
    ///cout<<s<<endl;
}

void permutation(string s,int si){
    if(s[si]=='\0') {cout<<s<<endl;
                        //arr[z]=s;
                        //z++;
                       return; }
        for(int i=si;s[i]!='\0';i++){
            ///swap(s[i],s[si]);

            char temp=s[i];
            for(int j=i;j>si;j--) s[j]=s[j-1];
            s[si]=temp;
            permutation(s,si+1);
            temp=s[si];
            for(int j=si;j<i;j++) s[j]=s[j+1];
            s[i]=temp;

            ///swap(s[i],s[si]);

        }

}


int main(){
    string s="MAD";
    sorting(s);
    permutation(s,0);}
    /*string s,r;   cin>>s; r=s;
    int l=s.length();
    int m=l;
    int n=1;
    while(l>0) { n=n*l; l--;}
    string arr[n];
    sorting(s);
    permutation(s,0,arr,l);


    /// n= no of perm  m= length;
    int p=n/m;

    while(i<n){
        ///if(arr[i+p-1]==r) break;
        cout<<arr[i+p-1]<<endl;
        p--;
        if(p==0){ p=q; i=i+q;}
    }*/
