#include <bits/stdc++.h>
using namespace std;
#define fr(a,b) for(i=a;i<b;i++)
#define rep(a,b) for(i=a;i>=b;i--)
#define input(a,n) fr(i,n) cin>>a[i]
#define print(a,n) fr(i,n) {cout << a[i] << " ";} cout << endl
#define lli long long int
#define ull unsigned long long

int m[11][11];

bool place(int row,int col,int n)
{
    //check above

    for(int i = row;i>=0;i--)
    {
        if(m[i][col]==1)
            return false;
    }

    //check left diagonal

    for(int i =row, j = col;i>=0,j>=0;i--,j--)
    {
        if(m[i][j]==1)
            return false;
    }

    //check right diagonal

    for(int i= row, j = col;i>=0,j<n;i--,j++)
    {
        if(m[i][j]==1)
        {
            return false;
        }
    }
    //this will return whether we can place
    //queen at that block or not
    return true;
}



void nQueen(int n,int row)
{
    if(row>=n)
    {
        cout<<"==========================="<<endl;
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<n;j++)
            {
                cout<<m[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<"==========================="<<endl;
    }
    for(int i = 0;i<n;i++)
    {
        if(place(row,i,n))
        {
            m[row][i] = 1;
            nQueen(n,row+1);
            m[row][i]=0;
        }
    }
}



int main()
{
    int n;
    cin>>n;
    nQueen(n,0);
    return 0;
}
