#include"bits/stdc++.h"
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        int no_0=0,no_1=0;
        for(int i=0;i<n;i++){
            int temp;
            cin>>temp;
            arr[i]= temp%2;
            if(arr[i]){
                no_1++;
            }
            else{
                no_0++;
            }
        }

        if(n%2 != 0 && abs(no_1-no_0)!=1){
            cout<<-1<<endl;
        }
        else if(n%2 == 0 && no_1-no_0!=0){
            cout<<-1<<endl;
        }
        else{
            int temp_count=0;
            int tmp=0;
            for(int i=0;i<n-1;i++){
                if(arr[i]==1 && arr[i]==arr[i+1]){
                   temp_count++;
                }
                else if(arr[i]==0 && arr[i]==arr[i+1]){
                   tmp++;
                }
            }
            cout<<max(tmp,temp_count)<<endl;
        }


    }
}