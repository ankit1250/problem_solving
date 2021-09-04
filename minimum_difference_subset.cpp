#include "bits/stdc++.h"
using namespace std;

int min_sub_diff(vector<int> v,int sum){
    int n= v.size();
    bool dp[n+1][sum+1];

    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++){
            
            if(j==0){
                dp[i][j]=true;
            }
            else if(i==0){
                dp[i][j]=false;
            }
            else if(v[i-1]>j){
                dp[i][j]= dp[i-1][j];
            }
            else{
                dp[i][j]=(dp[i-1][j] || dp[i-1][j-v[i-1]]);
            }
            
        }
    }

    int min_diff= INT_MAX;
    for(int i=sum/2;i>=0;i--){
        if(dp[n][i]){
            min_diff= min(min_diff,abs(sum-2*i));
        }
    }
    return min_diff;
}

int main(){
    vector<int> v{1,6,11,5};
    int sum= 23;
    cout<<min_sub_diff(v,sum);
}