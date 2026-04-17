#include <iostream>
using namespace std;

int main() {
    float income;
    int years;

    cout<<"Enter your annual income: ";
    cin>>income;

    cout<<"Enter years at current job: ";
    cin>>years;

    if(income>=35000&&years>5){
        cout<<"Congratulations! You qualify for the special loan."<<endl;
    } else{
        cout<<"Sorry, you do not qualify for the special loan."<<endl;
    }
    return 0;
}
