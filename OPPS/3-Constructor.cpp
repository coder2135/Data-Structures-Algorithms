#include<iostream>
using namespace std;
class Car{
    string name;   //properties
    string color;
public:
    Car(){
        cout<<"Constructor without partameter \n";//Non-Parametric Constructor
    }  


    Car(string namev,string colorv){  //Constructure
        name = namev;                 //parametric Constructor
        color = colorv;
        cout<<"Aayush kamboj\n";
    }
    string getter(){      //Getter for verification
        return name;
    }

};
int main(){
    Car c0;
    Car c1("Audi","Grey");   //Initiallisation
    cout<<"Car name is : "<<c1.getter()<<endl;
    return 0;
}