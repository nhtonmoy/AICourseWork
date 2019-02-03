#include<cstdio>
#include<iostream>>
using namespace std;

int REFLEX_VACCUM_AGENT(int location, int state)
{
    if(state==2)
    {
        return 1;
    }
    else
    {
        if(location==1)
        {
            return 2;
        }
        else if(location==2)
        {
            return 3;
        }
    }
}

int main()
{
    int loc, st;
    printf("Enter 1 for Clean, 2 for dirty\n");
    printf("Enter Cleaner's Location: ");

    scanf("%d",&st);
    if(st!=1  && st!=2) {printf("invalid input\n"); return 0;}

    printf("Enter 1 for location A, 2 for location B\n");
    printf("Enter cleaner's location: ");
    scanf("%d",&loc);

    if(loc!=1 && loc!=2) {printf("invalid input\n"); return 0;}

    int action=REFLEX_VACCUM_AGENT(loc, st);

    if(action==1) printf("\nSuck\n");
    else if(action==2) printf("\nRight\n");
    else if(action==3) printf("\nLeft\n");

    return 0;
}

