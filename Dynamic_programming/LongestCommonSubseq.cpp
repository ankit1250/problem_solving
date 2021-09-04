#include "bits/stdc++.h"
using namespace std;
string subseq="";
string findCommonSubseqString(int **dp,int n1,int n2,string sub_seq,string s1,string s2){
    if(n1==0 && n2==0){
        return subseq;
    }
    if(dp[n1][n2] > dp[n1-1][n2-1]){
        cout<<s2[n2-1];
        subseq = subseq + (s1[n1-1]);
        return findCommonSubseqString(dp,n1-1,n2-1,sub_seq,s1,s2);
        
    }
    if(dp[n1][n2] == dp[n1][n2-1] && dp[n1][n2]==dp[n1-1][n2]){
        return findCommonSubseqString(dp,n1,n2-1,sub_seq,s1,s2);
        
    }
    if(dp[n1][n2] > dp[n1-1][n2]){
        return findCommonSubseqString(dp,n1,n2-1,sub_seq,s1,s2);
        
    }
    if(dp[n1][n2] > dp[n1][n2-1]){
        return findCommonSubseqString(dp,n1-1,n2,sub_seq,s1,s2);
        
    }
    
}
void longestCommonSubseq(string s1,string s2){
    int n1,n2;
    n1= s1.length();
    n2= s2.length();
    int **dp= new int*[n1+1];
    for(int i=0;i<=n1;i++){
        dp[i]= new int[n2+1];
    }
    
    for(int i=0;i<=n1;i++){
        for(int j=0;j<=n2;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
            else if(s1[i-1] == s2[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else{
                dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    cout<<dp[n1][n2]<<endl;
    char *S= "";
    
    cout<<findCommonSubseqString(dp,n1,n2,S,s1,s2);
    
    
    
}

int main(){
    string s1= "ABCDEFGH";
    string s2="ARPCOELFWQG";
    longestCommonSubseq(s1,s2);
}