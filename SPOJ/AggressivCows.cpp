

/* problem link :

https://www.spoj.com/problems/AGGRCOW/

*/


#include <bits/stdc++.h>
using namespace std;
#define fr(a,b) for(i=a;i<b;i++)
#define rep(a,b) for(i=a;i>=b;i--)
#define input(a,n) fr(i,n) cin>>a[i]
#define print(a,n) fr(i,n) {cout << a[i] << " ";} cout << endl
#define lli long long int
#define ull unsigned long long

bool findPossible(lli a[],lli n,lli mid,lli c)
{

    //cout<<"============================================="<<endl;
    //cout<<"FOR MID VALUE : "<<mid<<endl;
    int lastpossible= a[0];
    lli cows = 1;
    for(int i =1;i<n;i++)
    {
        //cout<<"lastpossible  :"<<lastpossible;
        //cout<<"C : "<<c<<endl;
        if(a[i]-lastpossible >= mid)
        {
            lastpossible = a[i];
            cows++;

        }
        if(c == cows)
                return true;
    }
    return false;
}


lli aggressiveCows(lli a[],lli n,lli c)
{
    lli ans = -1;
    lli start = 0;
    lli end = a[n-1]-a[0];

    while(start<=end)
    {
        lli mid = start+ (end-start)/2;
        bool res = findPossible(a,n,mid,c);
        //cout<<"MID : "<<mid;
        //cout<<" RES :"<<res<<endl;
        if(res)
        {
                ans = mid;
                //cout<<"ANS : "<<ans<<endl;
            start = mid+ 1;
        }
        else
            end = mid-1;
        //cout<<"start :"<<start;
        //cout<<" End : "<<end<<endl;


    }
    return ans;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        lli n,c;
        cin>>n>>c;
        lli i = 0;
        lli a[n];
        input(a,n);
        sort(a,a+n);
        lli ans = aggressiveCows(a,n,c);
        cout<<ans<<endl;
    }
    return 0;
}
