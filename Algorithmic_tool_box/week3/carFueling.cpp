#include "bits/stdc++.h"

using namespace std;

int minRefills(int x[],int n,int L){
    int numRefills=0;
    int lastRefill=0;
    int currRefills=0;
    while(currRefills<= n){
       lastRefill=currRefills;
       while(currRefills<=n && x[currRefills+1]-x[lastRefill]<=L){
           currRefills=currRefills+1;
       }
       if(currRefills==lastRefill){
           cout<<"Impossible to reach destination"<<endl;
           return -1;
       }
       if(currRefills <= n)
       {
           numRefills++;
       }
    }
    return numRefills;
}

int main(){

}