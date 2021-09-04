#include "bits/stdc++.h"
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    Node(int value) {
       data=value;
       left=NULL;
       right=NULL;
    }
};

void preorder(struct Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}


void inorder(struct Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
    
}


void postorder(struct Node* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
int calcHeight(Node*root){
    if(root==NULL){
        return 0;
    }

    int left = calcHeight(root->left);
    int right= calcHeight(root->right);

    return max(left,right)+1;
}

int calcDiameter(Node *root,int *height){
    if(root == NULL){
        *height=0;
        return 0;
    }
    int lh=0,rh=0; 
    int lDiameter = calcDiameter(root->left,&lh);
    int rDiameter = calcDiameter(root->right,&rh);
    
    int currDiameter = lh+rh+1;
    *height= max(lh,rh)+1;

    return max(currDiameter,max(lDiameter,rDiameter));
}
int main(){
    Node *root= new Node(1);
    root->left = new Node(2);
    root->right= new Node(3);
    root->left->left= new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    int height = 0;
    cout<<calcDiameter(root,&height)<<"\n";
    return 0;
}