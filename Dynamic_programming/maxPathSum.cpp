// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        // code here
        if(N==1){
            return Matrix[0][0];
        }
        for(int i=0;i<N-1;i++){
            for(int j=0;j<N;j++){
                
                if(j==0){
                    Matrix[i][j]= max(Matrix[i+1][j],Matrix[i+1][j+1])+Matrix[i][j];
                }
                else if(j==N-1){
                    Matrix[i][j]= max(max(Matrix[i+1][j-1],Matrix[i+1][j])+Matrix[i][j],Matrix[i][j-1]);
                }
                else{
                    int temp = max(Matrix[i+1][j-1],Matrix[i+1][j]);
                    Matrix[i][j]= max(max(temp,Matrix[i+1][j+1])+Matrix[i][j],Matrix[i][j-1]);
                }
            }
            
        }
        int max_sum=0;
        for(int j=0;j<N-1;j++){
            
            max_sum+=Matrix[j][N-1];
        }
        return max_sum;
        
        
        
    }
    
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}  // } Driver Code Ends