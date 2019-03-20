#include<bits/stdc++.h>
using namespace std;

int color[100],dis[100],par[100],fin[100],u,v,n,e, adj[100][100];
int tim;
void dfs_visit(int u)
{
    color[u]=1;
    dis[u]=++tim;
    cout<<u<<"   "<<tim<<'\n';
    for(v=0;v<n;v++)
    {
        if(adj[u][v]==1)
        {
            if(color[v]==0)
            {
                par[v]=u;
                dfs_visit(v);
            }
        }
    }
    fin[u]=++tim;
    cout<<tim<<endl;
    color[u]=2;
}

void dfs()
{
    for(u=0;u<n;u++)
    {
        color[u]=0;
        par[u]=-1;
    }
    for(u=0;u<n;u++)
    {
        if(color[u]==0)
        {
            dfs_visit(u);
        }
    }
}

int main()
{
    int i,j,x,y;
    cin>>n>>e;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            adj[i][j]=0;
        }
    }
    for(i=0;i<e;i++)
    {
        cin>>x>>y;
        adj[x][y]=1;
    }
    dfs();

    return 0;
}
