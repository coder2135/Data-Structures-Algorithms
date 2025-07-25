#include<iostream>
#include<vector>
using namespace std;
void heapify(vector<int>&vec,int i,int n){
    int l = 2*i+1;
    int r = 2*i+2;
    int maxI = i;
    if(l<n && vec[l] > vec[i]){
        maxI = l;
    }
    if(r<n && vec[r] > vec[maxI]){
        maxI = r;
    }
    if(maxI != i){
        swap(vec[i],vec[maxI]);
        heapify(vec,maxI,n);
    } 
}
void HeapSort(vector<int> &vec,int n){
    //Step 1 : Build a max heap
    for(int i=n/2-1;i>=0;i--){
        heapify(vec,i,n);
    }
    //Step 2 : Taking element to correct position
    for(int i=n-1;i>=0;i--){
        swap(vec[0],vec[i]);
        heapify(vec,0,i);
    }
}
int main(){
    vector<int> vec = {5,3,4,1,2,0};
    int n = vec.size();
    HeapSort(vec,n);
    for(int i=0;i<n;i++){
        cout<<vec[i]<<" ";
    }
    return 0;
}
