//To print the components of graph, it takes input in form of source destination not adj matrix.


#include <bits/stdc++.h>
#define fr(a,b) for(i=a;i<b;i++)
#define rep(a,b) for(i=a;i>=b;i--)
#define f first
#define s second
#define input(a,n) fr(i,n) cin>>a[i]
#define print(a,n) fr(i,n) {cout << a[i] << " ";} cout << endl
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAX 100000
using namespace std;

class Component
{
    public:
    int a[100];
    int n;
};

void DFS(ll *visited,ll n,ll **edge,int src,int componentNumber)
{
    visited[src] = componentNumber;
    //cout<<src+1<<" ";
    for(int i = src;i<n;i++)
    {
        if(visited[i] == 0 && edge[src][i] ==1)
        {
            DFS(visited,n,edge,i,componentNumber);
        }
    }
}

void check(ll **edge,ll n)
{
    ll *visited = new ll[n];
    for(int i = 0;i<n;i++)
    {
        visited[i] = 0;
    }
    int componentNumber = 0;
    Component component[1000];
    for(int i = 0;i<n;i++)
    {
        if(visited[i] == 0)
        {
            DFS(visited,n,edge,i,i+1);
            component[componentNumber].n = 0;
            //cout<<"FOR I :"<<i<" : ";
            for(int j = 0;j<n;j++)
            {
                if(visited[j] == i+1)
                {

                    component[componentNumber].a[component[componentNumber].n++] = j;
                    //cout<<component[componentNumber].a[component[componentNumber].n]<<" ";

                }

            }
            componentNumber++;
        }
    }
    for(int i = 0;i<componentNumber;i++)
    {
        for(int j =0;j<component[i].n;j++)
        {
            cout<<component[i].a[j]+1<<" ";
        }
        cout<<endl;
    }



}


int main()
{
    ll n,m;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        ll **edge = new ll*[n+1];
        for(int i = 0;i<n+1;i++)
            edge[i] = new ll[n+1];
        for(int i = 0;i<n+1;i++)
            for(int j = 0;j<n+1;j++)
                edge[i][j] = 0;
        for(int i = 0;i<m;i++)
        {
            int s,d;
            cin>>s>>d;
            edge[s-1][d-1] = 1;
            edge[d-1][s-1] = 1;
        }
        check(edge,n);
        //print 2d array
        /*for(int i =0;i<n;i++)
        {
            for(int j =0;j<n;j++)
            {
                cout<<edge[i][j];
            }
            cout<<endl;
        }*/

    }


  return 0;
}
