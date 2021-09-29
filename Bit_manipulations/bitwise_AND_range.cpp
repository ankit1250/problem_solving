#include<iostream>
using namespace std;

int bitwise_AND_range(int m,int n){
    int number=0;
    int counter =0;
    while(m!=0 && n!=0){
       
       if(m==n){
           number= m;
           break;
       }
       counter++;
       m=m>>1;
       n=n>>1;
    }
    number<<= counter;
    return number;
}

int main(){
    int m,n;
    cin>>m>>n;
    cout<<bitwise_AND_range(m,n);
}