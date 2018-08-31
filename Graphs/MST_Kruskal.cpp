
//Using Kruskal Algorithm with checking of cycle using union methon

//Algorithm
//Sort the weight of edges in ascending order 
//Assign the parent array with the value of self node number..ex parent[1] = 1, parent[2] = 2
//if there are n vertext the for MST there will be n-1 edges
//find the parent of both destination and source
// if there parent is same means their edge will form cycle so we can't include that in our MST 
//else we will include it in our MST



#include <bits/stdc++.h>
#define ll long long
using namespace std;


struct Edge
{
  ll source;
  ll dest;
  ll weight;
};

ll findParent(int V,int *parent)
{
  if(V == parent[V])
    return V;
  return findParent(parent[V],parent);
}

bool compare(Edge e1,Edge e2)
{
  return e1.weight < e2.weight;
}

void kruskal(Edge *edge,int V,int E)
{
  int *parent = new int[V];
  for(int i = 0;i<V;i++)
    parent[i] = i;

  ll i = 0;
  ll count =0;
  sort(edge,edge+E,compare);
  while(count < V-1)
  {
    Edge currentNode = edge[i];
    ll sParent = findParent(currentNode.source,parent);
    ll dParent = findParent(currentNode.dest,parent);
    if(sParent != dParent)
    {
      if(currentNode.source <currentNode.dest)
     	cout<<currentNode.source<<" "<<currentNode.dest<<" "<<currentNode.weight<<endl;
      else
        cout<<currentNode.dest<<" "<<currentNode.source<<" "<<currentNode.weight<<endl;
      parent[sParent] = dParent;
      count ++;
    }
    i++;
  }
}


int main()
{
  long long V, E, tempX, tempY;
  cin >> V >> E;
  Edge *edge = new Edge[E];
  for(int i = 0;i<E;i++)
  {
    ll s,d,w;
    cin>>s>>d>>w;
    edge[i].source =s;
    edge[i].dest = d;
    edge[i].weight = w;
  }
  kruskal(edge,V,E);

  return 0;
}
