#include<bits/stdc++.h>
#include<queue>
using namespace std;
int u, vis[100],n,e,adj[100][100],par[100];
int x[100];
int traversed[100];
bool pr=true;
int startNode, endNode;
bool endFound=false;
void bfs_visit(int u)
{
    queue<int> Q;
    Q.push(u);
    //vis[u];
    while(!Q.empty())
    {
        u=Q.front();

        //cout<<endl<<'\t'<<Q.front()<<'\t'<<traversed[i];

        if(!(u==startNode && !pr))
            cout<<u<<" ";
        Q.pop();
        if(u==endNode)
        {
            endFound=true;
            break;
        }
        if(u==startNode) pr=false;


        for(int v=0;v<n;v++)
        {
            if(adj[u][v] == 1)
            {
                if(vis[v]==0)
                {
                    par[v] = u;
                    vis[v] = 1;
                    Q.push(v);
                }
            }
        }
    }
}
void  bfs()
{
    for(int  i=0;i<n;i++)
    {
        vis[i]=0;
        par[i]=-1;
    }
    for(int i=0;i<n;i++)
    {
        if(vis[i]==0)
        {
            if(endFound==false)
                bfs_visit(startNode);
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

    cin>>startNode>>endNode;
    bfs();
    if(endFound==false) cout<<endl<<"End node wasn't found"<<endl;
}

// 6 10 1 0 0 2 2 1 0 5 2 4 2 3 3 0 3 5 1 4 4 5
