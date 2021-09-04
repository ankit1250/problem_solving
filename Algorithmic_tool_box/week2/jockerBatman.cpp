#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t-->0){
        int n,m,l;
        cin>>n>>m>>l;
        int arr[n];
        for(int i=0;i<m;i++){
            int temp;
            cin>>temp;
            for(int j=0;j<temp;j++){
                int id;
                cin>>id;
                arr[id]=i;
            }
        }
        int strip[l];
        for(int i=0;i<l;i++){
            cin>>strip[i];
        }
        int num_Segment=1;
        for(int i=0;i<l-1;i++){
            int temp= strip[i];
            int temp1= strip[i+1];
            if(temp!=temp1){
                if(arr[temp]!=arr[temp1]){
                    num_Segment++;
                }
            }

        }
        cout<<num_Segment<<endl;
    }
}