#include<iostream>
using namespace std;
void Permutation(string str,string ans){
    int n = str.size();
    if(n==0){
        cout<<ans<<endl;
        return ;
    }
     for(int i=0;i<str.size();i++){
        char ch = str[i];
        string next = str.substr(0,i)+str.substr(i+1);
        Permutation(next,ans+ch);
    }
}
int main(){
    string str = "abc";
    string ans = "";
    Permutation(str,ans);
    return 0;
} 