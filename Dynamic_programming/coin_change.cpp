#include "bits\stdc++.h"
using namespace std;

int min_coin(vector<int> v,int total){
    int n= v.size();
    bool dp[n+1][total+1];

    for(int i=0;i<=n;i++){
        for(int j=0;j<=total;j++){
            if(j==0){
                dp[i][j]=true;
            }
            else if(i==0){
                dp[i][j]=false;
            }
            else if(j%v[i-1] == 0){
                dp[i][j]=true;
            }
            else{
                int rem= j%v[i-1];
                dp[i][j]=dp[i-1][rem];
            }
        }
    }
    int remainder= total;
    int min_coins=0;
    int index=n;
    if(dp[n][total]){
        while(remainder>0){
           int den= v[index-1];
           min_coins+= remainder/den;
           remainder= remainder%den;
           index--;
        }
        return min_coins;
    }
    else{
        return -1;
    }
}


int main(){
    vector<int> v{2,5};
    int total=11;
    cout<<min_coin(v,total);
}
// another approach for coin change problem
int coin_change_problem(vector<int>v,int amount){
    int n= v.size();
    int dp[n+1][amount+1];

    for(int i=0;i<=n;i++){
        for(int j=0;j<=amount;j++){
            if(j==0)
               dp[i][j]=0;
            
            else if(i==0)
               dp[i][j]= 1e5;
            else if(v[i-1] > j)
               dp[i][j]= dp[i-1][j];
            else
               dp[i][j]= min(1+dp[i][j-v[i-1]],dp[i-1][j]);
        }
    }

    return dp[n][amount]>1e4? -1:dp[n][amount];
}