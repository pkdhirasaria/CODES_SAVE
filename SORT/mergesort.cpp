
void merge(int a[],int l,int r, int mid)
{
   // cout<<"==================================="<<endl;
    //cout<<"MID : "<<mid<<" L : "<<l<<" R : "<<r<<endl;
    int n1 = mid - l+1;
    int n2 = r-mid;
    int b[n1],c[n2];
    //cout<<"N1 : "<<n1<<" N2 : "<<n2<<endl;
    for(int i = 0;i<n1;i++)
        b[i] = a[l+i];
    //cout<<"B : ";
   // int i =0;
    //print(b,n1);
    //cout<< "C : ";
    for(int i = 0;i<n2;i++)
        c[i] = a[i+mid+1];
    //i = 0;
    //print(c,n2);
    int j=0;
    int k=0;
    int i = l;
    while(j<n1 && k<n2)
    {
        if(b[j]<=c[k])
        {
            a[i] = b[j];
            j++;
        }
        else
        {
            a[i] = c[k];
            k++;
        }
        i++;
    }


    while(j<n1)
    {
        a[i] = b[j];
        j++;
        i++;
    }
    while(k<n2)
    {
        a[i]=c[k];
        k++;
        i++;
    }
}



//calling from main as mergeSort(a,0,size-1);
void mergeSort(int a[],int l,int r)
{
    if(l<r)
    {
        int mid = (l+r)/2;
        mergeSort(a,mid+1,r);
        mergeSort(a,l,mid);
        merge(a,l,r,mid);
    }
}
