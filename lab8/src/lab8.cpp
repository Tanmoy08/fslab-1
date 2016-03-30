#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<fstream>
#include<sstream>
#include<sys/types.h>
#include<unistd.h>
#include<vector>
using namespace std;
class mgrsrt
{
public:
    string fname[8];
    string name[100];
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
            name[i]=buffer;
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
            name[i]=buffer;
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
            name[i]=buffer;
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
            name[i]=buffer;
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
            name[i]=buffer;
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
            name[i]=buffer;
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
            name[i]=buffer;
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
            name[i]=buffer;
            i++;
            /*fp2<<buffer;
            fp2<<endl;*/
        }
	i--;
	cout<<"value of i : "<<i<<endl ;
        fp1.close();
        cout<<"content of name :"<<endl;
        for(int j=0;j<i;j++)
        	cout<<"name["<<j<<"] : "<<name[j]<<endl;
        for(int k=0;k<i;k++)
        {
        	fp2<<name[k];
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
        m1.*/mergesort(0,i-1);
        cout<<"file sorted"<<endl;
        fp1.open("final.txt",ios::out);
        fp1.close();
       
        fp1.open("final.txt",ios::out|ios::app);
        for(int k=0;k<i;k++)
        {
            fp1<<names[k];
            fp1<<endl;
        }
        fp1.close();
    }

void merge(int l,int m,int r)
{
mgrsrt m1;
    cout<<"inside merge"<<endl;
    cout<<"content of name inside merge :"<<endl;
	cout<<"value of l & r : "<<l<<" & "<<r<<endl;
    for(int k=l;k<=r;k++)
	cout<<name[k]<<endl;
    int i=0,j=m+1,k=0,q;
    while((i<=m)&&(j<=r))
    {
    	if(name[i]<=name[j])
    	{
    		names[k++]=name[i++];
    	}
    	else
    		names[k++]=name[j++];
    	if(i>m)
    	{
    		for(q=j;q<=r;q++)
    			names[k++]=name[q];
    	}
    	else
    	{
    		for(q=i;q<=m;q++)
    		    names[k++]=name[q];
    	}
    }
	/* cout<<"content of names :"<<endl;
                for(int j=0;j<k;j++)
                	cout<<"names["<<j<<"] : "<<names[j]<<endl;*/
}
void mergesort(int l, int r)
{
    //cout<<"inside mergesort"<<endl;
   /* mgrsrt m1;*/
    if (l<r)
    {
	//cout<<"@"<<endl;
        int m = (l+r)/2;
        /*m1.*/mergesort(l, m);
	//cout<<"@1"<<endl;
        /*m1.*/mergesort(m+1, r);
	//cout<<"@2"<<endl;
        /*m1.*/merge(l,m,r);
    }  
}
};
int main()
{	
    int j;
    mgrsrt m;
    j=m.mergef();
    m.mgrsort(j);
    cout<<"file sorted"<<endl;
}
