#include<iostream>
#include<queue>
#include<string>
using namespace std;
char isNonRepeating(string str){
    queue<char> q;
    int freq[26] = {0};
    for(int i=0;i<str.length();i++){
        char ch = str[i];
        q.push(ch);
        freq[ch - 'a']++;
        while(!q.empty() && freq[q.front() - 'a'] > 1){
            q.pop();
        }
        if(q.empty()){
            cout<<"-1\n";
        }else{
            cout<<q.front()<<"\n";
        }
    }
    return q.front();
}
int main(){
    string str = "aabbccdfddefe";
    char ans = isNonRepeating(str);
    if(ans == NULL){
        cout<<"No Non-repeating character exists ";
        return 0;
    }
    cout<<"Answer is : "<<ans<<endl;
    return 0;
}