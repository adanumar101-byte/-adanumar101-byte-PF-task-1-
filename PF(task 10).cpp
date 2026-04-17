#include <iostream>
using namespace std;

int main() {
    float mass,weight;

    cout<<"Enter the mass of the object (in kg): ";
    cin>>mass;

    weight=mass*9.8;

    cout<<"Weight of the object = "<<weight<<" newtons"<<endl;

    if(weight>1000){
        cout<<"The object is too heavy."<<endl;
    } 
    else if(weight<10){
        cout<<"The object is too light."<<endl;
    }
    return 0;
}
