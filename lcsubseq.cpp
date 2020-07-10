#include<iostream>
using namespace std;
int main()
{
	int n=0;
	cout<<"Enter size of array\n";
	cin>>n;
	int a[n],l[n],p[n],k=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		l[i]=1;
		p[i]=i;
	}
	int max=-1;
	for(int i=1;i<n;i++)
	{
		for(int j=i-1;j>=0;j--)
		{
			if(a[i]>=a[j] && l[i]<l[j]+1)
			{
				l[i]=l[j]+1;		
				p[i]=j;			
			}	
		}		
		if(max<l[i])
		{
			max=l[i];
			k=i;
		}
	}
	int x=k;	
	int t=n+1;
	while(p[x]!=x && t>=0)
	{
		cout<<a[x]<<"\t";
		x=p[x];
		t--;
	}
	cout<<a[x]<<endl;
	cout<<endl<<max<<endl;
	return 0;
}
