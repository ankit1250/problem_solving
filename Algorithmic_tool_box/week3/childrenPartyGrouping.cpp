#include "bits/stdc++.h"
#include <vector>
#include <utility>
using namespace std;

vector<pair<int,int>> childrenGroup(const vector<int> &childrenAge){
    vector<pair<int,int>> group;
    int i=0;
    int n=childrenAge.size();
    while(i<n){
        pair<int,int> pair1= make_pair(childrenAge[i],childrenAge[i]+1);
        group.push_back(pair1);
        i++;
        while( i < n && childrenAge[i] <= pair1.second){
            i++;
        }
    }

    return group;
}
int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> groups;
    vector<int> child_age;
    for(int i=0;i<n;i++){
        int age;
        cin>>age;
        child_age.push_back(age);
    }
    groups= childrenGroup(child_age);
    for(auto g: groups){
        cout<<"["<<g.first<<","<<g.second<<"]"<<endl;
    }
}