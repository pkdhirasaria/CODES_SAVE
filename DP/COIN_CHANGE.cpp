
//https://www.hackerrank.com/challenges/coin-change/problem


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
using namespace std;

ll coin_change(ll a[51],ll sum,ll n)
{
    ll dp[n+1][sum+1];
    memset(dp,0,sizeof(dp));
    //if number of coin is zero then it's not possible to achieve any sum so 0
    for(int i = 0;i<=sum;i++) 
        dp[0][i] = 0;
    //if sum is zero but we have n, then we have one choice not to take any coin 
    for(int i = 0;i<=n;i++)
        dp[i][0] = 1;
    for(int i = 1;i<=n;i++)
    {
        for(int j = 1;j<=sum;j++)
        {
            dp[i][j] = dp[i-1][j];
            if(j>=a[i-1])
            {
                dp[i][j] = max(dp[i][j],dp[i][j] + dp[i][j-a[i-1]]);
            }
        }
       
    }
    return dp[n][sum];
}

int main()
{
    ll sum,n;
    cin>>sum>>n;
    ll a[51];
    ll i = 0;
    input(a,n);
    cout<<coin_change(a,sum,n);


}


