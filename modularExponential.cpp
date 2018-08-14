#include <bits/stdc++.h>
#define fr(a,b) for(i=a;i<b;i++)
#define rep(a,b) for(i=a;i>=b;i--)
#define f first
#define s second
#define input(a,n) fr(i,n) cin>>a[i]
#define print(a,n) fr(i,n) {cout << a[i] << " ";} cout << endl
#define lli long long
#define ull unsigned long long
using namespace std;


//Recursive Solution 
int modularExpRecursive(int a,int b,int c)
{
    if(b == 0)
        return 1;

    if(b%2 == 0)
    {
        return modularExpRecursive((a*a)%c,b/2,c);
    }
    else
    {
        return ((a%c)* modularExpRecursive((a*a)%c,(b-1)/2,c))%c;
    }
}


//Iterative Solution
int modularExpIterations(int a,int b ,int c)
{
    int res = 1;
    while(b>0)
    {
        //if rightmost digit is one b is even
        if(b&1 == 1)
        {
            res = ((res*a)%c);
        }
        a = (a*a)%c;
        b = b/2;
    }
    return res;
}


int main()
{
    cout<<modularExpRecursive(10,5,7)<<endl;
    cout<<modularExpIterations(10,5,7);
	return 0;
}
