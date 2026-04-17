#include <iostream>
using namespace std;

int main() {
    char ch;

    cout<<"ASCII values of Uppercase Alphabets:\n";
    for(ch='A';ch<='Z';ch++){
        cout<<ch<<" = "<<(int)ch<<endl;
    }

    cout<<endl;

    cout<<"ASCII values of Lowercase Alphabets:\n";
    for(ch='a';ch<='z';ch++){
        cout<<ch<<" = "<<(int)ch<<endl;
    }
    return 0;
}
