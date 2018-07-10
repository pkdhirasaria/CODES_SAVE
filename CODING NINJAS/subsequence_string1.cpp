#include <bits/stdc++.h>
#define fr(a,b) for(i=a;i<b;i++)
#define rep(a,b) for(i=a;i>=b;i--)
#define input(a,n) fr(i,n) cin>>a[i]
#define print(a,n) fr(i,n) {cout << a[i] << " ";} cout << endl
#define lli long long int
using namespace std;

int subsequence(string s, string out[])
{
    if(s.empty())
    {
        out[0] = "";
        return 1;
    }
    int small = subsequence(s.substr(1),out);
    for(int i = 0;i<small;i ++)
    {
        out[i+small] = s[0] + out[i];
    }
    return 2*small;
}
int main()
{
    string s= "abc";
    string output[1000];
    int len = subsequence(s,output);
    int i =0;
    print(output,len);
}
