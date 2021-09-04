#include <iostream>
#include<climits>
using namespace std;

int main()
{
    int n,no_block,i,j,temp,lowest=INT_MAX;
    
    
    cout<<"Enter the number of process: ";
    cin>>n;
    cout<<"Enter the number of blocks: ";
    cin>>no_block;
    
    int size_block[no_block],size_proc[n],fragment[n],process_block[n];
    bool block_alloc[no_block];
    cout<<"Enter the size of each block: "<<endl;
    for(i=0;i<no_block;i++){
        cin>>size_block[i];
    }
    cout<<"Enter the requirement of each process: "<<endl;
    for(i=0;i<n;i++){
        cin>>size_proc[i];
    }
    
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(!block_alloc[j]){
            temp= size_block[j]-size_proc[i];
            if(temp>=0){
                if(temp<lowest){
                    lowest= temp;
                    process_block[i]=j;
                }
            }
            }
        }
        fragment[i]=lowest;
        block_alloc[process_block[i]]=true; 
        lowest=INT_MAX;
    }
    cout<<"\n\nProcess_no.  Process_req.  Size_block  Fragment\n";
    
    for(i=0;i<n;i++){
        cout<<i+1<<"\t\t"<<size_proc[i]<<"\t\t"<<size_block[process_block[i]]<<"\t\t"<<fragment[i]<<endl;
    }
    
    
    
    

    return 0;
}
