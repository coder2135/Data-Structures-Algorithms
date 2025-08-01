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
   bool startsWith(string pr){
       Node* temp = root;
       for(int i=0;i<pr.length();i++){
           if(!temp->children.count(pr[i])){
               return false;
           }
           temp = temp->children[pr[i]];
       }
       return true;
    } 
};
bool StartsWith(vector<string>&words,string key){
    Trie trie;
    for(int i=0;i<words.size();i++){
        trie.insert(words[i]);
    }
    return trie.startsWith(key);
}
int main(){
    vector<string> words = {"apple","app","mango","man","woman"};
    string pr1 = "app";
    string pr2 = "moon";
    cout<<StartsWith(words,pr1)<<endl;
    cout<<StartsWith(words,pr2)<<endl;
    return 0;
}