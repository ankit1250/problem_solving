#include"bits/stdc++.h"
using namespace std;

int longestRepeatingSubseq(string s){
    int l= s.length();
    int dp[l+1][l+1];
    for(int i=0;i<=l;i++){
        for(int j=0;j<=l;j++){
            if(i==0|| j==0){
                dp[i][j]=0;
            }
            else if(s[i-1]==s[j-1] && i!=j){
                dp[i][j]= 1+dp[i-1][j-1];
            }
            else{
                dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[l][l];
}

int main(){
    string s;
    cin>>s;
    cout<<longestRepeatingSubseq(s);
}