#include <iostream>
using namespace std;

int main()
{
    double a=10;
    double b=10;

    a=a+0.2;

    if(a>b)
    {
        cout<<"a is larger: "<<a<<endl;
        cout<<"b is smaller: "<<b<<endl;
    }
    else if(b>a)
    {
        cout<<"b is larger: "<<b<<endl;
        cout<<"a is smaller: "<<a<<endl;
    }
    else
    {
        cout<<"Both are equal."<<endl;
    }
    return 0;
}
