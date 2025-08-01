#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;
class Node{
public: 
   unordered_map<char,Node*> children;
   bool endofword;
   Node(){
    endofword = false;
   }
};
class Trie{
    Node* root = new Node();
public :
   //INSERT FUNCTION
   void insert(string key){
    Node* temp = root;
    for(int i=0;i<key.length();i++){
        if(!temp->children.count(key[i])){
            temp->children[key[i]] = new Node(); //insert the char
        }
        temp = temp->children[key[i]];
    }
    temp->endofword = true;
   }
   //SEARCH FUNCTION
   bool search(string key){
    Node* temp = root;
    for(int i=0;i<key.length();i++){
        if(temp->children.count(key[i])){
            temp = temp->children[key[i]];  //key[i]  available
        }else{
            return false;  //not available , return
        }
    }
    return temp->endofword;
   }
};
int main(){
    vector<string> word = {"ayush" , "kamboj" , "anmol" , "akshay" , "software"};
    Trie trie;
    for(int i=0;i<word.size();i++){
        trie.insert(word[i]);
    }
    if(trie.search("ayush")){
        cout<<"Searched key is available";
    }else{
        cout<<"Searched key is not available";
    }
    return 0;
}