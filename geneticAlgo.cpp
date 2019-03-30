#include<bits/stdc++.h>
using namespace std;
///
int n;
int vis[10];
int cromosom[10][6];
int tmp[6];
int cromosomTmp[10][6];
int fitness[10];
int pow2[10];
void binary(int val,int row)
{
    int ind=0;
    while(val)
    {
//        cout<<val%2<<" ";
        cromosom[row][ind]=val%2;
        val/=2;
        ind++;
    }
//    cout<<endl;
    for(int j=ind;j<5;j++)
        cromosom[row][j]=0;
    for(int j=4;j>=0;j--)
    {
        cout<<cromosom[row][j]<<" ";
    }
    cout<<endl;
}
int dec(int row)
{
    int val=0;
    for(int i=0;i<5;i++)
    {
        val+=(cromosom[row][i]*pow2[i]);
    }
    return val;
}
int fitnessValue(int val,int row)
{
    return fitness[row]=val*val;
}
void selection()
{
    memset(vis,0,sizeof(vis));
    int t=n/2,x1,x2;
    int ind=0;
    while(t--)
    {
        x1=rand()%n;
//        cout<<"selection x1"<<endl;
        while(vis[x1])
        {
            x1=rand()%n;
//            cout<<x1<<endl;
        }
        vis[x1]=1;
        x2=rand()%n;
        while(vis[x2])
        {
            x2=rand()%n;
        }
        vis[x2]=1;
        ///x1 & x2 cromosoms are selected for cross;
        for(int i=0;i<5;i++)
        {
            cromosomTmp[ind][i]=cromosom[x1][i];
            cromosomTmp[ind+1][i]=cromosom[x2][i];
        }
        ind+=2;
    }
}
void crossover()
{
    int t=n/2,x1,x2,tmp;
    int ind=0;
    while(t--)
    {
        x1=rand()%(5-1);
        while(x1<=0)
        {
            x1=rand()%(n-1);
        }
        for(int i=0;i<x1;i++)
        {
            tmp=cromosomTmp[ind][i];
            cromosomTmp[ind][i]=cromosomTmp[ind+1][i];
            cromosomTmp[ind+1][i]=tmp;
        }
        ind+=2;
    }
}
void mutation()
{
    int x1;
    for(int i=0;i<n;i++)
    {
        x1=rand()%5;
        cout<<"mutation "<<" "<<x1<<endl;
        cromosomTmp[i][x1]=!cromosomTmp[i][x1];
    }
}
void assignn()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<5;j++)
        {
            cromosom[i][j]=cromosomTmp[i][j];
        }
        for(int j=4;j>=0;j--)
        {
                cout<<cromosom[i][j]<<" ";
        }
        cout<<endl;

    }
}
int calMaxXval()
{
    int maxx=-1;
    for(int i=0;i<n;i++)
    {
        maxx=max(maxx,dec(i));
    }
    return maxx;
}
int main()
{
    pow2[0]=1;
    for(int i=1;i<10;i++)
    {
        pow2[i]=pow2[i-1]*2;
    }
    srand(1e9+7);
//    int t=20;
//    while(t--)
//    cout<<rand()%2<<endl;
    cout<<"Set initial population "<<endl;
    cin>>n;
    int x;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        binary(x,i);
//        cout<<dec(i)<<endl;
    }
    int it=0;
    int maxx=-1,m;
    while(1)
    {
        selection();
//        cout<<"asce"<<endl;
        crossover();
        mutation();
        assignn();
        m=calMaxXval();
//        cout<<m<<endl;
        maxx=max(maxx,m);
        it++;
        if(maxx==31)
            break;
    }
    cout<<maxx<<" "<<it<<endl;
    return 0;
}
/*
4
13
24
8
19
*/
