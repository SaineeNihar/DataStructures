#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void countSort(int t[],int n,int k)
{
    int c[k+1],i;
    int b[n];
    for(i=0;i<=k;i++)
        c[i]=0;
 
    for(i=0;i<n;i++)
        c[t[i]]+=1;

    for(i=1;i<=k;i++)
        c[i]+=c[i-1];

    for(i=n-1;i>=0;i--)
    {    
        b[c[t[i]]-1]=t[i];
        c[t[i]]-=1;
    }
    
    for(i=0;i<n;i++)
    {
        t[i]=b[i];
    }
}
void countSortRedix(int a[],int n,int exp)
{
    int count[10];
    int output[n];
    memset(count,0,10*sizeof(int));
    for(int i=0;i<n;i++)
        count[(a[i]/exp)%10]++;

    for(int i=1;i<10;i++)
        count[i]+=count[i-1];
    for(int i=n-1;i>=0;i--)
    {
        output[count[(a[i]/exp)%10]-1]=a[i];
        count[(a[i]/exp)%10]--;
    }
    for(int i=0;i<n;i++)
        a[i]=output[i];
}
int getMax(int a[],int n)
{
    int max=a[0];
    for(int i=0;i<n;i++)
        if(max<a[i])
            max=a[i];
    return max;
}
void redixSort(int a[],int n)
{
    int m=getMax(a,n);
    cout<<m<<endl;
    for(int exp=1;m/exp>0;exp *=10)
        countSortRedix(a,n,exp);
}
int main()
{
    cout<<"Count Sort"<<endl;       
    int n=10;
    int t[]={1670,4785,3464,1452,3415,4813,3766,4164,1386,1386};
    //redixSort(t,n);
    redixSort(t,n);
    for(int i=0;i<n;i++)
        cout<<t[i]<<" ";
    cout<<"\n";
    return 0;
}
