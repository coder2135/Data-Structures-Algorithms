#include<iostream>
#include<string.h>
using namespace std;
class InstaUser{
    string userName;
    int userId;
    int password;
    public:
        void setname(string namev){
            userName = namev;
        }
        string getname(){
            return userName;
        }
    void changePassword(int pass){
        password = pass;
    }
};
int main(){
    InstaUser u1;
    u1.setname("Aayush");
    cout<<u1.getname()<<endl;
    return 0;
}