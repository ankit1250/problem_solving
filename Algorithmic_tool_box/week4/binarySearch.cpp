#include "bits/stdc++.h"
using namespace std;

int binarySearch(int arr[],int low,int high,int key){
    if(high >= low){
    int mid = low + (high-low)/2;
    if(arr[mid] == key){
        return mid;
    }
    else if(key < arr[mid]){
        return binarySearch(arr,low,mid-1,key);
    }
    else 
    {
        return binarySearch(arr,mid+1,high,key);
    }
    }
    return -1;

}
int main(){
    int arr[]= { 1, 2, 3, 4,  9 };
    int key= 9;
    int n= sizeof(arr)/sizeof(arr[0]);
    int ind= binarySearch(arr,0,n-1,key);
    cout<<ind;
}