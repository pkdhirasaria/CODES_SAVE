#include <bits/stdc++.h>
#define ll long long
using namespace std;


ll minVertex(bool *visited,ll *weight,ll n)
{
    int ans = -1;
    for(ll i = 0;i<n;i++)
    {
        if(!visited[i] && (ans == -1 ||weight[i] < weight[ans]))
        {
            ans = i;
        }
    }
    return ans;
}

void prims(ll **edge,ll V)
{
    ll *parent = new ll [V];
    ll *weight = new ll [V];
    bool *visited = new bool[V];
    for(int i = 0;i<V;i++)
    {
        parent[i] = i;
        weight[i] = INT_MAX;
        visited[i]= false;
    }
    parent[0] = -1;
    //visited[0] = true;
    weight[0] = 0;
    for(ll i = 0;i<V;i++)
    {
        ll min_vertex = minVertex(visited,weight,V);
        visited[min_vertex]  = true;
        for(ll j = 0;j<V;j++)
        {
            if(!visited[j] && edge[min_vertex][j] > 0 && edge[min_vertex][j] <weight[j])
            {
                weight[j] = edge[min_vertex][j];
                parent[j] = min_vertex;
            }
        }
    }
    ll sum = 0;
    for(int i =1;i<V;i++)
    {
       sum += weight[i];
    }
    cout<<sum<<endl;
}


int main()
{
  long long V, E, tempX, tempY;
  cin >> V >> E;
  ll **edge = new ll *[V];
  for(ll i =0;i<V;i++)
  {
      edge[i] = new ll[V];
  }
     for(int i = 0;i<V;i++)
        for(int j = 0;j<V;j++)
            edge[i][j] = 0;

  for(ll i = 0;i<E;i++)
  {
    ll s,d,w;
    cin>>s>>d>>w;
    edge[s-1][d-1] = w;
    edge[d-1][s-1] = w;
  }
  prims(edge,V);

  return 0;
}
