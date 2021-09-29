#include<iostream>
using namespace std;

int find_rightmost_bit(int n){
    int mask=1;
    int counter=1;
    while(n){
        if(n&mask){
            return counter;
        }

        counter++;
        n>>=1;
    }
}
int find_rightmost_diff_bits(int a,int b){
    int c= a^b;
    
    int mask=1;
    int counter=1;
    while(c){
        if(c&mask){
            return counter;
        }
        counter++;
        c>>=1;
    }
    return -1;
}
int main(){
    int n1,n2;
    scanf("%d",&n1);
    cin>>n2;
    cout<<find_rightmost_diff_bits(n1,n2);
}