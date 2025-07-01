#include<iostream>
using namespace std;
class Car{
    public:
    string name;
    string color;
    int *milege;
    Car(string name,string color){  //CONSTRUCTOR
        this->name = name;
        this->color = color;
        milege = new int;
        *milege = 10;
    }
    Car(Car &original){  //CUSTOM CONSTRUCTOR (NOT NECCESSARY FOR SHALLOW COPY)
        name = original.name;
        color = original.color;
        milege = original.milege;
    }
    ~Car(){  //DISTRUCTOR
        cout<<"deleting memory from heap..\n";
        if(milege != NULL){
            delete milege;    //deleting memory from heap
            milege = NULL;
        }
    }
};
int main(){
    Car c1("Audi","white");
    cout<<"milege of car c1 is : "<<*c1.milege<<endl;
    Car c2(c1); //copy constructor
    cout<<"milege of car c2 is : "<<*c2.milege<<endl;
    return 0;
}