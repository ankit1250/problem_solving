#include "bits/stdc++.h"
using namespace std;

int rod_cutting(int price[],int length[],int rod_len,int n){
    int dp[n+1][rod_len+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=rod_len;j++){
            if(j==0){
                dp[i][j]=0;
            }
            else if(i==0){
                dp[i][j]=0;
            }
            else if(j< length[i-1]){
                dp[i][j]= dp[i-1][j];
            }
            else{
                dp[i][j]= max(price[i-1]+dp[i][j-length[i-1]],dp[i-1][j]);
            }
        }
    }
    
    return dp[n][rod_len];
}

int main(){
    int length[]={1,2,3,4,5,6,7,8};
    int price[]={3,5,8,9,10,17,17,20};
    cout<<rod_cutting(price,length,8,8);
}


// Another approach using recursion and DP
int t[9][9];
 
// A recursive program, using ,
// memoization, to implement the
// rod cutting problem(Top-Down).
int un_kp(int price[], int length[],
                    int Max_len, int n)
{
 
    // The maximum price will be zero,
    // when either the length of the rod
    // is zero or price is zero.
    if (n == 0 || Max_len == 0)
    {
        return 0;
    }
 
    // If the length of the rod is less
    // than the maximum length, Max_lene will
    // consider it.Now depending
    // upon the profit,
    // either Max_lene  we will take
    // it or discard it.
    if (length[n - 1] <= Max_len)
    {
        t[n][Max_len]
            = max(price[n - 1]
                      + un_kp(price, length,
                           Max_len - length[n - 1], n),
                  un_kp(price, length, Max_len, n - 1));
    }
 
    // If the length of the rod is
    // greater than the permitted size,
    // Max_len we will  not consider it.
    else
    {
        t[n][Max_len]
            = un_kp(price, length,
                              Max_len, n - 1);
    }
 
    // Max_lene Max_lenill return the maximum
    // value obtained, Max_lenhich is present
    // at the nth roMax_len and Max_lenth column.
    return t[n][Max_len];
}
 