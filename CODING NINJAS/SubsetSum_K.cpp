#include <bits/stdc++.h>
#define fr(a,b) for(i=a;i<b;i++)
#define rep(a,b) for(i=a;i>=b;i--)
#define input(a,n) fr(i,n) cin>>a[i]
#define print(a,n) fr(i,n) {cout << a[i] << " ";} cout << endl
#define lli long long int
using namespace std;

void subsetutility(int a[],int n,int currSum,int k, int i,int output[])
{
    if(k == currSum)
    {
        for(int j= 0;j<i;j++)
        {
            if(output[j]==1)
            cout<<a[j]<<" ";
        }
        cout<<endl;
    }
    else if(n == 0)
        return;
    else{
    output[i] = 1;
    currSum += a[i];
    subsetutility(a,n-1,currSum,k,i+1,output);
    output[i] = 0;
    currSum -=a[i];
    subsetutility(a,n-1,currSum,k,i+1,output);}
    return;
}



int subset(int a[],int n)
{
    int output[20];
    subsetutility(a,n,0,6,0,output);
    return 1;
}


int main()
{
    int t,n;
    cin>>n;
    int i = 0;
    int a[10];
    input(a,n);
    int size = subset(a,n);
}




