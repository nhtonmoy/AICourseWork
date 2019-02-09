#include <iostream>

using namespace std;

string Interpret_Input(string a[2])
{
    string state = a[0];
    return state;
}

string Rule_Match(string state, string rules[],string a[2])
{
    string cur="", cond="";
    for(int i=0; i<3; i++)
    {
        if(a[1]==rules[i])
        {
            cond=rules[i];
        }
    }

    if(state == "A")
    {
        if(cond == "clean")
        {
            cur = "ac";
        }
        else if(cond == "dirty")
        {
            cur = "ad";
        }
    }
    else if(state == "B")
    {
        if(cond == "clean")
        {
            cur = "bc";
        }
        else if(cond == "dirty")
        {
            cur = "bd";
        }
    }
    return cur;
}

string Rule_Action(string state)
{
    string action="";
    if(state == "ac")
    {
        action = "Right";
    }
    else if(state == "bc")
    {
        action = "Left";
    }
    else if(state == "ad" || state == "bd")
    {
        action = "suck";
    }
    else action= "invalid input";
    return action;
}

string Simple_Reflex_Agent(string a[2])
{
    string rules [] = {"dirty", "clean"};
    string action="", state="", rule="";
    state = Interpret_Input(a);
    rule = Rule_Match(state,rules,a);
    action = Rule_Action(rule);

    return action;
}

int main()
{
    string location, condition;
    //string arrr[0][1];
    while(1)
    {
        cout << "Enter Location : ";
        cin >> location;
        cout << "Enter Condition : ";
        cin >> condition;
        string s[2]={ location, condition};

        cout << Simple_Reflex_Agent(s) << endl << endl;
    }


    return 0;
}
