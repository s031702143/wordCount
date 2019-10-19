#include <iostream>
#include <stdlib.h>
#include<fstream>
#include <string>
#include <stdio.h>
using namespace std;
void change_char(char *arr)	//将分隔符变为空格 
{
	int len=strlen(arr);
	for(int i=0;i<len;i++)
		if((64<arr[i]&&arr[i]<91)||(96<arr[i]&&arr[i]<123)||(47<arr[i]&&arr[i]<58)) ;
		else arr[i]=' ';
}
bool isc(char c)			//是否是字母或数字 
{
	if((64<c&&c<91)||(c&&c)||(47<c&&c)) return true;
	else return false;
}
void write_be(char *arr,int begin[],int end[],int numb) 
{	//子串开始位置与结束位置写好,并且给出子串个数 
	int num=0;
	char c='\0';
	bool sign=true;
	int bbegin=0,eend=0;
	if(isc(arr[0])) begin[num]=0;
	for(int k=0;k<strlen(arr);k++)
	{
		if(isc(arr[k]))	{
			if(!isc(arr[k+1])) {end[num]=k;numb++;} 
		};
		if(!isc(arr[k])) {
			if(isc(arr[k+1])) begin[num]=k+1;
		}
	}
} 
void copy_char_arr(char (*arr)[],int *b,int *e,int n,char yuan[])
{		//将子串copy到二维数组 
	int i,begin,end;
	for(i=0;i<n;i++)
	{
		int a0=b[i];
		for(int j=b[i];j<=e[i];j++)
			arr[i][j-a0]=yuan[j];
	}
} 
int isdanci(char arr[])		//是否是符合题目的单词形式 
{
	int len=strlen(arr);
	if(len<4) return -1;
	for(int i=0;i<4;i++)
		if(arr[i]<47||58<arr[i])	return -1;
	return 0;
}
int main()
{
	int m=2;
	char a[100]={"Monday 1uesday Friday\nMonday!Tuesday@Wednesday ThursdayFriday"};
	char aa[100][20]={'\0'};
	int numble=0;	//子串个数 
	int begin[100]={0},end[100]={0};  //用以表示第i个的开头位置与结束位置
	int danci[100]={0}; 	 //arr[i]为0，第i个是单词，为-1，不是 
	write_be(a,begin,end,numble);
	change_char(a);
	for(int k=0;k<numble;k++)
		danci[k]=isdanci(aa[k]);
	for(int first=0;first<numble-m;first++)
		{
			int sum=0;
			for(int nn=0;nn<m;nn++)
				sum+=danci[nn];
			if(sum == 0) {
			for(int nn=0;nn<m;nn++) 
				cout<<aa[nn]<<' ';
				cout<<'\n';
				} 
		} 
	return 0;
}
//"Monday Tuesday 1jkal \nMonday Tuesday ThursdayFriday"
// i    j k     l    
