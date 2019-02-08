
#include <iostream>		
#include <fstream>		  
#include <stdio.h>      
#include <math.h>       


using namespace std;
int fd,fs,df,i,l;
float pi=3.1415;
float p,z1,r,p1,z2;
float a[3],b[3];
float name;


int main()

{
	cout<<"please enter sampling frequency fd"<<endl;
	cin>>fd;
	cout<< "fd="<<fd<<endl;
	cout<<"plesae enter stopband frequency fs"<<endl;
	cin>>fs;
	cout<< "fs="<<fs<<endl;
	cout<<"please enter bandwidth"<<endl;
	cin>>df;
	cout<< "df="<<df<<endl;
	cout<<"please enter length of the signal l"<<endl;
	cin>>l;
	cout<< "l="<<l<<endl;
	float s[l];
  float filt[l];
	r=1-(pi*df/fd);
	p=cos(2*pi*fs/fd);
	z1=sin(2*pi*fs/fd);
	p1=p*r;
	z2=z1*r;
	
	 
	 //--------------------Filter coeficients----------------------------//
    b[0]=1; b[1]=-2*p; b[2]=p*p+(z1*z1);
	cout<<"b="<<b[0]<<" "<<b[1] <<" "<<" "<<b[2]<<endl;

	a[0]=1; a[1]=-2*p1; a[2]=p1*p1+(z2*z2);
	cout<<"a="<<b[0]<<" "<<a[1] <<" "<<" "<<a[2]<<endl;
	//-------------------------------------------------------------------//
	
	ifstream theFile("signal.txt"); /*input file*/



while(theFile >>name)


{

/* this part is used to load the signal from txt file*/

	s[i]=name;
	i=i+1;
}

//-----------------------filtering---------------------//
filt[0]= s[0]*b[0];
filt[1]=(s[1]*b[0])+(s[0]*b[1])-(filt[0]*a[1]);



for (i=2;i<l;i++)
{
filt[i]=(s[i]*b[0])+(s[i-1]*b[1])+(s[i-2]*b[2])-(filt[i-1]*a[1])-(filt[i-2]*a[2]);
	
}

//-----------------------------------------------------------//


ofstream text("processed.txt"); /*output file*/

	for(i=0;i<l;i=i+1)
	{

{
	text <<filt[i]<<endl;
	
	if(i==l-1)
	{
		cout<<"signal processing have been finished!"<<endl;
	}
}

}
}
