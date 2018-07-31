#include <bits/stdc++.h>
using namespace std;
#define fr(a,b) for(i=a;i<b;i++)
#define rep(a,b) for(i=a;i>=b;i--)
#define input(a,n) fr(i,n) cin>>a[i]
#define print(a,n) fr(i,n) {cout << a[i] << " ";} cout << endl
#define lli long long int
#define ull unsigned long long

int ans[20][20];

void possiblePath(int m[][20],int n,int row,int col)
{
    if(row== (n-1) && col == (n-1))
    {
        cout<<"=============================="<<endl;
        ans[row][col] = 1;
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<n;j++)
            {
                cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return;
    }
    //if rows or column exceeds grid
    // if the current cell in m is not open i.e. it's 0
    // if we have already taken that cell in our path i.e. 1
    if(row>=n || col >= n || row <0 || col <0 || m[row][col] == 0 || ans[row][col] == 1)
    {
        return;
    }
    ans[row][col] = 1;
    possiblePath(m,n,row+1,col);
    possiblePath(m,n,row-1,col);
    possiblePath(m,n,row,col+1);
    possiblePath(m,n,row,col-1);
    ans[row][col] = 0;


}



void ratInAMaze(int m[][20],int n)
{
    possiblePath(m,n,0,0);
}


int main()
{
    int n;
    cin>>n;
    int m[20][20];
    int i,j;
    for(i = 0;i<n;i++)
    {
        for(j= 0;j<n;j++)
            cin>>m[i][j];
    }
    ratInAMaze(m,n);
    return 0;
}
