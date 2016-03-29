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
    string fname[8];
    string name[100];
public:
    void mergef()
    {
        string buffer;
        fstream fp1,fp2;
        fp2.open("final.txt",ios::out|ios::app);
        fp1.open("1.txt",ios::in);
        while(!fp1.eof())
        {
            getline(fp1,buffer);
            fp2<<buffer;
            fp2<<endl;
        }
        fp1.close();
        fp1.open("2.txt",ios::in);
        while(!fp1.eof())
        {
            getline(fp1,buffer);
            fp2<<buffer;
            fp2<<endl;
        }
        fp1.close();
        fp1.open("3.txt",ios::in);
        while(!fp1.eof())
        {
            getline(fp1,buffer);
            fp2<<buffer;
            fp2<<endl;
        }
        fp1.close();
        fp1.open("4.txt",ios::in);
        while(!fp1.eof())
        {
            getline(fp1,buffer);
            fp2<<buffer;
            fp2<<endl;
        }
        fp1.close();
        fp1.open("5.txt",ios::in);
        while(!fp1.eof())
        {
            getline(fp1,buffer);
            fp2<<buffer;
            fp2<<endl;
        }
        fp1.close();
        fp1.open("6.txt",ios::in);
        while(!fp1.eof())
        {
            getline(fp1,buffer);
            fp2<<buffer;
            fp2<<endl;
        }
        fp1.close();
        fp1.open("7.txt",ios::in);
        while(!fp1.eof())
        {
            getline(fp1,buffer);
            fp2<<buffer;
            fp2<<endl;
        }
        fp1.close();
        fp1.open("8.txt",ios::in);
        while(!fp1.eof())
        {
            getline(fp1,buffer);
            fp2<<buffer;
            fp2<<endl;
        }
        fp1.close();
        fp2.close();
    }
    void mgrsort()
    {
        cout<<"inside mgrsort"<<endl;
        int i;
        string buffer;
        
        int rsize=0;
        fstream fp1;
        fp1.open("final.txt",ios::in);
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
        int mid=(1+i)/2;
        mgrsrt m1;
        m1.mergesort(name,0,i-1);
        cout<<"file sorted"<<endl;
        fp1.open("final.txt",ios::out);
        fp1.close();
        fp1.open("final.txt",ios::out|ios::app);
        for(int k=0;k<i-1;k++)
        {
            fp1<<name[k];
            fp1<<endl;
        }
    }

void merge(string name[100],int l,int m,int r)
{
    cout<<"inside merge"<<endl;
   int i=0,j=0,k=0;
   int n1 = m - l + 1;
   int n2 =  r - m;
   string L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = name[l + i];
    for (j = 0; j < n2; j++)
        R[j] = name[m + 1+ j];
    i = 0; 
    j = 0;
    k = 0;
     while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
           name[k] = L[i];
            i++;
        }
        else
        {
            name[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        name[k] = L[i];
        i++;
        k++;
    }
     while (j < n2)
    {
        name[k] = R[j];
        j++;
        k++;
    }
    return;
}
void mergesort(string name[100], int l, int r)
{
    cout<<"inside mergesort"<<endl;
    mgrsrt m2;
    if (l < r)
    {
        int m = (l+r)/2;
        m2.mergesort(name, l, m);
        m2.mergesort(name, m+1, r);
        m2.merge(name, l, m, r);
    }
    return;
}
};
int main()
{
    mgrsrt m;
    m.mergef();
    m.mgrsort();
    cout<<"file sorted"<<endl;
}
