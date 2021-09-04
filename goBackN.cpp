#include<iostream>
#include<ctime>

using namespace std;

int main(){
    int winsize,nf;
    cin>>nf>>winsize;
    srand(time(NULL));
    int count=0;
    int current_win[2];
    bool retransmit=false;
    bool acknow[nf];
    current_win[0]=0;
    current_win[1]=winsize-1;
    for(int i=0;i<winsize;i++){
        cout<<"sending frame "<<i+1<<endl;
    }
    while(count<nf){
        
        int temp= rand()%2;
        if(temp!=0){
            cout<<"Ack for frame "<<count+1<<endl;
            current_win[0]++;
            current_win[1]++;
            count++;
        }else{
            retransmit=true;
            cout<<"Timeout!! No ack for frame "<<count+1<<endl;
        }


        if(retransmit==true){
            for(int i=current_win[0];i<=current_win[1];i++){
                cout<<"Re-sending Frame "<<i+1<<endl;
                retransmit=false;
            }
        }
        else{
            cout<<"sending frame "<<current_win[1]+1<<endl;
            
        }
    }
}