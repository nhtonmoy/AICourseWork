#include<bits/stdc++.h>
using namespace std;

int cost[100];
int totalcost[100];
int G[100][100];
int H[100];

struct node{
    int x;
    int cost;
    bool operator<(const node &b) const{
        return cost>b.cost;
    }
};

void  Astar(node root,int n)
{
    priority_queue<node>pq;
    pq.push(root);
    cost[root.x]=root.cost;
    totalcost[root.x]=root.cost+H[root.x];
    node temp,t;
    int x,y;

    while(!pq.empty())
    {
        temp=pq.top();
        pq.pop();
        x=temp.x;
        for(int y=1; y<=n; y++)
        {
            if(G[x][y])
            {
                if(cost[y]>cost[x]+G[x][y])
                {
                    cost[y]=cost[x]+G[x][y];
                    totalcost[y]=cost[y]+H[y];
                    t.x=y;
                    t.cost=totalcost[y];
                    pq.push(t);
                }
            }
        }
    }
}

int main()
{
    int n,e,x,y,c;
    cout<<"Enter node number : ";
    cin>>n;
    cout<<"Enter edge number : ";
    cin>>e;
    for(int i=1;i<=n;i++)
    {
        cost[i]=INT_MAX;
    }
    cout<<"Enter nodes & cost : "<<endl;
    for(int i=0;i<e;i++)
    {
       cin>>x>>y>>c;
       G[x][y]=c;
    }
    cout<<"Enter Huristic value : "<<endl;
    for(int i=1;i<=n;i++)
    {
       cin>>H[i];
    }

    node t;
    t.x=1;
    t.cost=0+H[0];
//    cout<<"hi"<<endl;
    Astar(t,n);

    cout<<"Total cost = "<<totalcost[n]<<endl;

    return 0;
}


/*
7 10
1 2 5
1 4 3
2 3 1
3 5 6
3 7 8
7 5 4
5 2 4
4 5 2
4 6 2
6 7 3
100
120
200
220
300
400
500
*/

