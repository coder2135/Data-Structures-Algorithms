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
bool helper(Trie trie,string key){
    if(key.length() == 0){
        return false;
    }
    for(int i=0;i<key.length();i++){
        string first = key.substr(0,i+1);
        string second = key.substr(i+1);
        if(trie.search(first) && trie.search(second)){
            return true;
        }
    }
    return false;
}
bool WordBreak(vector<string>& dictionary,string key){
    Trie trie;
    for(int i=0;i<dictionary.size();i++){
        trie.insert(dictionary[i]);
    }
    return helper(trie,key);
}
int main(){
    vector<string> dictionary = {"i","like","sam","samsung","mobile","ice"};
    string key = "ilikesamsung";
    cout<<WordBreak(dictionary,key);
    return 0;
}