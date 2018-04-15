#include<conio.h>
#include<time.h>
#include<iostream>
#include<stdlib.h>
#include<stdio.h>

using namespace std;

int score=0;
int count=1;
int big;

void large(int a[4][4]){
 for(int i=0;i<4;i++)
 {
	for(int j=0;j<4;j++)
	{
		if(a[i][j]>big)
		{
			big=a[i][j];
		}
	}
 }
}

int digits(int b)
{
 int count=0;
 while(b>0){
	b/=10;
	count++;
 }
 return count;
}

void spaces(int a)
{
 int space=0;
 space=digits(big);
 for(int i=digits(a)-1;i<space-1;i++)
 {
 cout<<" ";
 }
}

int exitcondition(int a[4][4])
{
 int ec=0;
 for(int i=0; i<4; i++)
 {
	for(int j=0; j<4; j++)
	{
		if(i<3)
        {
            if(j<3)
            {
                if(a[i+1][j]==a[i][j]||a[i][j+1]==a[i][j]||a[i][j]==1||a[i+1][j]==1||a[i][j+1]==1)
                {
                    ec++;
                }
            }
            else if(j>=3)
                if(a[i+1][j]==a[i][j]||a[i][j]==1||a[i+1][j]==1)
                    ec++;
        }
		else if(i>=3)
			if(a[i][j+1]==a[i][j]||a[i][j]==1||a[i][j+1]==1)
				ec++;
	}
 }
 if(ec>0)
 {
	return 0;
 }
 else
 {
	return 1;
 }
}

void display(int a[4][4])      //Grid size?
{
 //clrscr();
 system("cls");
 cout<<"your score is "<<score<<endl;
 cout<<"  ---------------------------"<<endl;
 for(int i=0;i<4;i++)
 {
	for(int j=0;j<4;j++)
	{

		if(a[i][j]%2==0)
		{
			cout<<"  |"<<a[i][j];
			if(digits(a[i][j])!=digits(big))
			{
			spaces(a[i][j]);
			}
		}
		else
		{
			cout<<"  | ";
			if(digits(a[i][j])!=digits(big))
			{
			spaces(a[i][j]);
			}
		}
	}
	cout<<"  |"<<endl;
 }
 cout<<"  ---------------------------"<<endl;
}

void generate(int a[4][4])
{
 srand(time(NULL));
 lbl:
 int ipos=rand()%4;
 int jpos=rand()%4;
 if(count==0){

 }
 else{
	if(a[ipos][jpos]%2!=0)
	{
		a[ipos][jpos]=2;
	}
	else
		goto lbl;
	count=0;
 }
}

void shift(int a[4][4])
{
 cout<<"\n\n Menu:Select what direction you wish to swipe in:\n1. Right(d)\n2. Left(a)\n3. Up(w)\n4. Down(s)\n ";
 char dir;
 lb:
     dir=getch();
     switch(dir)
     {
        case 'w':
        case 'a':
        case 's':
        case 'd': break;
        default: goto lb;
    }
 if(dir=='d')
 {
	for(int i=0;i<4;i++){
		for(int j=2;j>=0;j--)
		{
			if(a[i][j]%2==0)
			{
				if(a[i][j+1]%2!=0)
				{
					a[i][j+1]=a[i][j];
					a[i][j]=1;
					j=3;
					count++;
				}
				else{
					if(a[i][j]==a[i][j+1])
					{
						a[i][j+1]*=2;
						a[i][j]=1;
						score+=a[i][j+1];
						count++;
					}
				}
			}
		}
	  }
 }
 else if(dir=='a'){
	for(int i=0;i<4;i++){
		for(int j=1;j<4;j++)
		{
			if(a[i][j]%2==0)
			{
				if(a[i][j-1]%2!=0)
				{
					a[i][j-1]=a[i][j];
					a[i][j]=1;
					j=0;
					count++;
				}
				else{
					if(a[i][j-1]==a[i][j])
					{
						a[i][j-1]*=2;
						a[i][j]=1;
						score+=a[i][j-1];
						count++;
					}
				}
			}
		}
	  }
 }
 else if(dir=='w'){
	for(int j=0;j<4;j++){
		for(int i=1;i<4;i++)
		{
			if(a[i][j]%2==0)
			{
				if(a[i-1][j]%2!=0)
				{
					a[i-1][j]=a[i][j];
					a[i][j]=1;
					i=0;
					count++;
				}
				else{
					if(a[i-1][j]==a[i][j])
					{
						a[i-1][j]*=2;
						a[i][j]=1;
						score+=a[i-1][j];
						count++;
					}
				}
			}
		}
	  }
 }
 else if(dir=='s')
 {
	for(int j=0;j<4;j++){
		for(int i=2;i>=0;i--)
		{
			if(a[i][j]%2==0)
			{
				if(a[i+1][j]%2!=0)
				{
					a[i+1][j]=a[i][j];
					a[i][j]=1;
					i=3;
					count++;
				}
				else{
					if(a[i][j]==a[i+1][j])
					{
						a[i+1][j]*=2;
						a[i][j]=1;
						score+=a[i+1][j];
						count++;
					}
				}
			}
		}
	  }
 }
}

int main()
{

 int a[4][4]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
 srand(time(NULL));
 int ipos=rand()%4;
 int jpos=rand()%4;
 a[ipos][jpos]=2;
 lb:
 large(a);
 generate(a);
 display(a);
 shift(a);
 display(a);
 if(exitcondition(a)==0)
	goto lb;
 else
	{
	    cout<< "Game over!\nYour final score is "<<score<<".";
	    getch();
	}
return 0;
}
