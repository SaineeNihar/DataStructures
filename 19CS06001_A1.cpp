#include<iostream>
#include<fstream>
#include <cstring>
#include <sstream> 

using namespace std;
struct student_rcd
{
		string name;
		string rno;
		string dept;
};
void merge_sort(struct student_rcd[], int,int);
int partition(struct student_rcd[], int,int);
void qs(struct student_rcd[],int,int);
int lbs(struct student_rcd[], int, int,string);
int rbs(struct student_rcd[], int, int,string);
int main()
{
	int std_no=0;
	ifstream f;
	string s;
	student_rcd r[100];
	//File Reading 
	f.open("rcd.txt",ios::in);
	while(getline(f,s))
	{		 
		stringstream sp(s);
		getline(sp,r[std_no].name,',');
		getline(sp,r[std_no].rno,',');
		getline(sp,r[std_no].dept,'\n');
		++std_no;		
	}
	f.close();
	//Reading Data from Student record Structure
	cout<<"Before Sorting"<<endl;
	for(int b=0;b<std_no;b++)
	{
	cout<<r[b].name<<"\t";
	cout<<r[b].rno<<"\t";
	cout<<r[b].dept<<endl;
	}
	cout<<"No of students are "<<std_no<<endl;
	cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
	cout<<"(1) Merge Sort\n(2) Quick Sort\n(3) Binary Search\n(4) Quit.\n";
	int input;
	cin>>input;
	if(input==1)//Merge 
	{
		merge_sort(r,0,std_no-1);	
	}	
	else if(input==2)//Quick Sort
	{ 
		qs(r,0,std_no-1);
	}
	else if(input==3)//Binary Search
	{ 
		merge_sort(r,0,std_no-1);
		char bn[30];		
		cout<<"Enter Name of the student";
		scanf(" %[^\n]",bn);	
		string bname=bn;
		int p=lbs(r,0,std_no-1,bname);
		int q=rbs(r,0,std_no-1,bname);
		if(p==-1 && q==-1)
		{
			cout<<"No Record found!!!";
			return 0;		
		}		
		cout<<"No of students are "<<q-p+1<<endl;
		for(int x=p,f=1;x<=q;x++,f++)
		{
			cout<<f<<" "<<r[x].name<<"\t";
			cout<<r[x].rno<<"\t";
			cout<<r[x].dept<<endl;
			cout<<"------------------------------------"<<endl;
		}
		return 0;		
	}
	else if(input==4)//Quit
	{
		return 0;
	}
	else
	{
		cout<<"Wrong input\n"; 
		return 0;
	}
	//Reading Data from Student record Structure
	cout<<"..............After Sorting............\n";
	for(int x=0;x<std_no;x++)
	{
		cout<<x+1<<" "<<r[x].name<<"\t";
		cout<<r[x].rno<<"\t";
		cout<<r[x].dept<<endl;
	}
	cout<<"No of students are "<<std_no<<endl;
return 0;
}
/////////////////////Merge Sort Code/////////////////////////////////////////////////
void merging(struct student_rcd r[],int low, int mid, int high)
	{
		int i=low,j=mid+1,k=0;
		student_rcd b[high-low+1];

		while(i<=mid && j<=high)
		{
			int nf= strcmp((r[i].name).c_str(),(r[j].name).c_str());
			//if 2 names are Same//
			if(nf==0)
			{
				int rf= strcmp((r[i].rno).c_str(),(r[j].rno).c_str());
					if(rf<0) { b[k++]=r[i++]; }
					else { b[k++]=r[j++]; }
							
			}
			//Distinct Names// 
			else if(nf<0) { b[k++]=r[i++]; }
			else { b[k++]=r[j++]; } 
		}
		//storing extra elements left, into the array//
		while(i<=mid){ b[k++]=r[i++]; }
		while(j<=high){ b[k++]=r[j++]; }
		//copying back into original array//
		for(i=low,k=0;i<=high;i++,k++){ r[i]=b[k];}
	}	
// Merge sorting// 
void merge_sort(struct student_rcd r[], int low,int high)
{
	if (low<high)
	{
		int mid =(low+high)/2;		
		merge_sort(r,low,mid);
		merge_sort(r,mid+1,high);		
		merging(r,low,mid,high);
	}
}	
//////////////////////////++++++++++++++++////////////////////////////////////////////
//////////////////////////Quick Sort Code/////////////////////////////////////////////
int partition(struct student_rcd r[],int low, int high)
{
	string nm=r[low].name,rn=r[low].rno;
	int i=low;
	for(int j=low+1;j<=high;j++)
	{
		int nm_flag= strcmp((r[j].name).c_str(),nm.c_str());
		if(nm_flag==0)
		{
			int rn_flag= strcmp((r[j].rno).c_str(),rn.c_str());
			if(rn_flag<=0)
			{
				i=i+1;
				struct student_rcd buf=r[i];
				r[i]=r[j];
				r[j]=buf;
			}
		}		
		else if(nm_flag<0)
		{
			i=i+1;
			struct student_rcd buf=r[i];
			r[i]=r[j];
			r[j]=buf;
		}	
	} 
	struct student_rcd bu=r[low];
	r[low]=r[i];
	r[i]=bu;
	return i;
}
void qs(struct student_rcd r[],int p,int q)
{
	if(p<q)
	{ 
		int m=partition(r,p,q);
		qs(r,p,m-1);
		qs(r,m+1,q);
	}
}
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////Binary Search///////////////////////////////////////////
int lbs(struct student_rcd r[], int i,int j,string x)
{
	int mid;
	while(i<=j)
		{
			mid=(i+j)/2;
			if (r[mid].name==x && mid==i){return mid;}
			if(r[mid-1].name<r[mid].name && r[mid].name==x){return mid;}
			if(r[mid].name<x){i=mid+1;}
			else{j=mid-1;}
		}
	return -1;		
}
int rbs(struct student_rcd r[], int i, int j,string x)
{
	
	int mid;
	while(i<=j)
		{
			mid=(i+j)/2;
			if (r[mid].name==x && mid==j){return mid;}
			if(r[mid].name<r[mid+1].name && r[mid].name==x){return mid;}
			if(r[mid].name<=x){i=mid+1;}
			else{j=mid-1;}
		}
	return -1;
}

























