#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct coin
{
	int val=0;
	int count=0;
};
int main() 
{ 
	struct coin a[3];
	a[0].val=1;
	a[1].val=4;
	a[2].val=5;
  //  int a[]= {1,4,5}; 
    int m =3; 
    cout<<"\nEnter no.";
    int n;
    cin>>n;
   
    int t[n+1];
    t[0]=0;
    for(int i=1;i<=n;i++)
    {
    	t[i]=INT_MAX;
    }
    for(int i=1;i<=n;i++)
    {
    	for(int j=0;j<m;j++)
    	{
    		if(i>=a[j].val && t[i-a[j].val]+1<t[i])
			{
				 t[i]=1+t[i-a[j].val];
			}			    	
    	}
    }
    cout<<endl<<t[n];
	cout<<"\nCoins used:\n";
	for(int i=0;i<3;i++)
	{
		cout<<a[i].val<<"\t"<<a[i].count;
		cout<<endl; 
	}   
    return 0; 
}
