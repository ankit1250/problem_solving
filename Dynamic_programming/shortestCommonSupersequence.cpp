#include"bits/stdc++.h"
using namespace std;

string LCS(string s1,string s2){
    int l1= s1.size(),l2=s2.size();
    string dp[l1+1][l2+1];
    for(int i=0;i<=l1;i++){
        for(int j=0;j<=l2;j++){
            if(i==0 || j==0){
                dp[i][j]="";
            }
            else if(s1[i-1]== s2[j-1]){
                dp[i][j]= dp[i-1][j-1]+ s1[i-1];
            }
            else{
                dp[i][j]= dp[i-1][j].length()>dp[i][j-1].length()?dp[i-1][j]:dp[i][j-1];
            }
        }
    }
    return dp[l1][l2];
}
string SCS(string s1,string s2){
    string lcs= LCS(s1,s2);
    string ans="";
    int p1=0,p2=0;
    for(char c:lcs){
        while(s1[p1]!=c){
            ans+=s1[p1++];
        }
        while(s2[p2]!=c){
            ans+=s2[p2++];
        }
        ans+=c;
        ++p1;
        ++p2;
    }
    return ans;
}
int main(){
    string s1= "aggtab";
    string s2= "gxtxayb";
    cout<<SCS(s1,s2);
}