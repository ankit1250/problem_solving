#include<iostream>
#include<cmath>
using namespace std;

int toggle_bits(int n,int l,int r){
    int mask=1;

    mask = (1<<(r-l+1))-1;
    mask = mask<< (l-1);

    // mask <<= (l-1);
    
    // for(int i=l-1;i<r;i++){
    //     if(mask&n){
    //         n-= pow(2,i);
    //     }
    //     else{
    //         n+= pow(2,i);
    //     }
    //     mask <<=1;
        
        
    // }
    return n^mask;

}

int main(){
    int n,l,r;
    cin>>n>>l>>r;
    cout<<toggle_bits(n,l,r);
}