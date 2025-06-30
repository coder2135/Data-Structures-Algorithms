#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    //Constructor
    Node(int val){
        data = val;
        next = NULL;
    }
    ~Node(){
        if(next!=NULL){
            delete next;
           // cout<<"Deleting "<<data<<" from memory \n";
            next = NULL;
        }
    }
};
class List{
public : 
    Node* head;
    Node* tail;
    //Constructor
    List(){
        head = NULL;
        tail = NULL;
    }
    void push_front(int val){
        Node* newNode = new Node(val);  //new node dynamically
        if(head == NULL){
            head = tail = newNode;
        }else{
            newNode->next = head;
            head = newNode;
        }
    }
    void push_back(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
    }
    void insert(int val,int idx){
        Node* newNode = new Node(val);
        Node* temp = head;
        for(int i=0;i<idx-1;i++){
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    void printList(){
        Node * temp = head;
        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<"NULL\n";
    }
    void pop_front(){
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    void pop_back(){
        Node* temp = head;
        while(temp->next != tail){
            temp = temp->next;
        } 
        delete tail;          // Delete the last node
        tail = temp;          // Update tail to the second-to-last node
        tail->next = NULL; 
    }
    void search(int val){
        Node* temp = head;
        int count = 0;
        while(temp!=NULL){
            if((temp->data)==val){
                //cout<<"Key found at index : "<<count<<endl;
                return ;
            }else{
                temp = temp->next;
                count++;
            }
        }
        cout<<"key not found \n";
    }
    ~List(){
        //cout<<"List distructor is being called..\n";
        if(head!=NULL){
            delete head;  //Deleting the node which head is pointing
            head = NULL;
        }
    }
};
int main(){
    List ll;
    ll.push_back(11);
    ll.push_back(2);
    ll.push_back(30);
    ll.push_back(43);
    ll.push_back(0);
    ll.push_back(9);
    ll.printList();
    return 0;
}