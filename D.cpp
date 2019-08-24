using namespace std;

#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<stack>

//#define di cout<<"enter"<<temp<<endl

vector<int>graph[100010];
bool taken[10010];
stack<int>TOP;


void dfs1(int s)
{
    int i;

    taken[s]=true;
    for(i=0;i<graph[s].size();i++)
    {
        if(taken[graph[s][i]]==false)
            dfs1(graph[s][i]);
    }

    TOP.push(s);
}

void dfs2(int s)
{
    int i;
    if(taken[s]==false)
    {
        taken[s]=true;
        for(i=0;i<graph[s].size();i++)
            dfs2(graph[s][i]);
    }
    //graph[s].clear();
}


int main()
{
    int t,u,v,m,n,i,Case=1,x,ans;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d%d",&n,&m);

        for(i=1;i<=n;i++)
        {
           taken[i]=false;
           graph[i].clear();
        }

        for(i=0;i<m;i++)
        {
            scanf("%d%d",&u,&v);

            graph[u].push_back(v);
        }

        ans=0;


        for(i=1;i<=n;i++)
        {
            if(taken[i]==false)
            {
                dfs1(i);
            }
        }

        for(i=1;i<=n;i++)
        {
           taken[i]=false;
        }

        while(!TOP.empty())
        {
            x=TOP.top();
            TOP.pop();
            if(taken[x]==false)
            {
                dfs2(x);
                ans++;
            }
        }

        printf("Case %d: %d\n",Case++,ans);

       /* for(i=1;i<=n;i++)
            graph[i].clear();*/
    }

    return 0;
}






/*using namespace std;

#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>

//#define di cout<<"enter"<<temp<<endl

vector<int>graph[100010];
bool taken[10010];
int ans,flag,par[10010],temp;



void dfs(int s)
{
    int i;

    if(taken[s]==false)
    {
        par[s]=temp;
        for(i=0;i<graph[s].size();i++)
        {
            if(taken[graph[s][i]]&&par[graph[s][i]]==graph[s][i])
                flag=0;
            else
            {
                if(par[graph[s][i]]==graph[s][i]&&graph[s][i]!=temp)
                {
                    dfs(graph[s][i]);
                }
            }

        }
        taken[s]=true;
    }
}


int main()
{
    int t,u,v,m,n,i,Case=1;
    scanf("%d",&t);

    while(t--)
    {
        map<int,int>mt;
        scanf("%d%d",&n,&m);

        for(i=1;i<=n;i++)
        {
           taken[i]=false;
           par[i]=i;

        }
        int mp=1;

        for(i=0;i<m;i++)
        {
            scanf("%d%d",&u,&v);
            if(!mt[u])
                mt[u]=mp++;
            if(!mt[v])
                mt[v]=mp++;
            graph[mt[u]].push_back(mt[v]);
        }

        ans=0;


        for(i=1;i<=n;i++)
        {
            if(taken[i]==false)
            {
                flag=1;
                temp=i;
                dfs(i);
                if(flag)
                    ans++;
            }
        }

        printf("Case %d: %d\n",Case++,ans);

        for(i=1;i<mp;i++)
            graph[i].clear();
    }

    return 0;
}*/
