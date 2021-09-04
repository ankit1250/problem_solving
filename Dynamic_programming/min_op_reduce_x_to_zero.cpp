#include "bits/stdc++.h"

using namespace std;

class Solution{
    unordered_map<string,int> mem;
    int solve(vector<int> &nums,int x,int left,int right,int count)
    {
        if(x==0){
            return count;
        }
        if(x<0 || left>right){
            return 1e6;
        }
        string key= to_string(left) +"*"+to_string(right)+ "*"+to_string(count);
        if(mem.count(key)>0){
            return mem[key];
        }

        int l= solve(nums,x-nums[left],left+1,right,count+1);
        int r= solve(nums,x-nums[right],left,right-1,count+1);

        return mem[key]= min(l,r);
        
    }
    public:
    int minOperationToReduceToZero(vector<int> &nums,int x){
        int ans= solve(nums,x,0,nums.size()-1,0);
        return ans>=1e6?-1:ans;
     }

};
int min_op(int arr[],int x,int l,int r,int count){
    if(x<arr[l] && x< arr[r]){
        return -1;
    }
    else if(x==arr[l] || x== arr[r]){
        return count+1;
    }
    else{
        int left= min_op(arr,x-arr[l],l+1,r,count+1);
        int right= min_op(arr,x-arr[r],l,r-1,count+1);
        if(left > 0 && right>0){
            return min(left,right);
        }
        else if(left < 0){
            return right;
        } 
        else{
            return left;
        }
    }
}
int main(){
    // int arr[]={6,1,4,2,6};
    // int x=5;
    // cout<<min_op(arr,x,0,4,0);
    vector<int> nums {1,1,4,3,2};
    int x=5;
    Solution sol;
    cout<<sol.minOperationToReduceToZero(nums,x);
    return 0;
}