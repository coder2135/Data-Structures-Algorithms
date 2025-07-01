#include<iostream>
using namespace std;
class instagram {  //class with name "instagram"
    string username;
    string userId;
    int password;
    void changeProfile(){
        cout<<"Profile has changed\n";
    }
    void deleteAccout(){
        cout<<"Account has deleted\n";
    }
    public : 
    //setter 
    void setname(string name){
        username = name;
    }
    //getter 
    string getname(){
        return username;
    }
};
int main(){
    instagram u1;   //object u1s
    instagram u2;
    u1.setname("Aayush"); //calling the setter 
    cout<<"Name of user 1 is : "<<u1.getname();  //calling the getter
    return 0;
}