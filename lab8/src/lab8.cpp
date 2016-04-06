#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<fstream>
#include<sstream>
#include<sys/types.h>
#include<unistd.h>
#include<vector>
using namespace std;
#define max 50
class mgrsrt
{
public:
    string fname[8];
    string a[100];
    string names[100];
    int i;

    int mergef()
    {
    	int i=0;
        string buffer;
        fstream fp1,fp2;
        fp2.open("final.txt",ios::out|ios::app);
        fp1.open("1.txt",ios::in);
        while(!fp1.eof())
        {
            getline(fp1,buffer);
            a[i]=buffer;
            i++;
            /*fp2<<buffer;
            fp2<<endl;*/
        }
	i--;
        fp1.close();
        fp1.open("2.txt",ios::in);
        while(!fp1.eof())
        {
	    //int pos=fp2.tellp();
	  // fp2.seekp(pos-2,ios::beg);
            getline(fp1,buffer);
            a[i]=buffer;
            i++;
            /*fp2<<buffer;
            fp2<<endl;*/
        }
	i--;
        fp1.close();
        fp1.open("3.txt",ios::in);
        while(!fp1.eof())
        {
		//int pos=fp2.tellp();
	   // fp2.seekp(pos-2,ios::beg);
            getline(fp1,buffer);
            a[i]=buffer;
            i++;
            /*fp2<<buffer;
            fp2<<endl;*/
        }
	i--;
        fp1.close();
        fp1.open("4.txt",ios::in);
        while(!fp1.eof())
        {
		//int pos=fp2.tellp();
	  // fp2.seekp(pos-2,ios::beg);
            getline(fp1,buffer);
            a[i]=buffer;
            i++;
            /*fp2<<buffer;
            fp2<<endl;*/
        }
	i--;
        fp1.close();
        fp1.open("5.txt",ios::in);
        while(!fp1.eof())
        {
		//int pos=fp2.tellp();
	 // fp2.seekp(pos-2,ios::beg);
            getline(fp1,buffer);
            a[i]=buffer;
            i++;
           /* fp2<<buffer;
            fp2<<endl;*/
        }
	i--;
        fp1.close();
        fp1.open("6.txt",ios::in);
        while(!fp1.eof())
        {
	//	int pos=fp2.tellp();
	  // fp2.seekp(pos-2,ios::beg);
            getline(fp1,buffer);
            a[i]=buffer;
            i++;
           /* fp2<<buffer;
            fp2<<endl;*/
        }
	i--;
        fp1.close();
        fp1.open("7.txt",ios::in);
        while(!fp1.eof())
        {
	//	int pos=fp2.tellp();
	  //  fp2.seekp(pos-2,ios::beg);
            getline(fp1,buffer);
            a[i]=buffer;
            i++;
           /* fp2<<buffer;
            fp2<<endl;*/
        }
	i--;
        fp1.close();
        fp1.open("8.txt",ios::in);
        while(!fp1.eof())
        {
	//	int pos=fp2.tellp();
	 // fp2.seekp(pos-2,ios::beg);
            getline(fp1,buffer);
            a[i]=buffer;
            i++;
            /*fp2<<buffer;
            fp2<<endl;*/
        }
	i--;
	cout<<"value of i : "<<i<<endl ;
        fp1.close();
        cout<<"content of name :"<<endl;
        for(int j=0;j<i;j++)
        	cout<<"a["<<j<<"] : "<<a[j]<<endl;
        for(int k=0;k<i;k++)
        {
        	fp2<<a[k];
        	fp2<<endl;
        }
        fp2.close();
	return i;
    }
    void mgrsort(int j)
    {

        cout<<"inside mgrsort"<<endl;
	i=j;
       cout<<"value of i : "<<i<<endl;
        string buffer;
        //int rsize=0;
        fstream fp1;
        /*fp1.open("final.txt",ios::in);
        cout<<"opened file"<<endl;
        while(!fp1.eof())
        {
            getline(fp1,buffer);
           // name.push_back(buffer);
            name[i]=buffer;
            i++;
        }
        fp1.close();
        for(int k=0;k<i-1;k++)
            cout<<"k["<<k<<"]"<<" : "<<name[k]<<endl;
        int mid=(1+i)/2;*/
        /*mgrsrt m1;
        m1.*/mergesort(a,0,i-1);
        cout<<"file sorted"<<endl;
        fp1.open("final.txt",ios::out);
        fp1.close();
       cout<<"file cleared"<<endl;
        fp1.open("final.txt",ios::out|ios::app);
        for(int k=0;k<i;k++)
        {
            fp1<<a[k];
            fp1<<endl;
        }
        fp1.close();
    }

void merge(string c[max],string d[max],int l,int m,int r)
{
	
	int i,j,q,k;
	i=l;
	j=m+1;
	k=l;
	while((i<=m)&&(j<=r))
	if(c[i]<=c[j])
	d[k++]=c[i++];
	else
	d[k++]=c[j++];
	if(i>m)			
	for(q=j;q<=r;q++)
	d[k++]=c[q];			
	else			
	for(q=i;q<=m;q++)
	d[k++]=c[q];
	
}
void mergesort(string a[],int l, int r)
{
	cout<<"content after mergesort is :"<<endl;
	for(i=l;i<=r;i++)
		cout<<"a["<<i<<"] : "<<a[i]<<endl;
   	int m,i;
   	string b[max];
	if(l<r)
	{
		m=(l+r)/2;
		mergesort(a,l,m);
		mergesort(a,m+1,r);	
		merge(a,b,l,m,r);
		for(i=l;i<=r;i++)
			{a[i]=b[i];}
	}
	/*cout<<"content after mergesort is :"<<endl;
	for(i=l;i<=r;i++)
		cout<<"a["<<i<<"] : "<<a[i]<<endl;*/
}
};
int main()
{	
    int j;
    mgrsrt m;
    j=m.mergef();
    m.mgrsort(j);
}
