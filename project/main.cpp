#include<stdio.h>
#include<conio.h>
#include<time.h> 
#include<stdlib.h>
#include<graphics.h>
#include<windows.h>
#include "level.h"
#include "starting page code.h"
#include "ending page code.h"
#include "rank.h"

#define UP_KEY 0x26
#define DOWN_KEY 0x28
#define L_KEY 0x25
#define R_KEY 0x27
#define space_key 0x20

int main()
{
	srand(time(NULL));	
    initwindow(700,400);
    
    int op=0,s;
    
    op=start();
    
    while(1)
    {
    clearmouseclick(WM_LBUTTONDOWN);	
    switch(op)
    {
        case 0:
            op=start();
            break;
        case 1:
            s=level(4);
            updaterank(s);
            op=ending(s);
			break;
        case 2:
        	op=showrank();
            break;
        case 3:
            exit(1);        
    }
	}
	
	closegraph();
	return 0;		
}
