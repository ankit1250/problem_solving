#include "bits/stdc++.h"
using namespace std;

struct Node {
  int data;
  struct Node* left;
  struct Node* right;
  Node(int data){
      this->data= data;
      left=NULL;
      right=NULL;
  }
};
Node* buildTree(int postorder[], int inorder[], int st, int end){
    static int idx=4;
    if(st > end){
        return NULL;
    }

    int curr= postorder[idx];
    idx--;
    Node* node= new Node(curr);
    if(st == end){
        return node;
    }
    
    //searching inorder for the position of the current node
    int temp=-1;
    for(int i=st;i<=end;i++){
        if(curr== inorder[i]){
            temp=i;
            break;
        }
    }
    node->right= buildTree(postorder,inorder,temp+1,end);
    node->left= buildTree(postorder,inorder,st,temp-1);

    return node;

}
void printInorder(Node* root){
    if(root == NULL){
        return;
    }
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}
int main(){
    int inorder[] = {4, 2, 1, 5, 3};
    int postorder[] = {4, 2, 5, 3, 1};
    Node* root= buildTree(postorder,inorder,0,4);
    printInorder(root);

}