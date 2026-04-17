#include <iostream>
using namespace std;

int main() {
    int month,day,year;

    cout<<"Enter month (numeric): ";
    cin>>month;

    cout<<"Enter day: ";
    cin>>day;

    cout<<"Enter two-digit year: ";
    cin>>year;

    int result=month*day;

    cout<<"Calculation: "<<month<<" * "<<day<<" = "<<result<<endl;

    if(result==year){
        cout<<"Result: MAGIC DATE."<<endl;
    } else {
        cout<<"Result: NOT MAGIC."<<endl;
    }
    return 0;
}
