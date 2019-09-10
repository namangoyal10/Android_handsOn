#include<iostream>
using namespace std;
int main(){
    int m,n;
    cin>>m>>n;
    int arr1[m][2];
    int arr2[n][2];

    for(int i=0;i<m;i++) cin>>arr1[i][0]>>arr1[i][1];
    int sum=0;

    for(int i=0;i<n;i++){
            cin>>arr2[i][0]>>arr2[i][1];        ///i--arr2
                for(int j=0;j<m;j++){ ///j--arr1
                    if(arr1[j][0]>=arr2[i][0] && arr1[j][1]<=arr2[i][1]){
                        cout<<arr1[j][0]<<arr1[j][1]<<"     1 "<<endl;
                        sum++;
                    }
                    if(arr1[j][0]<arr2[i][0] && arr1[j][1]>=arr2[i][0]){
                        cout<<arr1[j][0]<<arr1[j][1]<<"     2 "<<endl;
                        sum++;
                    }
                    if(arr1[j][0]>arr2[i][0] && arr1[j][0]<=arr2[i][1] && arr1[j][1]>arr2[i][1]){
                      cout<<arr1[j][0]<<arr1[j][1]<<"     3 "<<endl;
                        sum++;

                    }

                }
        }
    cout<<sum;
}
