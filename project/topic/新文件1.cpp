#include<stdio.h>
#include<conio.h>
#include<time.h> 
#include<stdlib.h>
#include<graphics.h>
#include<windows.h>

int main()
{
	initwindow(700,300);
	
	int i;
	
	char button[3][100]={".\\topic\button-start",
						 ".\\topic\button-rank",
						 ".\\topic\button-exit"};
						 
	char buttonmove[3][100]={".\\topic\button-start",
						 ".\\topic\button-rank",
						 ".\\topic\button-exit"};
						 
	
	char buttondown[3][100]={".\\topic\button-start2",
						 		".\\topic\button-rank2",
						 		".\\topic\button-exit2"};
						 		
	for(i=0;i<3;i++)
	{
		readimagefile(button[i],50+25*i,200,100+25*i,250);
	}
	
	getch();	
	return 0;
}
