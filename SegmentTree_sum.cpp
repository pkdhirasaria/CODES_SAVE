#include <bits/stdc++.h>
using namespace std;
#define fr(a,b) for(i=a;i<b;i++)
#define rep(a,b) for(i=a;i>=b;i--)
#define input(a,n) fr(i,n) cin>>a[i]
#define print(a,n) fr(i,n) {cout << a[i] << " ";} cout << endl
#define lli long long int
#define setValue(a,val,n) fr(i,n) a[i] = val;
#define pb push_back
#define mp make_pair

#define vii vector<int,int>
#define qi queue<int>
#define mii map<int,int>
#define mll map<lli,lli>

void buildTree(int* a,int* tree,int start,int endi, int treeNode)
{
    if(start == endi)
    {
        tree[treeNode] = a[start];
        return;
    }
    int mid = (start + endi)/2;
    buildTree(a,tree,start,mid,2*treeNode);
    buildTree(a,tree,mid+1,endi,2*treeNode+1);

    tree[treeNode] = tree[2*treeNode] + tree[2*treeNode+1];
}

void updateTree(int* a,int* tree,int start,int endi,int treeNode,int idx,int value)
{
    if(start == endi)
    {
        a[start] = value;
        tree[treeNode] = value;
        return;
    }
    int mid = (start + endi)/2;
    if(idx > mid)
    {
        updateTree(a,tree,mid+1,endi,treeNode*2 + 1,idx,value);
    }
    else
    {
        updateTree(a,tree,start,mid,treeNode*2,idx,value);
    }

    tree[treeNode] = tree[2*treeNode] + tree[2*treeNode+1];
}

int query(int* tree,int start,int endi,int treeNode,int left,int right)
{
    //completely outside
    if(start > right || endi < left)
    {
        return 0;
    }
    // completely inside

    if(start >=left && endi <= right)
    {
        return tree[treeNode];
    }
    int mid = (start+endi)/2;
    int ans1 = query(tree,start,mid,2*treeNode,left,right);
    int ans2 = query(tree,mid+1,endi,2*treeNode+1,left,right);
    return ans1 +ans2;
}

int main()
{
    int a[] ={1,2,3,4,5,6,7,8,9};
    int *tree = new int[18];
    buildTree(a,tree,0,8,1);
    int  i =1;
    print(tree,18);

    updateTree(a,tree,0,8,1,2,10);
    i = 1;
    print(tree,18);
    cout<<endl;
    cout<<query(tree,0,8,1,2,9);
}
