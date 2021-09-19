#include "bits/stdc++.h"
using namespace std;

int max_uncrossed_lines(vector<int> v1,vector<int> v2){
    int n1= v1.size();
    int n2= v2.size();
    vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
    for(int i=0;i<=n1;i++){
        for(int j=0;j<=n2;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
            else{
                if(v1[i-1]== v2[j-1]){
                    dp[i][j]= 1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]= max(dp[i-1][j-1],max(dp[i-1][j],dp[i][j-1]));
                }
            }
        }
    }
    return dp[n1][n2];
    
}

int main(){
    vector<int>v1{1,4,3,5,2};
    vector<int>v2{1,2,4,3,6};
    cout<<max_uncrossed_lines(v1,v2);

    
    
}