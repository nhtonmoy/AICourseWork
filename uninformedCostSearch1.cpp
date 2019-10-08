#include<bits/stdc++.h>
using namespace std;

int cost[100];
int totalcost[100];
int G[100][100];
int H[100];

class node{
public:
    int x;
    int cost;
    bool operator<(const node &b) const{
        return cost>b.cost;
    }
};

void  ucs(node root,int n)
{
    priority_queue<node>pq; //priority queue of node type is created
    pq.push(root); //queue te push korlam root object er attributes, ekdom main function er parameter theke jeta first call hoise
    cost[root.x]=root.cost; //cost array er root.x no element e root.cost insert korlam, first element er cost
    node temp,t; //temp and t name e node class er duita object create korlam
    int x,y;

    while(!pq.empty()) //queue empty na howa porjonto cholte thakbe loop ta
    {
        temp=pq.top(); //temp object e queue er top element ta insert hobe (first object er attributes)
        pq.pop(); //top element pop hoye gelo
        x=temp.x; //temp object er x attribute ta ke x variable e assign korlam
        for(int y=1; y<=n; y++) //1st node theke nth node porjonto loop cholbe (main function e je node and edges disilam)
        {
            if(G[x][y]) //x ar y node er path ase ki na
            {
                if(cost[y]>cost[x]+G[x][y]) //y node er total cost ki x node er total cost and x and y er path cost er jogfol er cheye boro ki na
                {
                    cost[y]=cost[x]+G[x][y]; //y node er new total cost assign korlam
                    t.x=y; //t object er x er value assign korlam, new node to be checked
                    t.cost=cost[y]; //t object er cost e new total cost assign korlam
                    pq.push(t); //queue te t object ta push kore dilam, t is the new top element
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

    node t;
    t.x=1;
    t.cost=0;
//    cout<<"hi"<<endl;
    ucs(t,n);

    cout<<"Total cost = "<<cost[n]<<endl;

    return 0;
}


/*7 10
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
