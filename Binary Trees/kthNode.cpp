#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Node{
public:
  int data;
  Node* left;
  Node* right;

  Node(int data){
    this->data = data;
    left = right = NULL; 
  }
};
static int idx = -1;
Node* buildTree(vector<int> nodes){
  idx++;
  if(nodes[idx]==-1){
    return NULL;
  }
  Node* currNode = new Node(nodes[idx]);
  currNode->left = buildTree(nodes); //For left subtree
  currNode->right = buildTree(nodes); //For right subtree
  return currNode;
}
void kth(Node* root,int k , int n ){
    if(root == NULL ){
        return ;
    }
    if(n==k){
        cout<<root->data<<" ";
        return ;
    }
    kth(root->left,k,n+1);
    kth(root->right,k,n+1);
}
void Kth(Node* root,int k){
    kth(root,k,1);
}
int main(){
  vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
  Node* root = buildTree(nodes);
  //cout<<"root is : "<<root->data<<endl;
  Kth(root,3);
  return 0;
}