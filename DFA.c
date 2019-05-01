 #include<stdio.h>
#include<string.h>
#include<stdlib.h>

int stat[10],tran[20][20],finalstate[20];
int nextstate,fs,ips,init,i,j,k,m;
char sym[10],ch,str[10],a[10];

void state(void);
void symbol(void);
void transition(void);
void initial(void);
void final(void);
void run(void);
void display(void);

int main()
{
	int ch;
	state();
	symbol();
	transition();
	initial();
	final();
	run();
	display();
}


void state()
{
	printf("\n How many States your DFA has?: ");
	scanf("%d",&ips);
	for(i=0;i<ips;i++)
	{
		printf("\n Enter state %d:q",i+1);
		scanf("%d",&stat[i]);
	}
}

void symbol()
{
	printf("\n Enter the number of input symbols: ");
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		printf("\n Enter you symbol here: %d",i+1);
		scanf("%s",&sym[i]);
	}
}

void transition()
{
	printf("\n Give transition by specifying state number");
	for(i=0;i<ips;i++)
	{
		for(j=0;j<m;j++)
		{
			printf("\n Trnsition from q[%d] over  %c will go to :q",i,sym[j]);
			scanf("%d",&tran[i][j]);
		}
	}
}

void initial()
{
	printf("\n What is you initial State:q");
	scanf("%d",&init);
}

void final()
{
	printf("\n How many final states do you have?: ");
	scanf("%d",&fs);
	for(i=0;i<fs;i++)
	{
		printf("\n What is your %d final states:q",i+1);
		scanf("%d",&finalstate[i]);
	}
}

void run() 
{
	int tag=0;
	do{
		printf("\n Entert the input string:");
		scanf("%s",str);
		i=init;
		for(k=0;k<strlen(str);k++)
		{
			for(j=0;j<m;j++) 
			{
				if(str[k]==sym[j])
					break;
			}
			nextstate=tran[i][j];
			i=nextstate;
		}
		for(j=0;j<fs;j++) 
		{
			if(i==finalstate[j])
				tag=1;
		}
		if(tag==1)
		{
			printf("\n Given string is accepted");
			tag=0;
		}
		else
		{	
			printf("\n Given string is rejected");
			tag=0;
		}
		printf("\n Do you want to verify again?:(y/n):");
		scanf("%s",&ch);
	}
	while(ch!='n');
}

void display()
{
	printf("\n The  DFA is as given below");
	printf("\n Q={");
	for(i=0;i<ips;i++) 
	{	
		printf("q[%d],",stat[i]);
	}
	printf("}");
	printf("\n Input Symbols={");
	for(i=0;i<m;i++)
	{
		printf("%c,",sym[i]);
	}
	printf("}");
	printf("\n F={");
	for(i=0;i<fs;i++) 
	{
		printf("q[%d]",finalstate[i]);
	}
	printf("}");
	printf("\n Initial state={q[%d]}",init);
	printf("\n Transition function \n");
	printf("\n\t %c",235);
	for(i=0;i<m;i++)
		printf("\t %c",sym[i]);
	printf("\n");

	for(i=0;i<ips;i++) 
	{
		printf("\t q[%d]",stat[i]);
		for(j=0;j<m;j++) 
		{
			printf("\t q[%d]",tran[i][j]);
		}
		printf("\n");
	}
}

