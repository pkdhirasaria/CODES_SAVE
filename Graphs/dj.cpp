#include <bits/stdc++.h>
using namespace std;
#define fr(a,b) for(i=a;i<b;i++)
#define frj(a,b) for(j=a;j<b;j++)
#define rep(a,b) for(i=a;i>=b;i--)
#define input(a,n) fr(i,n) cin>>a[i]
#define input2(a,n) fr(i,n){j =0; frj(j,n) cin>>a[i][j];}
#define print2(a,n) fr(i,n){j =0; frj(j,n) cout<<a[i][j]<<" "; nl();}
#define print(a,n) fr(i,n) {cout << a[i] << " ";} cout << endl
#define lli long long int
#define setbits __builtin_popcount
#define setValue(a,val,n) fr(i,n) a[i] = val;
#define pb push_back
#define fst first
#define scnd second
#define nl() cout<<"\n"
#define vi vector<int>
#define qi queue<int>
#define mii map<int,int>
#define mll map<lli,lli>
#define pii pair<int,int>
#define N 1000009

int dp[100][100];

int minDistance(bool *visited,int *weight,int  n)
{
    int mini = INT_MAX,minidx;
    for(int i =0;i<n;i++)
    {
        if(!visited[i] && weight[i] <= mini)
        {
            mini = weight[i];
            minidx = i;
        }
    }
    return minidx;
}

void dj(int n)
{
    bool *visited = new bool[n];
    int *weight = new int[n];
    int i =0;
    setValue(visited,false,n);
    i =0;
    setValue(weight,INT_MAX,n);
    weight[0] = 0;
    for(int i=0;i<n-1;i++)
    {
        int u = minDistance(visited,weight,n);
        visited[u] = true;
        for(int j =0;j<n;j++)
        {
            if(!visited[j] && dp[u][j]>0 && weight[u]!= INT_MAX && weight[j] > dp[u][j]+weight[u])
            {
                weight[j] = dp[u][j]+weight[u];
            }
        }
    }

    i =0;
    print(weight,n);
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int i=0,j=0;
    input2(dp,n);
    i = 0;
    dj(n);
}
