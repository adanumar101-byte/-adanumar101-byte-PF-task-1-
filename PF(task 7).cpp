#include <iostream>
using namespace std;

int main()
{
    double runner1,runner2,runner3;

    cout<<"Enter time in minutes for Runner 1: ";
    cin>>runner1;

    cout<<"Enter time in minutes for Runner 2: ";
    cin>>runner2;

    cout<<"Enter time in minutes for Runner 3: ";
    cin>>runner3;

    if(runner1<=0||runner2<=0||runner3<=0)
    {
        cout<<"Invalid time entered."<<endl;
    }
    else
    {

        if(runner1<=runner2&&runner1<=runner3)
        {
            cout<<"First place: Runner 1"<<endl;

            if(runner2<=runner3)
            {
                cout<<"Second place: Runner 2"<<endl;
                cout<<"Third place: Runner 3"<<endl;
            }
            else
            {
                cout<<"Second place: Runner 3"<<endl;
                cout<<"Third place: Runner 2"<<endl;
            }
        }
        else if(runner2<=runner1&&runner2<=runner3)
        {
            cout<<"First place: Runner 2"<<endl;

            if(runner1<=runner3)
            {
                cout<<"Second place: Runner 1"<<endl;
                cout<<"Third place: Runner 3"<<endl;
            }
            else
            {
                cout<<"Second place: Runner 3"<<endl;
                cout<< "Third place: Runner 1"<<endl;
            }
        }
        else
        {
            cout<<"First place: Runner 3"<<endl;

            if(runner1<=runner2)
            {
                cout<<"Second place: Runner 1"<<endl;
                cout<<"Third place: Runner 2"<<endl;
            }
            else
            {
                cout<<"Second place: Runner 2"<<endl;
                cout<<"Third place: Runner 1"<<endl;
            }
        }
    }

    return 0;
}
