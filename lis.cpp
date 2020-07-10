#include<iostream>
using namespace std;
int lis(int arr[],int n)
{
	int len[n];
	len[0]=1;
	int max=-1;
	for(int i=1;i<n;i++)
	{
		len[i]=1;
		for(int j=0;j<i;j++)
		{
			if(arr[i]>arr[j] && len[i]<len[j]+1)
			{
				len[i]=len[j]+1;
			}	
		}	
		if(max<len[i])
		max=len[i];
	}
	return max;
}


int main()
{
	int arr[]={100,34,42,32,5,67,11,96};
	int size=sizeof(arr)/sizeof(arr[0]);
	cout<<lis(arr,size);
return 0;
}
