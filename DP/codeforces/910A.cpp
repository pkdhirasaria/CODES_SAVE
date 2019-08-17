

// https://codeforces.com/problemset/problem/910/A


#include <bits/stdc++.h>
#include <limits>
#define fr(a,b) for(i=a;i<b;i++)
#define rep(a,b) for(i=a;i>=b;i--)
#define f first
#define s second
#define inp(a,n) fr(i,n) cin>>a[i]
#define print(a,n) fr(i,n) {cout << a[i] << " ";} cout << endl
#define ll long long
using namespace std;

int main()
{
    {
        ll n,d;
        cin>>n>>d;
        string s;
        cin>>s;
        int dp[101];
        dp[0] = 0;
        for(int i =1;i<n;i++)
        {
            if(s[i] == '1')
            {
                dp[i]= 999999;
                for(int j=i-d;j<=i;j++)
                {
                    if(j>=0)
                        dp[i] = min(dp[i],dp[j]+1);
                }
            }
            else
            {
                dp[i] = 999999;
            }
        }
        if(dp[n-1] != 999999)
            cout<<dp[n-1]<<"\n";
        else
        {
            cout<<"-1";
        }

    }

    return 0;
}
