#include <iostream>

using namespace std;

struct Node{
    int dist[20];
    int from[20];
    
} router[10];

int main()
{
    int dm[20][20],n;
    cout<<"enter the no. of Nodes: ";
    cin>>n;
    cout<<"Enter the distance matrix: "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>dm[i][j];
            router[i].dist[j]= dm[i][j];
            router[i].from[j]=j;
        }
    }
    int flag=0;
    do{
        flag=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    if(router[i].dist[j]>router[i].dist[k]+router[k].dist[j]){
                        flag=1;
                        router[i].dist[j]= router[i].dist[k]+router[k].dist[j];
                        router[i].from[j]= k;
                    }
                    
                }
            }
        }
    }while(flag);
    for(int i=0;i<n;i++){
        cout<<"Router info for router"<<i+1<<endl;
        cout<<"Dest\tNext Hop\tDist"<<endl;
        for(int j=0;j<n;j++){
            cout<<router[i].from[j]+1<<"\t\t"<<j+1<<"\t\t"<<router[i].dist[j]<<endl;
        }
    }

    return 0;
}
