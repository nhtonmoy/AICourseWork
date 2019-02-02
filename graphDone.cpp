#include<cstdio>

int main()
{
    int edges;
    printf("number of edges: ");
    scanf("%d",&edges);
    int con[100][100];
    int s[100], d[100];
    int source, destination;


    int maxS=0, maxD=0, maxN=0;

    for(int i = 0; i < edges; i++)
    {
        printf("Source and Destination for Edge %d:  ", i );
        scanf("%d %d", &source,&destination);
        s[i]=source;
        d[i]=destination;

        con[source][destination]=1;



//        for(int j = 0; j < edges; j++)
//        {
//            scanf("%d", &con[i][j]);
//            //printf("\n%d %d %d\n%d\n",i,j, con[i][j],isConnected);
//        }
    }

    for(int i = 0; i<edges; i++)
    {

        for(int ms=0;ms<i;ms++)
        {
            if(s[i]>=s[ms]) maxS=s[i]; else maxS=s[ms];
        }

        for(int md=0;md<i;md++)
        {
            if(d[i]>=d[md]) maxD=d[i]; else maxD=d[md];
        }
    }


    int ds=0; //distinct sources
    bool isOnce=true;
    int sources[100], destinations[100];
    for(int i=0;i<edges;i++)
    {
        for(int j=0; j<i; j++)
        {
            if(s[i]==s[j]) {isOnce=false; break;}
            isOnce=true;

        }
        if(isOnce)
        {
            ds++;
            sources[i]=s[i];
            //printf("%d\n",sources[i]);
        }
    }
    for(int i=ds;i<100;i++)
    {
        sources[i]==-999;
    }

    for(int i=0; i<ds; i++)
    {
        if(sources[i]==-999) break;
        //printf("%d ", sources[i]);

    }

    int dd=0; //distinct destinations
    isOnce=true;
    for(int i=0;i<edges;i++)
    {
        for(int j=0; j<i; j++)
        {
            if(d[i]==d[j]) {isOnce=false; break;}
            isOnce=true;

        }
        if(isOnce)
        {
            dd++;
            destinations[i]=d[i];
            //printf("\n%d",destinations[i]);
        }
    }
    for(int i=dd;i<100;i++)
    {
        destinations[i]==-999;
    }
    printf("\n");

    for(int i=0; i<dd; i++)
    {
        if(destinations[i]==-999) break;
        //printf("%d ", destinations[i]);

    }

    int tnodes=0;


    if(maxS>maxD){maxN=maxS;} else {maxN=maxD;}

    printf("%d  %d  \n\n",maxS, maxD);
    //return 0;



    bool isLineFinished=false;
    for(int i = 0; i <= maxN; i++)
    {
        printf("\n    ");
        if(!isLineFinished)
        {
            for(int x=0; x<=maxN; x++)
            {
                printf("E%d ",x);
            }
            isLineFinished=true;
        }
        printf("\nV%d  ",i);

        for(int j = 0; j <= maxN; j++)
        {
            printf("%d  ", con[i][j]);
        }
    }
}
