#include<bits/stdc++.h>
using namespace std;

int cost[1000][1000];
int G[1000][1000];

class Node{
public:
    int x,y;
    int cost;
    bool operator<(const Node &b) const{
        return cost>b.cost;
    }
};
void  ucs(Node root,int r,int c)
{
    priority_queue<Node>pq;
    pq.push(root);
    cost[root.x][root.y]=root.cost;
    Node temp,t;
    int x,y;
    int z;
    int xx,yy;
    while(!pq.empty())
    {
        temp=pq.top();
        pq.pop();
//        cout<<temp.x<<" "<<temp.y<<endl;
        xx=temp.x+1;
        yy=temp.y;
        if(xx<r)
        {
            if(cost[xx][yy]>cost[temp.x][temp.y]+G[xx][yy])
            {
                cost[xx][yy]=cost[temp.x][temp.y]+G[xx][yy];
                Node ab;
                ab.x=xx;
                ab.y=yy;
                ab.cost=cost[xx][yy];
                pq.push(ab);
            }
        }
        xx=temp.x;
        yy=temp.y+1;
        if(yy<c)
        {
            if(cost[xx][yy]>cost[temp.x][temp.y]+G[xx][yy])
            {
                cost[xx][yy]=cost[temp.x][temp.y]+G[xx][yy];
                Node cd;
                cd.x=xx;
                cd.y=yy;
                cd.cost=cost[xx][yy];
                pq.push(cd);
            }
        }

    }
}

int main()
{
//    READ;
    int n,m,x,y;
    int c;
    cout<<"Enter node numbers: ";
    cin>>n;
    cout<<"Enter edge numbers : ";
    cin>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cost[i][j]=INT_MAX;

    }
    cout<<"Enter the matrix : "<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>G[i][j];
        }
    }
//    cout<<"yo"<<endl;
    Node t;
    t.x=0;
    t.y=0;
    t.cost=G[0][0];
    ucs(t,n,m);
    cout<<"\nCost is : "<<cost[n-1][m-1]<<endl;

    return 0;
}

/*
5 5
131 673 234 103 18
201 96 342 965 150
630 803 746 422 111
537 699 497 121 956
805 732 524 37 331
*/
