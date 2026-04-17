#include <iostream>
using namespace std;

int main()
{
    int choice;
    double radius,length,width,base,height,area;
    const double pi=3.14159;

    cout<<"Geometry Calculator"<<endl;
    cout<<"1. Calculate the Area of a Circle"<<endl;
    cout<<"2. Calculate the Area of a Rectangle"<<endl;
    cout<<"3. Calculate the Area of a Triangle"<<endl;
    cout<<"Enter your choice (1-3): ";
    cin>>choice;

    if(choice==1)
    {
        cout<<"Enter radius of the circle: ";
        cin>>radius;

        area=pi*radius*radius;
        cout<<"Area of the circle is: "<<area<<endl;
    }
    else if(choice==2)
    {
        cout<<"Enter length of the rectangle: ";
        cin>>length;

        cout<<"Enter width of the rectangle: ";
        cin>>width;

        area=length*width;
        cout<<"Area of the rectangle is: "<<area<<endl;
    }
    else if(choice==3)
    {
        cout<<"Enter base of the triangle: ";
        cin>>base;

        cout<<"Enter height of the triangle: ";
        cin>>height;

        area=base*height*0.5;
        cout<<"Area of the triangle is: "<<area<<endl;
    }
    else
    {
        cout<<"Invalid choice. Please enter 1, 2, or 3."<<endl;
    }
    return 0;
}
