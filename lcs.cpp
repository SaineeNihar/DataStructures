#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int lcs(char a[],char b[],int m,int n)
{
	int l[m+1][n+1];
	string s="";
	for(int i=0;i<=m;i++)
	{
			for(int j=0;j<=n;j++)
			{
				if(i==0||j==0)
				l[i][j]=0;
				else if(a[i-1]==b[j-1])
				{
					l[i][j]=1+l[i-1][j-1];
					s=s+a[i-1];
				}	
				else
				l[i][j]=max(l[i-1][j],l[i][j-1]);
			}
	}
	int index=l[m][n];
	char seq[index+1];
	seq[index]='\0';
	int i=m,j=n;
	while(i>0&&j>0)
	{
		if(a[i-1]==b[j-1])
		{
			seq[index-1]=a[i-1];
			i--;j--;index--;
		}
		else if(l[i-1][j]>l[i][j-1])
			i--;			
		else 
			j--;
	}
	cout<<seq<<endl;	
		
	return l[m][n];	

}
int main()
{

	char a[]="NIharLove";
	char b[]="Iloveyou3000";
	int m=strlen(a);
	int n=strlen(b);
	cout<<lcs(a,b,m,n);


}
