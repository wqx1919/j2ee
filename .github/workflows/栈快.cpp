#include<iostream>
#include<fstream>
#include<stack>
#include<math.h>
using namespace std;
void main()
{
	ifstream in("intput.txt");
	ofstream out("output.txt");
    int r,r1,n,ai[100][100]={0};
	int l=0,t=0;
	void hie(int ai[100][100],int j,int i,int n);
		 in>>n;
	for(r=1;r<n+1;r++)
	{
	   for(r1=1;r1<n+1;r1++)
	       in>>ai[r][r1];					
	}
	for(r=1;r<n+1;r++)
	{
	   for(r1=1;r1<n+1;r1++)
		   if(ai[r][r1]==1)
		   {	
			   	hie(ai,r,r1,n);			
				l++;
		   }
	}
	cout<<l;
}
void hie(int ai[100][100],int j,int i,int n)
{          
	int ha,le,r1,r;
         stack<int >s1,s2;
    	 s1.push(j);s2.push(i);
    	while(s1.size()<=n*n)
		{
					 ha=s1.top(); le=s2.top();
					 ai[ha][le]=-1;					   
					if( ai[ha+1][le]==1)//下
					{
                       s1.push(ha+1);s2.push(le);
					    ai[ha+1][le]=-1;
					}
				  	if( ai[ha][le+1]==1)//后
					{
                       s1.push(ha);s2.push(le+1);
					    ai[ha][le+1]=-1;
					}
					if( ai[ha-1][le]==1)//上
					{
                       s1.push(ha-1);s2.push(le);
					    ai[ha-1][le]=-1;
					}
					if( ai[ha][le-1]==1)//前
					{
                        s1.push(ha);s2.push(le-1);
					    ai[ha][le-1]=-1;
					}	
				    if(s1.top()==ha && s2.top()==le)
					{    
						s1.pop();s2.pop();
					}
					if(s1.size()==0)
						break;					
		}
		cout<<endl;
		for(r=0;r<=n+1;r++)
	{
	   for(r1=0;r1<=n+1;r1++)
		   if(ai[r][r1]==-1)
	       cout<<ai[r][r1]<<" ";
		   else
			   cout<<" "<<ai[r][r1]<<" ";
	   cout<<endl;
	}
}
/*	for(r=0;r<=n+1;r++)
	{
	   for(r1=0;r1<=n+1;r1++)
		   if(ai[r][r1]==-1)
	       cout<<ai[r][r1]<<" ";
		   else
			   cout<<" "<<ai[r][r1]<<" ";
	   cout<<endl;
	}*/