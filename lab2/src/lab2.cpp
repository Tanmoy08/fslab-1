

//============================================================================
// Name        : pg2f.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<string.h>
#include<fstream>
#include<sstream>
#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#define max 100
using namespace std;
class Student {
	string name;
	string usn;
	string branch;
	int sem;
	string buffer;
public :
	void read()
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
	}
	void show()
	{
		cout<<"Name is :"<<name<<endl;
		cout<<"usn is :"<<usn<<endl;
		cout<<"branch is :"<<branch<<endl;
		cout<<"semester is :"<<sem<<endl<<endl;
	}
	void pack()
	{
		string sem1;
		string temp;
		stringstream out;
		out<<sem;
		sem1=out.str();
		int i;
		temp=usn+'|'+name+'|'+branch+'|'+sem1;
		for(i=temp.size()+1;i<100;i++)
		{
			temp+='$';
		}
		cout<<temp<<endl;
		buffer=temp;
	}
	void write()
	{
		fstream fp1;
		char flname[max];
		cout<<"enter the file name to write the read record"<<endl;
		cin>>flname;
		fp1.open(flname,ios::out|ios::app);
		fp1<<buffer;
		fp1<<endl;
		fp1.close();
	}
	void search(string usn)
	{
		fstream fp1;
		int i;
		fp1.open("data.txt",ios::in);
		getline(fp1,buffer);
		cout<<"record read"<<endl;
		cout<<buffer<<endl;
		int pos=fp1.tellp();
		cout<<"position in file"<<pos<<endl;
		unpack();
	}
	void unpack()
	{
		string s;

			int i=0;
			cout<<endl<<endl;
			while(buffer[i]!='|')
			{
				usn+=buffer[i];
				i++;
			}
			i++;
			while(buffer[i]!='|')
			{
				name+=buffer[i];
				i++;
			}
			i++;
			while(buffer[i]!='|')
			{
				branch+=buffer[i];
				i++;
			}
			i++;
			while(buffer[i]!='$')
			{
				s=buffer[i];
				stringstream convert(s);
				convert>>sem;
				i++;
			}
			cout<<"usn is :"<<usn<<endl;
			cout<<"name is :"<<name<<endl;
			cout<<"branch is :"<<branch<<endl;
			cout<<"sem is :"<<sem<<endl;
	}
	void modify()
	{
	}
};

int main() {
	int choice;
	Student s1;
	while(1)
	{
		cout<<"enter your choice :\n1> insert\n2>search\n3>delete\n4>modify\n5>exit\n----"<<endl;
		cin>>choice;
		switch(choice)
		{
		case 1:
			{
				while(1)
				{
				s1.read();
				cout<<endl<<"data recorded"<<endl;
				s1.show();
				s1.pack();
				s1.write();
				cout<<"to exit from insert mode press 0 else press anyother number to continue"<<endl;
				int a;
				cin>>a;
				if(a==0)
					break;
				}
			}
			break;
		case 2:
			{
				string usn;
				cout<<"enter the usn :";
				cin>>usn;
				s1.search(usn);
			}
		case 4:
				{
					string usn;
					cout<<"enter the usn :";
					cin>>usn;
					modify(usn);
				}
		}
	}
	return 0;
}
