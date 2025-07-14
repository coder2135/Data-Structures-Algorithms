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
    if(nodes[idx] == -1){
        return NULL;
    }
    Node* currNode = new Node(nodes[idx]);
    currNode->left = buildTree(nodes);
    currNode->right = buildTree(nodes);
    return currNode;
}
int Height(Node* root){
    if(root == NULL){
        return 0;
    }
    int leftHt = Height(root->left);
    int rightHt = Height(root->right);
    int currHt = max(leftHt,rightHt) + 1;
    return currHt;
}
pair<int,int> Diameter2(Node* root){
    if(root == NULL){
        return make_pair(0,0);
    }
    pair<int,int> leftInfo = Diameter2(root->left);
    pair<int,int> rightInfo = Diameter2(root->right);
    int currDiameter = leftInfo.second + rightInfo.second + 1 ;
    int finalDiameter  = max(currDiameter,max(leftInfo.first,rightInfo.first));
    int finalHt = max(leftInfo.second,rightInfo.second)+1;
    return make_pair(finalDiameter,finalHt);
}
int Diameter(Node* root){
    if(root==NULL){
        return 0;
    }
    int leftHt = Height(root->left);
    int rightHt = Height(root->right);
    int currHt = leftHt + rightHt + 1;
}
int main(){
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root = buildTree(nodes);
    cout<<"Diameter of BT is : "<<Diameter2(root).first;
    return 0;
}