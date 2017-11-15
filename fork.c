#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>
#include<sys/types.h>

int main()
{
	pid_t pid[4];
	int nos[100], result[4]={0,0,0,0};
	int status;
	int sum=0, i;
	
	for(int n=0; n<100; n++)
	{ nos[n]=1;}

	for(i=0;i<4;i++)
	{
		pid[i]=fork();
		if(pid[i]<0)
			{exit(EXIT_FAILURE);}
		else if(pid[0]==0)
		{	
			for(int j=0;j<25;j++)
				{result[0]=result[0]+nos[j];}
		}
		else if(pid[1]==0)
		{	
			for(int j=25;j<50;j++)
				{result[1]=result[1]+nos[j];}
		}
		else if(pid[2]==0)
		{	
			for(int j=50;j<75;j++)
				{result[2]=result[2]+nos[j];}
		}
		else if(pid[3]==0)
		{	
			for(int j=75;j<100;j++)
				{result[3]=result[3]+nos[j];}
		}
		else
			{printf("Parent\n");}
	}

	for(int i=0;i<4;i++)
		{pid[i]=wait(&status);}

	sum=result[0]+result[1]+result[2]+result[3];
	printf("sum %d\n",sum);
	return 0;
}