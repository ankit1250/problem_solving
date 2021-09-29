#include<iostream>
using namespace std;
// Time Complexity = O(NlogN), where N is the no of elements in the array 
int majorityElem(int arr[],int n){
    int no_of_bits = sizeof(int)*8;
    int number=0;
    int size = n;
    for(int i=0;i<no_of_bits;i++){
        int counter=0;
        int mask= (1<<i);

        for(int j=0;j<size;j++){
            if(mask&arr[j]){
                counter++;
            }
        }

        if(counter> size/2){
            number+= mask;
        }
    }
    int count=0;
    for(int i=0;i<size;i++){
        if(arr[i]==number){
           count++;
        }
    }
    return (count>size/2)?number:-1;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<majorityElem(arr,sizeof(arr)/sizeof(arr[0]));
}