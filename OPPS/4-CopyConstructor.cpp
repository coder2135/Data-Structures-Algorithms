#include<iostream>
using namespace std;
class Car{
    string name;
    string color;
    string type;
    public:
    Car(string name,string color,string type){
        cout<<"Just practicing Constructors....\n";
        this->name = name;
        this->color = color;
        this->type = type;
        cout<<"Name of car c1 is : "<<name<<endl;
        cout<<"Color of car c1 is : "<<color<<endl;
        cout<<"Type of car c1 is : "<<type<<endl;
    }
    Car(Car &original){
        name = original.name;
        color = original.color;
        type = original.type;
    }
    void startCar(){
        cout<<"Car is started..\n";
    }
    //Getter 
    void getter(){
        cout<<"Name of car c2 is : "<<name<<endl;
        cout<<"Color of car c2 is : "<<color<<endl;
        cout<<"Type of car c2 is : "<<type<<endl;
    }
};
int main(){
    Car c1("Mahindra_BE6","Grey","Electric");
    Car c2(c1);
    c2.getter();
    return 0;
}