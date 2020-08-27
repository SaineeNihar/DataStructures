#include<bits/stdc++.h>
using namespace std;
void bsort(vector<int> &v)
{
    int flag=0;
    for(int i=0;i<v.size()-1;i++)
    {
        for(int j=0;j<v.size()-i-1;j++)
        {   
            if(v[j]>v[j+1])
            {
                //flag=1;
                int tmp=v[j];
                v[j]=v[j+1];
                v[j+1]=tmp;
            }
        }
        if(flag==0)
            break;
        else flag=0;
    }
}
void selectionSort(vector<int>&v1)
{
    int min,tmp;
    for(int i=0;i<v1.size()-1;i++)
    {
        min=i;
        for(int j=i+1;j<v1.size();j++)
        {
            if(v1[j]<v1[min])
                min=j;
        }
        tmp=v1[min];
        v1[min]=v1[i];
        v1[i]=tmp;
    }
}
void insertionSort(vector<int> &v)
{
    for(int i=1;i<v.size();i++)
    {
        int key=v[i];
        int j=i;
        while(v[j-1]>key and j>=0)
        {
            v[j]=v[j-1];
            j--;
        }
        v[j]=key;
    }
}
void merge(vector<int>&v,int l,int mid,int h)
{
    int b[h-l+1];
    int i=l,j=mid+1;
    int k=0;
    while(i<=mid and j<=h)
        if(v[i]<=v[j])
            b[k++]=v[i++];
        else
            b[k++]=v[j++];
    while(i<=mid)
    b[k++]=v[i++];
    while(j<=h)
    b[k++]=v[j++];
    for(int i=l,k=0;i<=h;i++,k++)
        v[i]=b[k];
}
void mergeSort(vector<int> &v,int low,int high)
{
    if(low<high)
    {
        int mid=(low+high)/2;//low+((high-low)/2)
        mergeSort(v,low,mid);
        mergeSort(v,mid+1,high);
        merge(v,low,mid,high);
    }
}
int partition(vector<int> &v,int low,int high)
{
    int pivot=v[low];
    int i=low;
    for(int j=low+1;j<high;j++)
    {
        if(v[j]<=pivot)
        {
            i++;
            int tmp=v[i];
            v[i]=v[j];
            v[j]=tmp;
        }
    }
    int tmp=v[low];
    v[low]=v[i];
    v[i]=tmp;
    return i;
}
void QuickSort(vector<int> &v,int low,int high)
{
    if(low<high)
    {
        int mid=partition(v,low,high);
        QuickSort(v,low,mid-1);
        QuickSort(v,mid+1,high);
    }
}
int main()
{
    vector<int> v{10,23,3,42,6,34,67,0};
    //bsort(v); cout<<"Bubble sort: \n";
    //selectionSort(v);   cout<<"\nSelection sort \n";
    //insertionSort(v);   cout<<"InsertionSort\n";    
    //mergeSort(v,0,v.size()-1); cout<<"Merge Sort\n";
    QuickSort(v,0,v.size()-1);cout<<"Quick Sort\n";
    for(auto i:v)
        cout<<i<<" ";
    return 0;
}