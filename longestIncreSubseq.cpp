#include <iostream>
#include<algorithm>
using namespace std;

int main(){
    int list[]={2,3,1,5,-1,0,6,4,7};
    int n= sizeof(list)/sizeof(list[0]);
    int temp[n];
    for(int i=0;i<n;i++){
        temp[i]=1;
        for(int j=0;j<i;j++){
            if(list[i]>list[j] && temp[j]+1> temp[i]){
                temp[i]++;
            }
        }
    }
    cout<<max_element(temp,temp+n);
}