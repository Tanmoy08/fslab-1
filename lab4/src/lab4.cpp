#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
#include<stdlib.h>
using namespace std;
vector<int> rrn;
int rsize=0;
class Studentrecord{
    string name;
    string usn;
    string branch;
    int sem;
    string buffer;
    public:
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
        int pack()
        {
          string sem1;
		string temp;
		stringstream out;
		out<<sem;
		sem1=out.str();
		temp=usn+'|'+name+'|'+branch+'|'+sem1;
		cout<<temp<<endl;
		buffer=temp;
               int a=buffer.size();
               return a;
        }
        void write()
	{
		fstream fp1;
		fp1.open("data1.txt",ios::out|ios::app);
		fp1<<buffer;
                fp1.close();
		
	}
        int print()
        {
            fstream fp1;
            fp1.open("data1.txt",ios::in);
            int pos=fp1.tellp();
            fp1.close();
            
        }
};
int main()
{
    int choice;
    Studentrecord s;
    cout<<"Enter your choice :\n1) Insert\n2) Search"<<endl;
    cin>>choice;
    switch(choice)
    {
        case 1:
        {
            s.read();
            int len=s.pack();
            s.write();
            int pos=s.print();
            rrn[rsize]=pos-len;
            for(int i=0;i<=rrn.size();i++)
                cout<<rrn[i]<<endl;
           // cout<<"record is successfully written"<<endl;
        }
        break;
        default: cout<<"invalid option chosen"<<endl;
    }
}
