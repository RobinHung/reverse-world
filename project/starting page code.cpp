#include<stdio.h>
#include<conio.h>
#include<time.h> 
#include<stdlib.h>
#include<graphics.h>
#include<windows.h>
#define f1(x,y) (x-110)*(x-110)/60/60+(y-222)*(y-222)/30/30
#define f2(x,y) (x-280)*(x-280)/60/60+(y-222)*(y-222)/30/30
#define f3(x,y) (x-450)*(x-450)/60/60+(y-222)*(y-222)/30/30

int start_page=0;
	
char start_bk[1][100]={".\\starting page\\sky2.jpg"};
char gamename[2][100]={".\\starting page\\reverse3.gif",
					   ".\\starting page\\world3.gif"};
char monkey[1][100]={".\\starting page\\monkey2.gif"};
char start_botton_bk[1][100]={".\\starting page\\button-start_botton_bk.gif"};
char start_word[3][100]={".\\starting page\\PLAY.gif",
				   ".\\starting page\\RANK.gif",
				   ".\\starting page\\EXIT.gif"};

int start()
{
    while(1)
	{	
		setvisualpage(start_page);
    	start_page=-start_page+1;    
        setactivepage(start_page);
        clearmouseclick(WM_LBUTTONDOWN);
        readimagefile(start_bk[0],0,0,700,400);
		readimagefile(gamename[0],0,0,350,125);
		readimagefile(gamename[1],150,70,475,195);

      
        readimagefile(monkey[0],450,200,700,400);  
		 
		//"play" button
		if(f1(mousex(),mousey())<=1&&mousex()>30 && mousex()<170 && mousey()>190 && mousey()<270)
		{
			readimagefile(start_botton_bk[0],30,175,190,270);
			if(ismouseclick(WM_LBUTTONDOWN))
            {
               clearmouseclick(WM_LBUTTONDOWN);
               printf("Play\n");
               return 1;
            }   
		}else{
			readimagefile(start_botton_bk[0],30,175,190,270);
			readimagefile(start_word[0],47,187,177,262);
		}
		
		
		//"rank" button
		if(f2(mousex(),mousey())<=1&&mousex()>200 && mousex()<360 && mousey()>175 && mousey()<270)
		{
			readimagefile(start_botton_bk[0],200,175,360,270);
			if(ismouseclick(WM_LBUTTONDOWN))
            {
               clearmouseclick(WM_LBUTTONDOWN);
               printf("Rank\n");
               return 2;
            }   
		}else{
			readimagefile(start_botton_bk[0],200,175,360,270);
			readimagefile(start_word[1],220,187,348,262);
		}
		
		//"exit button"
		if(f3(mousex(),mousey())<=1&&mousex()>370 && mousex()<540 && mousey()>175 && mousey()<270)
		{
			readimagefile(start_botton_bk[0],370,175,540,270);
			if(ismouseclick(WM_LBUTTONDOWN))
            {
               clearmouseclick(WM_LBUTTONDOWN);
               printf("Exit\n");
               return 3;
            } 
		}else{
			readimagefile(start_botton_bk[0],370,175,540,270);
			readimagefile(start_word[2],373,189,536,264);
		}
	}
}

/*int main()
{
    int p;
	initwindow(700,400);
	p=start();
	closegraph();	
	return 0;
}*/
