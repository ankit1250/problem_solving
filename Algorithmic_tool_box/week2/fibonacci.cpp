#include "bits/stdc++.h"
using namespace std;

long long fibonacci(int n){
    long long arr[n+1];
    arr[0]=0;
    arr[1]=1;
    for(int i=2;i<=n;i++){
        arr[i]= arr[i-1]+arr[i-2];
    }
    return arr[n];
}
int main(){
    int n;
    n=45;
    cout<<fibonacci(n);
}
