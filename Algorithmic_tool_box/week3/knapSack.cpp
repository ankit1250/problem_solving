#include "bits/stdc++.h"
#include<algorithm>
#include<vector>
#include<utility>
using namespace std;
//here we need to pass the  weight_value array sorted in decreasing order of value/weight (value per unit weight) 
// sorting takes O(nlogn) and knapSack algorithm takes O(n), so the time complexity is O(nlogn)
int knapSack(vector<pair<int,int>> &weight_value,int capacity,vector<int> &A){

    int value=0;
    int n= weight_value.size();
    for(int i=0;i<n;i++){
        if(capacity==0){
            return value;
        }

        int Min= min(capacity,weight_value[i].first);
        capacity=capacity - Min;
        value+= Min*(weight_value[i].second/weight_value[i].first);
        (weight_value[i].first) = weight_value[i].first - Min;
        A[i] = A[i] + Min;
    }
    return value;

}
int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> weight_value;
    int capacity;
    cin>>capacity;
    vector<int> A(n,0);
    for(int i=0;i<n;i++){
        int weight,value;
        cin>>weight>>value;
        weight_value.push_back(make_pair(weight,value));
    }
    int maxValue= knapSack(weight_value,capacity,A);
    cout<<maxValue<<endl;
}

// Knapsack using recursion
// int dp[100][100]
// int knapSack(int W,int weight[],int profit[],int n){
//     if(W<=0 || n<0){
//         return 0;
//     }
//     if(dp[W][n]!= -1){
//       return dp[W][n];
//}
       // int result;
//     if(weight[n]>W){
//         result= knapSack(W,weight,profit,n-1);
//     }
//     else{
//         result= max(knapSack(W,weight,profit,n-1),profit[n]+knapSack(W-weight[n],weight,profit,n-1));
//     }
//     dp[W][n]=result;
//     return result;
// }
/*int KS(int weight[],int profit[],int n,int W){
    int dp[n+1][W+1];// initialize all cells with -1
    for(int i=0;i<=n;i++){
        for(int j=0;j<=W;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
            else if(weight[i-1]>j){
                dp[i][j]= dp[i-1][j];
            }
            else{
                dp[i][j]= max(dp[i-1][j],profit[i-1]+dp[i-1][j-weight[i-1]]);
            }
        }
    }
    cout<<dp[n][W]<<endl;


}*/