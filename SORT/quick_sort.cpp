#include <bits/stdc++.h>
#define fr(a,b) for(i=a;i<b;i++)
#define rep(a,b) for(i=a;i>=b;i--)
#define input(a,n) fr(i,n) cin>>a[i]
#define print(a,n) fr(i,n) {cout << a[i] << " ";} cout << endl
#define lli long long int
using namespace std;
int partition_array(int [],int , int);

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void quickSort(int a[],int l,int r)
{
    if(l<r)
    {
        int p = partition_array(a,l,r);
        quickSort(a,l,p);
        quickSort(a,p+1,r);
    }
    return;
}

int partition_array(int a[],int l, int r)
{
    int p= a[l];
    int i = l-1;
    int j = r+1;
    do{
        do{
            i++;
        }while(a[i]<p);
        do{
            j--;
        }while(a[j]>p);
        swap(&a[i],&a[j]);
    }while(i<j);
    swap(&a[i],&a[j]);
    swap(&a[l],&a[j]);
    return j;


}


int main()
{
  int a[] = {17,5,3,15,20};
  quickSort(a,0,4);
  int i =0;
  print(a,5);
}
