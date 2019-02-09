#include<iostream>
#include<sstream>
using namespace std;


string Agent(string arr[1][2])
{
    string a = "";

    if(arr[0][1] == "dirty")
    {
        a = "suck";
    }
    else if(arr[0][0] == "a")
    {
        if(arr[0][1] == "clean")
            a = "right";
        else
            a = "Invalid Input";
    }
    else if(arr[0][0] == "b")
    {
        if(arr[0][1] == "clean")
            a = "left";
        else
            a = "Invalid Input";
    }
    else
        a = "Invalid Input";

    return a;
}

int main()
{
    while(1)
    {
        string location="",status="";

        cout<<"Please enter location : ";
        cin>>location;
        cout<<"Please enter status : ";
        cin>>status;

        string arr[1][2] = {location, status};

        cout<<Agent(arr)<<endl;
    }
}
