// #include "bits/stdc++.h"
// using namespace std;

// int main(){
//     int T;
//     cin>>T;
//     int** arr = new int*[T];
//     int arr1[T];
//     for(int i=0;i<T;i++){
//         int n;
//         cin>>n;
//         arr1[i]=n;
//         arr[i]= new int[n];
//         for(int j=0;j<n;j++){
//             cin>>arr[i][j];
//         }
//     }
//     for(int i=0;i<T;i++){
//         int n= arr1[i];
//         for(int j=0;j<n;j=j+2){
//             cout<<arr[i][j]<<" ";
//         }
//         cout<<endl;
//     }
    

// }

#include <iostream>

using namespace std;
int * getResult(bool m[][15],int j,int set[],int n,int result[]){
    static int count=0;
    if(m[n-1][j]){
        getResult(m,j,set,n-1,result);
    }
    else {
        
        result[count++]=set[n];
        if(m[n-1][j-set[n]]){
           getResult(m,j-set[n],set,n-1,result);
        }
    }
    return result;
}
int main()
{
    int n=5,k=11;
    
    //cin>>n;
    
    //cin>>k;
    int set[]={2,3,7,8,10};
    
    /*for(int i=0;i<n;i++){
        cin>>set[i];
    }*/
    
    
    bool m[n][15];
    
    for(int i=0;i<n;i++){
        m[i][0]=true;
    }
    
    for(int j=1;j<=k;j++){
        if(j==set[0]){
            m[0][j]=true;
        }
        else{
            m[0][j]=false;
        }
        
    }
    
    for(int i=1;i<n;i++){
        for(int j=1;j<=k;j++){
            if(j<set[i]){
                m[i][j]=m[i-1][j];
            }
            else{
                if(m[i-1][j]){
                    m[i][j]=true;
                }
                else{
                    if(m[i-1][j-set[i]]){
                        m[i][j]= true;
                    }
                    else{
                        m[i][j]=false;
                    }
                }
            }
        }
    }
    int *result= new int[n];
    result= getResult(m,k,set,n-1,result);
    for(int i=0;i<n;i++){
        cout<<result[i]<<" ";
    }
    return 0;
}
/*
#include <iostream>
#include<vector>
using namespace std;

bool subsetSum(int arr[],int n,int sum,vector<int> &q){
    if(sum== 0){
        return true;
    }
    else if(sum<0 || n<=0){
        return false;
    }
    for(int i=0;i<n;i++){
    sum-= arr[n-1-i];
    //cout<<arr[n-1-i]<<" pushed"<<endl;
    if(subsetSum(arr,n-1-i,sum,q)){
        q.push_back(arr[n-1-i]);
        return true;
    }
    
    sum+=arr[n-1-i];
    }
    return false;
    
}

int main()
{
    int arr[]={2,5,3,4,8,7,6};
    vector<int> q;
    cout<<subsetSum(arr,7,5,q)<<endl;
    for(auto a:q){
        cout<<a<<" ";
    }
    return 0;
}


//Subset sum using dynamic programming(tabulation method)
int arr[]={2,5,3,4,8,7,6};
    vector<int> q;
    int sum= 26;
    
    int n= sizeof(arr)/sizeof(arr[0]);
    bool dp[sum+1][n+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++){
            if(i==0 && j==0){
                dp[i][j]=false;
            }
            else if(i==0 && j!=0){
                dp[i][j]=false;
            }
            else if(i!=0 && j==0){
                dp[i][j]=true;
            }
            else if(dp[i-1][j] || dp[i-1][j-arr[i-1]]){
                dp[i][j]=true;
            }
            else{
                dp[i][j]=false;
            }
        }
    }
    
    cout<<dp[n][sum];

*/
