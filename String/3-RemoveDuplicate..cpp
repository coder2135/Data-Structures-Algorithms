#include<iostream>
using namespace std;
void removeDuplicate(string str,string ans,int i,int map[26]){
    if(i==str.size()){
        cout<<"ans : "<<ans<<endl;
        return ;
    }
    int mapIdx = (int)(str[i] - 'a');

    if(map[mapIdx]){ //duplicate
        removeDuplicate(str,ans,i+1,map);  //Skip
    } else{   //not duplicate
        map[mapIdx] = true;    //do true for duplicate so not repeat next time
        removeDuplicate(str,ans+str[i],i+1,map); //add in ans 
    }
}
int main(){
    string str = "abbccdeefgfh";
    string ans = "";
    int map[26] = {false};//For no character is in array

    removeDuplicate(str,ans,0,map);
    return 0;
}