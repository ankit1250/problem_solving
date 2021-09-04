#include "bits/stdc++.h"
#include <queue>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};
void printLevelOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();
        if (node != NULL)
        {
            cout << node->data << " ";
            if (node->left != NULL)
            {
                q.push(node->left);
            }
            if (node->right != NULL)
            {
                q.push(node->right);
            }
        }
        else if(!q.empty())
        {
            q.push(NULL);
            cout << endl;
        }

        
    }
}

int sumAtK(Node* root, int k){

    if(root == NULL){
        return -1;
    }

    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    int sum=0;
    int tempLevel=0;
    while(!q.empty()){
        Node* node= q.front();
        q.pop();
        if(node != NULL){
            if(tempLevel == k){
                sum+=node->data;
            }
            if(node->left != NULL){
                q.push(node->left);
            }
            if(node->right != NULL){
                q.push(node->right);
            }
        }
        else if(!q.empty()){
            q.push(NULL);
            tempLevel++;
        }
       
    }
    return sum;
}
int32_t main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    //printLevelOrder(root);
    cout<<sumAtK(root,2);
}