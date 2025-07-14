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
  currNode->left = buildTree(nodes); //For left subtree
  currNode->right = buildTree(nodes); //For right subtree
  return currNode;
}
Node* LCA(Node* root,int n,int m){
    if(root == NULL){
        return NULL;
    }
    if(root->data == n || root->data == m){
        return root;
    }
    Node* left = LCA(root->left,n,m);
    Node* right = LCA(root->right,n,m);
    if(left != NULL && right!=NULL){
        return root;
    }
    return left!=NULL? left : right;
}
int LCANodeDist(Node* root, int n){
    if(root == NULL){
        return -1;
    }
    if(root->data == n){
        return 0;
    }
    int left = LCANodeDist(root->left, n);
    if(left != -1) return left + 1;
    int right = LCANodeDist(root->right, n);
    if(right != -1) return right + 1;
    return -1;
}
int Distance(Node* root,int n, int m){
    Node* lca = LCA(root,n,m);
    int dis1 = LCANodeDist(lca,n);
    int dis2 = LCANodeDist(lca,m);
    return dis1 + dis2;
}
int main(){
  vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
  Node* root = buildTree(nodes);
  cout<<"Distance is : "<<Distance(root,4,6);
  return 0;
}