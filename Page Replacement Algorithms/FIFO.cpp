

#include <iostream>
#include<string>
#include<queue>
#include<unordered_set>
using namespace std;

int pageFaults(int page[],int n,int capacity){
    unordered_set<int> frame;
    queue<int> que;
    int pagefault=0;
    
    for(int i=0;i<n;i++){
        if(frame.size()<capacity){
            if(frame.find(page[i])==frame.end()){
                pagefault++;
                que.push(page[i]);
                frame.insert(page[i]);
            }
        }
        else{
            
            if(frame.find(page[i])==frame.end()){
                pagefault++;
                int temp= que.front();
                que.pop();
                frame.erase(temp);
                que.push(page[i]);
                frame.insert(page[i]);
            }
            
        }
        
    }
    return pagefault;
}

int main()
{
    int n;
    cout<<"Enter the length of the reference page string: ";
    cin>>n;
    int pages[n];
    cout<<"Enter the reference page string: ";
    for(int i=0;i<n;i++){
        cin>>pages[i];
    }
    int size;
    cout<<"Enter the size of the frame: ";
    cin>>size;
    cout<<"The total number page fault is: "<<pageFaults(pages,n,size);
    

    return 0;
}
