#include <iostream>
using namespace std;

int main() {
    int model;
    
    cout<<"Enter TV model (100, 200, or 300): ";
    cin>>model;

    if(model==300){
        cout<<"Features: Picture-in-a-picture, Stereo sound, Remote control"<<endl;
    }
    else if(model==200){
        cout<<"Features: Stereo sound, Remote control"<<endl;
    }
    else if(model==100){
        cout<<"Features: Remote control only"<<endl;
    }
    else {
        cout<<"Invalid model selected."<<endl;
    }
    return 0;
}
