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
bool isIdentical(Node* root, Node* subroot){
    if(root==NULL && subroot==NULL){
        return true;
    }else if(root==NULL || subroot==NULL){
        return false;
    }
    if(root->data != subroot->data){
        return false;
    }
    return isIdentical(root->left,subroot->left)
           &&isIdentical(root->right,subroot->right);
}
bool isSubtree(Node* root, Node* subroot){
    if(root==NULL && subroot==NULL){
        return true;
    }else if(root==NULL || subroot==NULL){
        return false;
    }
    if(root->data == subroot->data){
        if(isIdentical(root , subroot)){
            return true;
        }
    }
    bool leftcheck = isSubtree(root->left,subroot);
    if(!leftcheck){
        return isSubtree(root->right,subroot);
    }
    return true;
}
int main(){
  vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
  Node* root = buildTree(nodes);
  //cout<<"root is : "<<root->data<<endl;
  Node* subroot = new Node(2);
  subroot->left = new Node(4);
  subroot->right = new Node(5);
  cout<<isSubtree(root,subroot);
  return 0;
}