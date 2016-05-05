#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<fstream>
#include<sstream>
#include<sys/types.h>
#include<unistd.h>
#include<vector>
#define max 100
using namespace std;
string index1[max][2];
void sort(int l)
{
	string temp,tempu;
	int usn1=0,usn2=0;
	cout<<l<<endl;
	for(int i=0;i<l;i++)
	{
		for(int j=i+1;j<l;j++)
		{

		usn1=atoi(index1[i][0].c_str());
		usn2=atoi(index1[j][0].c_str());
		cout<<usn1<<"|||||"<<usn2<<endl;
		if(usn1>usn2)
		{
			temp=index1[i][0];
			tempu=index1[i][1];

			index1[i][0]=index1[j][0];
			index1[i][1]=index1[j][1];

			index1[j][0]=temp;
		    index1[j][1]=tempu;
		}
	}
	}
	for(int i=0;i<l;i++)
	{
		cout<<index1[i][0];
		cout<<endl;
	}
	}
int load()
{
	fstream fp;
	int l=0;
	string usn,pos;
	int i=0;
	fp.open("inde.txt",ios::in);
	string buffer;
	getline(fp,buffer);
	if(buffer=="\n")
		return 0;
	else
		fp.seekp(0,ios::beg);
	while(!fp.eof())
	{
		usn.erase();
		pos.erase();
		getline(fp,buffer);
		 while(buffer[i]!='|')
		 {
		    usn+=buffer[i];
		    i++;
		 }
		 i++;
		 while(buffer[i]!='$')
		    {
		    	pos+=buffer[i];
		    	i++;
		    }
		 index1[l][0]=usn;
		 index1[l][1]=pos;
		 l++;
		 i=0;
	}
	for(i=0;i<l;i++)
	{
		cout<<index1[i][0];
		cout<<endl;
	}
	fp.close();
	return l-1;
}
class student{
    string name;
    string usn;
    string branch;
    int sem;
    string buffer;
public:
    string read();
    string pack();
    void unpack(int pos1);
};
string student::read()
{
    cin.clear();
    cin.ignore(255,'\n');
    cout<<"enter the name :"<<endl;
    getline(cin,name);
    cout<<"enter the usn :"<<endl;
    cin>>usn;
    cin.clear();
    cin.ignore(255,'\n');
    cout<<"enter the branch :"<<endl;
    getline(cin,branch);
    cout<<"enter the semester :"<<endl;
    cin>>sem;
    cin.clear();
    cin.ignore(255,'\n');
    cout<<endl;
    return usn;
}
string student::pack()
{
    string sem1;
    string temp;
    stringstream out;
    out<<sem;
    sem1=out.str();
    int i;
    temp=usn+'|'+name+'|'+branch+'|'+sem1;
    for(i=temp.size();i<100;i++)
    {
    	temp+='$';
    }
    cout<<temp<<endl;
    buffer=temp;
    return buffer;
}
void student::unpack(int pos1)
{
    fstream fp1;
    string buffer;
    fp1.open("data.txt",ios::in);
    fp1.seekp(pos1,ios::beg);
    getline(fp1,buffer);
    string s;
    int i=0;
    cout<<endl<<endl;
    usn.erase();
    while(buffer[i]!='|')
    {
    	usn+=buffer[i];
    	i++;
    }
    i++;
    name.erase();
    while(buffer[i]!='|')
    {
    	name+=buffer[i];
    	i++;
    }
    i++;
    branch.erase();
    while(buffer[i]!='|')
    {
    	branch+=buffer[i];
    	i++;
    }
    i++;
    sem=0;
    while(buffer[i]!='$')
    {
    	s=buffer[i];
    	i++;
    }
    stringstream convert(s);
    convert>>sem;
    cout<<"usn is : "<<usn<<endl;
    cout<<"name is : "<<name<<endl;
    cout<<"branch is : "<<branch<<endl;
    cout<<"sem is : "<<sem<<endl;
}
class file{
public:
    int write(string buf);
};
int file :: write(string buf)
{
	int pos=0;
    fstream fp1;
    fp1.open("data.txt",ios::out|ios::app);
    pos=fp1.tellp();
    fp1<<buf;
    fp1<<endl;
    fp1.close();
    return pos;
}
class indf{
public:
    void insert(int l);
    int search(string key);
    void rem(string key,int pos);
};
void indf::insert(int l)
{
    fstream fp1;
    fp1.open("inde.txt",ios::out);
    fp1.close();
    fp1.open("inde.txt",ios::out|ios::app);
    int i;
    string temp;
    for(i=0;i<l;i++)
    {
    	 temp=index1[i][0]+'|'+index1[i][1];
    	 for(int j=temp.size();j<50;j++)
    	 {
    	     temp+='$';
    	 }
    	 fp1<<temp;
    	 fp1<<endl;
    }
    fp1.close();
}
int indf::search(string key)
{
    fstream fp1;
    string buffer,sub,unkey,unpos,s;
    int i=0,j=0,pos=0;
    fp1.open("inde.txt",ios::in);
    while(!fp1.eof())
    {
    	buffer.erase();
    	j=0;
    	getline(fp1,buffer);
        while(buffer[j]!='|')
        	{
        	sub+=buffer[j];
        	j++;
        	}
        if(key==sub)
        {
            while(buffer[i]!='|')
            {
            		unkey+=buffer[i];
            		i++;
            }
            i++;
            while(buffer[i]!='$')
            {
            		unpos+=buffer[i];
            		i++;
            }
            s=unpos;
            stringstream convert(s);
            convert>>pos;
            cout<<"position in file : "<<pos<<endl;
            fp1.close();
            return pos;
        }
        else
        {
            sub.erase();
            unkey.erase();
            unpos.erase();
        }
    }
    cout<<"record not found"<<endl;
    fp1.close();
    return -1;
}

void indf::rem(string key,int pos)
{
   string buffer,usn1,i1;
   indf f;
   int i=pos;
   int j=0,l1=0,l=0,siz1=0,loc1=0,pos1=0;
   cout<<"value of pos in rem function : "<<i<<endl;
   fstream fp1,fp2,fp3;
   fp1.open("data.txt",ios::in);
   fp2.open("tempdata.txt",ios::out);
   fp2.close();
   fp2.open("tempdata.txt",ios::out|ios::app);
   l=0;
   while(!fp1.eof())
   {
	   j=fp1.tellp();
   getline(fp1,buffer);
   l++;
   if(j==i)
   {
       continue;
   }
   else
   {
       fp2<<buffer;
       fp2<<endl;
   }
   }
   l=l-2;
   fp1.close();
   fp2.close();
   fp1.open("data.txt",ios::out);
   fp1.close();
   fp1.open("data.txt",ios::out|ios::app);
   fp2.open("tempdata.txt",ios::in);
   fp3.open("inde.txt",ios::out);
   fp3.close();
   while(!fp2.eof())
   {
       i=0;
       if(l==0)
           break;
       pos1=fp1.tellp();
       getline(fp2,buffer);
       fp1<<buffer;
       fp1<<endl;
       l--;
       usn1.clear();
       while(buffer[i]!='|')
       {
    	   	  usn1+=buffer[i];
    	   	  i++;
       }

       index1[l1][0]=usn1;

       stringstream out;
                  out<<pos1;
                  i1=out.str();
                  index1[l1][1]=i1;
                  l1++;
                  sort(l1);
                  f.insert(l1);

       }
   fp1.close();
   fp2.close();
}


int main()
{

    int choice,i,k,l=0,m=0;
    string buffer,key,i1;
    student s;
    file f;
    indf ind;
    fstream fp1;
    fp1.open("inde.txt",ios::in);
	l=load();
	if(l==-1)
		l=0;
    cout<<"l :"<<l<<endl;
    while(1)
    {
    cout<<"1) add\n2) search\n3)delete\n------------\nEnter your choice : ";
    cin>>choice;
    cout<<endl;

    switch(choice)
    {
        case 1:
        {
           key=s.read();
           buffer=s.pack();
           i=f.write(buffer);
           index1[l][0]=key;
           stringstream out;
           out<<i;
           i1=out.str();
           index1[l][1]=i1;
           l++;
           sort(l);
           ind.insert(l);
        }
        break;
        case 2:
        {
            cout<<"enter the usn to be searched :";
            cin>>key;
            k=ind.search(key);
            s.unpack(k);
        }
        break;
        case 3:
        {
            cout<<"enter the usn to be removed : ";
            cin>>key;
            cout<<endl;
            k=ind.search(key);
            if(k==-1)
                exit(0);
            ind.rem(key,k);
        }
        break;
        default : cout<<"invalid option"<<endl;
    }
    cout<<"enter 0 to exit else 1 to continue : ";
    cin>>choice;
    if(choice == 0)
        exit(0);
    else
        continue;
    }
}
