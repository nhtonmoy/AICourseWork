#include<bits/stdc++.h>
using namespace std;

int cost[100];
int totalcost[100];
int G[100][100];
int H[100];

class Node{
public:
    int x;
    int cost;
    bool operator<(const Node &b) const{
        return cost>b.cost;
    }
};

void  ucs(Node root,int n)
{
    priority_queue<Node>pq;
    pq.push(root);
    cost[root.x]=root.cost;
    Node temp,t;
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
                    t.x=y;
                    t.cost=cost[y];
                    pq.push(t);
                }
            }
        }
    }
}

int main()
{
    int n,e,x,y,c;
    cout<<"Enter node numbers : ";
    cin>>n;
    cout<<"Enter edge numbers : ";
    cin>>e;

    for(int i=1;i<=n;i++)
    {
        cost[i]=INT_MAX;
    }

    for(int i=0;i<e;i++)
    {
        cout<<"Enter nodes: ";
        cin>>x>>y;
        cout<<"Enter cost : ";
        cin>>c;
        G[x][y]=c;
    }

    int goal, start;
    cout<<"Enter starting node: ";
    cin>>start;
    cout<<"Enter goal node: ";
    cin>>goal;
    Node t;
    t.x=start;
    t.cost=0;
//    cout<<"hi"<<endl;
    ucs(t,n);

    cout<<"Total cost = "<<cost[n]<<endl;

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
*/
