#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<fstream>
#include<sstream>
#include<sys/types.h>
#include<unistd.h>
using namespace std;
#define max 2
class seqo{
	string l1[max];
	string l2[max];
	string l3[max];
	int c1,c2;
public:
	void load();
	void sort();
	void match();
};
void seqo :: load()
{c1=0;c2=0;
	int i=0;
	fstream fp1,fp2;
	char flname2[10],flname1[10];
	string buffer;
	cout<<"enter the first filename : "<<endl;
	cin>>flname1;
	cout<<endl;
	cout<<"enter the second filename : "<<endl;
	cin>>flname2;
	fp1.open(flname1,ios::in);
	fp2.open(flname2,ios::in);
	while(!fp1.eof())
	{
		buffer.erase();
		getline(fp1,buffer);
		l1[i]=buffer;
		i++;
		c1++;
	}

	i=0;
	cout<<"after load l1 is : "<<endl;
	for(int i=0;i<c1;i++)
				cout<<l1[i]<<endl;
	while(!fp2.eof())
		{
		buffer.erase();
			getline(fp2,buffer);
			l2[i]=buffer;
			i++;
			c2++;
		}

	cout<<"after load l2 is : "<<endl;
		for(int i=0;i<c2;i++)
					cout<<l2[i]<<endl;
	fp1.close();
	fp2.close();
	return;
}
void seqo ::  sort()
{
	string temp;
	for(int i=0;i<c1;i++)
				{
					for(int j=i+1;j<c1;j++)
					{
						if(l1[i]>l1[j])
						{
							temp=l1[i];
							l1[i]=l1[j];
							l1[j]=temp;
						}
					}
				}
	cout<<c1<<endl<<c2<<endl;
cout<<"l1:"<<endl;
		for(int i=0;i<c1;i++)
			cout<<l1[i]<<endl;
				for(int i=0;i<c2;i++)
				{
					for(int j=i+1;j<c2;j++)
					{
						if(l2[i]>l2[j])
						{
							temp=l2[i];
							l2[i]=l2[j];
							l2[j]=temp;
						}
					}
				}
				cout<<"l2:"<<endl;
			for(int i=0;i<=c2;i++)
			cout<<l2[i]<<endl;
}
void seqo :: match()
{
	cout<<"matching records are:"<<endl;
	int i=0,j=0;
	for(i=0;i<c1;i++)
	{
		for(j=0;j<c2;j++)
		{
			if(l1[i]==l2[j])
				cout<<l1[i]<<endl;
		}
	}
}
int main()
{
	seqo s;
	s.load();
	//cout<<"after load"<<endl;
	s.sort();
	//cout<<"after sort"<<endl;
	s.match();
}
