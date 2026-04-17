#include <iostream>
using namespace std;

int main() {
    float sales,commissionRate,commission;

    cout<<"Enter sales amount: ";
    cin>>sales;

    if(sales<=10000){
        commissionRate=0.10;
    }
    else if(sales<=15000){
        commissionRate=0.15;
    }
    else {
        commissionRate=0.20;
    }

    commission=sales*commissionRate;

    cout<<"Commission Rate = "<<commissionRate*100<<"%"<<endl;
    cout<<"Commission Amount = "<<commission<<endl;
    return 0;
}
