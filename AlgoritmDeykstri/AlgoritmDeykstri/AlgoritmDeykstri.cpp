/// \file AlgoritmDeykstri.cpp

#include "stdafx.h"
#include<iostream>
#include<fstream>
#include<iomanip>
#include<conio.h>
using namespace std;
 
void read_from_file(int* n,int* start,int*finish,int* ves)  ///chtenie faila
 {
  ifstream f("deikstra.txt");
  if(!f) cout<<"File error!\n";
  else
  {
    f >> *n >> *start>> *finish;
    for(int i=0;i<*n;i++)
      for(int j=0;j<*n;j++)
       f>>*(ves+i*10+j);
  }
 }
int find_minimum(int* n,bool* used,int* metka)  ///poisk minimuma
{
 int min;
 for(int i=0;i<*n;i++)
     if (*(used+i)==false) {min=i;break;}
 for(int i=0;i<*n;i++)
     if(*(used+i)==false && *(metka+min)>*(metka+i)) min=i;
 return min;
}
void find_neighbours(int a,int n,int* ves,bool* used,int* metka)
{
 for(int i=0;i<n;i++)
  if(*(ves+a+i*10)!=0 && !*(used+i) && *(metka+i)>*(ves+a+i*10)+*(metka+a))
   *(metka+i)=*(ves+a+i*10)+*(metka+a);
 *(used+a)=true;
}
void otladka(int* n,int* metka,bool* used) ///otladka
{
 for(int i=0;i<*n;i++)
  cout<<i+1<<':'<<*(metka+i)<<' '<<*(used+i)<<' ';
 cout<<"\n";
}
bool finish_program(int* n,bool* used)  ///okonchanie programmy
{
 bool f=true;
 for(int i=0;i<*n;i++)
  if(!*(used+i)) f=false;
 return f;
}
int main()
  {
     int start,finish,n;   ///inicializacia peremennyh
     int ves[10][10],metka[10];  ///massivy
     bool used[10];
    read_from_file(&n,&start,&finish,&ves[0][0]); ///ispolzovanie finkcii chteniya fayla
      start--;                                    ///nachalo
      finish--;									  ///end
    for(int i=0;i<n;i++)
     {metka[i]=100;used[i]=false;}
    metka[start]=0;
   while(!finish_program(&n,&used[0]))
   {
    int nowusing=find_minimum(&n,&(used[0]),&(metka[0]));
    find_neighbours(nowusing,n,&ves[0][0],&used[0],&metka[0]);
    /*otladka(&n,&metka[0],&used[0]);*/
   }
   cout<<metka[finish];
   cin.get();
  }