#include "bits/stdc++.h"
using namespace std;
unordered_map<string,int> dp;
int minAttempts(int eggs,int floor){
    if(floor == 0 || floor == 1)
        return floor;
    
    if(eggs==1)
       return floor;
    int Min= INT_MAX;
    string key = to_string(eggs)+"*"+to_string(floor);
    if(dp.find(key)!= dp.end()){
        return dp[key];
    }
    for(int i=1;i<=floor;i++){
        int temp = 1+ max(minAttempts(eggs-1,i-1),minAttempts(eggs,floor-i));
        
        Min = min(Min,temp);
    }
    dp[key]= Min;
    return Min;
}
int main(){
    int e,f;
    cin>>e>>f;
    
    cout<<minAttempts(e,f);
}