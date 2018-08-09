int * findpower(string s, string n)
{
    int *res = new int[1000];
    for(int x=0;x<1000;x++)
        res[x] = 0;
    cout<<s<<" "<<n<<endl;
    int i ;
    int j ;
    int k = 0;
    int res_size = 1;
    for(i =n.length()-1;i>=0;i--)
    {
        k = res_size;
        int carry = 0;
        for(j = s.length()-1;j>=0;j--)
        {
            int prod = (s[j]-'0')*(n[i]-'0') + carry;
            int sum =  res[k] + prod %10;
            res[k] = sum%10;
            k++;
            carry = prod/10 + sum/10;
        }
        while(carry >0)
        {
            res[k++] = carry%10;
            carry = carry/10;
        }
        res_size++;
    }
    res[0] = k;
    return res;

}

int * getSum(string a,string b,long long n)
{
    int *p1 = findpower(a,n);
    int *p2 = findpower(b,n);
    int n1 =p1[0],n2=p2[0];
    int carry = 0;
    int *sum= new int[1000];
    for(int x= 0;x<1000;x++)
        sum[x] = 0;
    int i = 1;
    for(;i<min(n1,n2);i++)
    {
        int addition = p1[i] + p2[i] + carry;
        sum[i] = addition%10;
        carry = addition/10;
    }
    while(i<n2)
    {
        int addition = p2[i] + carry;
        sum[i++] = addition%10;
        carry = addition/10;
    }
    while(i<n1)
    {
        int addition = p1[i] + carry;
        sum[i++] = addition%10;
        carry = addition/10;
    }
    while(carry>0)
    {
        sum[i++] = carry%10;
        carry = carry/10;
    }
    sum[0] = i;
    return sum;

}

