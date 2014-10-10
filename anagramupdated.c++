//it is working just for strings upto 4 characters.. dont know why..
#include<iostream>
using namespace std;
#include<string.h>
void merge(int [],int ,int ,int );
void part(int arr[],int min,int max)
{
 int mid;
 if(min<max)
 {
   mid=(min+max)/2;
   part(arr,min,mid);
   part(arr,mid+1,max);
   merge(arr,min,mid,max);
 }
}


void merge(int arr[],int min,int mid,int max)
{
  int tmp[30];
  int i,j,k,m; 
  j=min;
  m=mid+1;
  for(i=min; j<=mid && m<=max ; i++)
  {
     if(arr[j]<=arr[m])
     {
         tmp[i]=arr[j];
         j++;
     }
     else
     {
         tmp[i]=arr[m];
         m++;
     }
  }
  if(j>mid)
  {
     for(k=m; k<=max; k++)
     {
         tmp[i]=arr[k];
         i++;
     }
  }
  else
  {
     for(k=j; k<=mid; k++)
     {
        tmp[i]=arr[k];
        i++;
     }
  }
  for(k=min; k<=max; k++)
     arr[k]=tmp[k];
}


int main()
{
int status=1;
char str[100],str1[100];
cout<<"enter string 1";
cin>>str;
cout<<"enter string 2";
cin>>str1;

	if(strlen(str1)!=strlen(str))
		{
		cout<<"not anagrams";
		}

	else
		{

	int *strarray=new int(strlen(str));
	int *strarray1=new int(strlen(str1));

	for(int i=0;i<strlen(str);i++)
		{
		strarray[i]=(int) str[i]; //typecasting to int
		}

	for(int i=0;i<strlen(str);i++)
		{
		strarray[i]=strarray[i]-97; //'a'=97
		}

	for(int i=0;i<strlen(str1);i++)
		{	
		strarray1[i]=(int) str1[i];  // typecasting to int
		}	

	for(int i=0;i<strlen(str1);i++)
		{
		strarray1[i]=strarray1[i]-97;
		}
	part(strarray,0,strlen(str)-1); //calling merge sort
	part(strarray1,0,strlen(str1)-1);

for(int i=0;i<strlen(str);i++)
	{
	if(strarray[i]!=strarray1[i])
		{
		status=0;
		break;
		}
	else 
		status=1;

	}

if(status==0)
{
cout<<"not anagrams";
}
else
{
cout<<"anagrams";
}
return 0;
}
}
