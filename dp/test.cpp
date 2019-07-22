#include <bits/stdc++.h>
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
    int n,p,q,r;
    cin>>n>>p>>q>>r;
    int a[n];
    int i=0;
    inp(a,n);
    int dp0[n],dp1[n],dp2[n];
    dp0[0] = a[0]*p;
    for(int i= 1;i<n;i++)
    {
        dp0[i] = max(dp0[i-1],a[i]*p);
    }

    cout<<"dp0 : ";
    i =0;
    print(dp0,n);
    dp1[0] = dp0[0] + a[0]*q;
    for(int i= 1;i<n;i++)
    {
        dp1[i] = max(dp1[i-1],dp0[i] + a[i]*q);
    }
    cout<<"dp1 : ";
    i =0;
    print(dp1,n);
    dp2[0] = dp1[0] + a[0]*r;
    for(int i= 1;i<n;i++)
    {
        dp2[i] = max(dp2[i-1],dp1[i] + a[i]*r);
    }

    cout<<"dp2 : ";
    i =0;
    print(dp2,n);
    cout<<dp2[n-1];
    return 0;
}
