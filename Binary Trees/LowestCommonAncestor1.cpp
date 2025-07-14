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
bool path(Node* root , int n , vector<int> & path1){
    if(root == NULL){
        return false;
    }
    if(root->data == n){
        path1.push_back(root->data);
        return true;
    }
    path1.push_back(root->data);
    bool left = path(root->left,n,path1);
    bool right = path(root->right,n,path1);
    if(left == false && right == false){
        path1.pop_back();
    }
}
//Lowest Common Ancester
int LCA(Node* root, int n , int m){
    vector<int> path1;
    vector<int> path2;
    path(root,n,path1);
    path(root,m,path2);
    int LCA = -1;
    for(int i=0,j=0;i<path1.size()&&j<path2.size();i++,j++){
        if(path1[i] != path2[j]){
            return LCA; 
        }
        LCA = path1[i];
    }
    return LCA;
}
int main(){
  vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
  Node* root = buildTree(nodes);
  //cout<<"root is : "<<root->data<<endl;
  if(LCA(root,4,6) != -1){
    cout<<"LCA is : "<<LCA<<endl;
  }
  return 0;
}