#include "bits/stdc++.h"
#include <vector>
using namespace std;

long long maximumPairwiseProduct(const vector<long> &numbers){
    long long result=0;
    long max=0;
    long sec_max=0;
    for(auto a:numbers){
        if(max < a){
            sec_max=max;
            max=a;
        }
        else if(sec_max < a){
            sec_max=a;
        }
    }
    result= (long long)max*sec_max;
    return result;
}

int main(){
    int n;
    cin>>n;
    vector<long> numbers;
    long number;
    for(int i=0;i<n;i++){
        cin>>number;
        numbers.push_back(number);
    }
    long long res= maximumPairwiseProduct(numbers);
    cout<<res;
}