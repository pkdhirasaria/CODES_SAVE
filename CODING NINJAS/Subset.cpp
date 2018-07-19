#include <bits/stdc++.h>
#define fr(a,b) for(i=a;i<b;i++)
#define rep(a,b) for(i=a;i>=b;i--)
#define input(a,n) fr(i,n) cin>>a[i]
#define print(a,n) fr(i,n) {cout << a[i] << " ";} cout << endl
#define lli long long int
using namespace std;

int subset(int a[],int n, int output[][20])
{
    if(n==0)
    {
        output[0][0] = 0;
        return 1;
    }
    int smallout = subset(a+1,n-1,output);
    for(int i = 0;i<smallout;i++)
    {
        output[i+smallout][0] = output[i][0] +1;
        output[i+smallout][1] = a[0];
        for(int j = 0;j<output[i][0];j++)
        {
            output[i+smallout][j+2] = output[i][j+1];
        }
    }
    return 2*smallout   ;
}


int main()
{
    int t,n;
    cin>>n;
    int i = 0;
    int a[10];
    input(a,n);
    int output[20][20];
    int size = subset(a,n,output);
    for(i = 0;i<size;i++)
    {
        for(int j = 0;j<output[i][0];j++)
        {
            cout<<output[i][j+1]<<" ";
        }
        cout<<"\n";
    }
}



