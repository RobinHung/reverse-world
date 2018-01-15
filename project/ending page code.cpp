#include<stdio.h>
#include<conio.h>
#include<time.h> 
#include<stdlib.h>
#include<graphics.h>
#include<windows.h>
#define f1(x,y) (x-110)*(x-110)/60/60+(y-222)*(y-222)/30/30
#define f2(x,y) (x-280)*(x-280)/60/60+(y-222)*(y-222)/30/30
#define f3(x,y) (x-450)*(x-450)/60/60+(y-222)*(y-222)/30/30
int end_page=0;
char end_bk[100]=".\\ending page\\bk.gif"; 
char gameover[1][100]={".\\ending page\\game over.gif"};
char sco[1][100]={".\\ending page\\score.gif"};
char end_word[3][100]={".\\ending page\\CONTINUE-word.gif",
				    ".\\ending page\\RANK-word.gif",					
				    ".\\ending page\\MENU-word.gif"};
char end_botton_bk[2][100]={".\\ending page\\button-background.gif",
						    ".\\ending page\\button2-background.gif"};
char strsco[50]="\0";
int ending(int ss)
{
	sprintf(strsco,"%d",ss);
    while(1)
    {
    	setvisualpage(end_page);
    	end_page=-end_page+1;    
        setactivepage(end_page);
        
        clearmouseclick(WM_LBUTTONDOWN);
    	
    	readimagefile(end_bk,0,0,700,400);
    	
    	//gameover.scorre
    	readimagefile(gameover[0],40,35,490,185);
    	readimagefile(sco[0],25,300,125,350);
    	settextstyle(SIMPLEX_FONT,HORIZ_DIR,4);
    	//setusercharsize(5,2,5,2);
    	outtextxy(200,320,strsco);
		
		//button-continue            	
    	if(f1(mousex(),mousey())<=1&&mousex()>30 && mousex()<175 && mousey()>175 && mousey()<270)
		{
			readimagefile(end_botton_bk[0],30,175,190,270);
			if(ismouseclick(WM_LBUTTONDOWN))
			{
				clearmouseclick(WM_LBUTTONDOWN);
				readimagefile(end_botton_bk[1],30,177,190,272);
				printf("Continue\n");
				return 1;
			}            
		}else{
			readimagefile(end_botton_bk[0],30,175,190,270);
    		readimagefile(end_word[0],45,177,175,272);
		}
		
		//button-rank
    	if(f2(mousex(),mousey())<=1&&mousex()>200 && mousex()<360 && mousey()>175 && mousey()<270)
		{
			readimagefile(end_botton_bk[0],200,175,360,270);
			if(ismouseclick(WM_LBUTTONDOWN))
			{
				clearmouseclick(WM_LBUTTONDOWN);
				readimagefile(end_botton_bk[1],200,177,360,272);
				printf("Rank\n");
				return 2;
			}  
		}else{
			readimagefile(end_botton_bk[0],200,175,360,270);
    		readimagefile(end_word[1],219,175,390,275);
		}
    	
    	//button-menu
    	if(f3(mousex(),mousey())<=1&&mousex()>370 && mousex()<530 && mousey()>175 && mousey()<270)
		{
			readimagefile(end_botton_bk[0],370,175,530,270);
			if(ismouseclick(WM_LBUTTONDOWN))
			{
				clearmouseclick(WM_LBUTTONDOWN);
				readimagefile(end_botton_bk[1],370,177,530,272);
				printf("Menu\n");
				return 0;
			}  
		}else{
			readimagefile(end_botton_bk[0],370,175,530,270);
    		readimagefile(end_word[2],376,177,546,277);
		}
    }
}

/*int main()
{
	initwindow(700,400);
	int p=123456;
	
    p=ending(p);

	closegraph();	
	return 0;
}*/
