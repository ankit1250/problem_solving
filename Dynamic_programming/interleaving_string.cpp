#include "bits\stdc++.h"
using namespace std;

class Solution{
   unordered_map<string,bool> mem;
   bool check(string s1,string s2, string s3,int len1,int len2,int len3,int p1,int p2,int p3){
       if(p3==len3){
           return (p1==len1 and p2==len2)?true:false;
       }

       string key = to_string(p1)+"*"+to_string(p2)+"*"+to_string(p3);
       if(mem.find(key)!= mem.end()){
           cout<<key<<endl;
           return mem[key];
       }
       if(p1== len1){
           return mem[key]= s3[p3]==s2[p2]?check(s1,s2,s3,len1,len2,len3,p1,p2+1,p3+1):false;
       }
       if(p2== len2){
           return mem[key]= s3[p3]==s1[p1]?check(s1,s2,s3,len1,len2,len3,p1+1,p2,p3+1):false;
       }

       bool one =false,two=false;

       if(s3[p3] == s1[p1]){
           one= check(s1,s2,s3,len1,len2,len3,p1+1,p2,p3+1);
       }
       if(s3[p3] == s2[p2]){
           two = check(s1,s2,s3,len1,len2,len3,p1,p2+1,p3+1);
       }

       return mem[key]= one or two;
   }
   public:
   bool isInterleaving(string s1,string s2,string s3){
       int l1= s1.length();
       int l2= s2.length();
       int l3= s3.length();
       if(l3 != l1+l2){
           return false;
       }

       return check(s1,s2,s3,l1,l2,l3,0,0,0);


   }
};

int main(){
    string s1= "aabbccdaaca";
    string s2= "ccdabbddaab";
    string s3= "aabccbdacbbcddaacdaaab";
    Solution solve;
    cout<<solve.isInterleaving(s1,s2,s3);
}