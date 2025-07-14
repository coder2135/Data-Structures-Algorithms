#include<iostream>
#include<vector>
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
  currNode->left = buildTree(nodes); 
  currNode->right = buildTree(nodes); 
  return currNode;
} 
int kthAncestor(Node* root,int n,int k){
    if(root==NULL){
        return -1;
    }
    if(root->data==n){
        return 0;
    }
    int left = kthAncestor(root->left,n,k);
    int right=-1;
    if(left==-1){
        right = kthAncestor(root->right,n,k);
    }
    if((left == -1) && (right == -1)){
        return -1;
    }
    int currAncestor = left!=-1?left:right;
    if(currAncestor+1 == k){
        cout<<"kth is : "<<root->data;
    }
    return currAncestor + 1;
}
int main(){
  vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
  Node* root = buildTree(nodes);
  kthAncestor(root,4,1);
  return 0;
}