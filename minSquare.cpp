#include"bits/stdc++.h"

using namespace std;
#define vi vector<int>
#define rep(i,a,b) for(int i=a;i<b;i++)
const int N= 1e5+2, MOD= 1e9+7;
int dp[N];
//Memoization Approach
// int minSquare(int n){
//     if(n == 0 || n==1 || n==2 || n==3){
//         return n;
//     }
//     int ans = MOD;
//     if(dp[n] != MOD){
//         return dp[n];
//     }
//     for(int i=1;i*i<=n;i++){
//         dp[n] = min(dp[n],minSquare(n - i*i) +1);
//     }
//     return dp[n];

// }
int minSquare(int n){
    if(n == 0 || n==1 || n==2 || n==3){
        return n;
    }
    
    if(dp[n] != MOD){
        return dp[n];
    }
    int ans=n;

    for(int i=1;i*i<=n;i++){
        ans = min(ans,minSquare(n - i*i) +1);
    }
    dp[n]=ans;
    return ans;

}

// Bottom up 


signed main(){
        int n;
        cin>>n;
        rep(i,0,N){
            dp[i]=MOD;
        }
        
        cout<<minSquare(n)<<endl;
       //Bottom up build tabulation method
    //    vector<int> dp(n+1,MOD);
    //    dp[0]=0;
    //    dp[1]=1;
    //    dp[2]=2;
    //    dp[3]=3;
    //    for(int i=1;i<=n;i++){
    //        dp[i]=i;
    //        for(int j=1;j*j<=i;j++){
    //            dp[i]= min(dp[i],1+dp[i-j*j]);
    //        }
    //    }
    //    cout<<dp[n];    


}