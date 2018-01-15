#include<stdio.h>
#include<conio.h>
#include<time.h> 
#include<stdlib.h>
#include<graphics.h>
#include<windows.h>

#define UP_KEY 0x26
#define DOWN_KEY 0x28
#define LEFT_KEY 0x25
#define RIGHT_KEY 0x27
#define space_key 0x20

int level(int); 
int level4();
//map-declare-----------------------------------------------//
char map[12][100]={".\\level\\floor.bmp",
				   ".\\level\\sky.bmp",
				   ".\\level\\trap_down.bmp",
				   ".\\level\\trap_up.bmp",
				   ".\\level\\trap_u&d.bmp",
				   ".\\level\\none.bmp",
				   ".\\level\\hollow4.bmp",
				   ".\\level\\hollow2.bmp",
				   ".\\level\\hollow1.bmp",
				   ".\\level\\hollow3.bmp",
				   ".\\level\\hollow5.bmp",
				   ".\\level\\ground.bmp"};
char saw[2][100]={".\\level\\saw1.bmp",
				  ".\\level\\asw2.bmp"};			   
int AI[200],ai=0;//record map
int type[8]={0};//up or down
int sit_x[8]={0,100,200,300,400,500,600,700};//x_site of start					 
int page=0,i,x,speed=20,page_saw=0;//standard data
int score=0;
char *s_sco=new char[50];//score tostring
//---------------------------------------------------------------//
//figure-declare--------------------------------------------//
char pic1[12][100]={".\\figure\\run_down\\00.gif",
					".\\figure\\run_down\\01.gif",  //DOWN 
					".\\figure\\run_down\\02.gif",
					".\\figure\\run_down\\03.gif",
					".\\figure\\run_down\\04.gif",
					".\\figure\\run_down\\05.gif",
					".\\figure\\run_down\\06.gif",
					".\\figure\\run_down\\07.gif",
					".\\figure\\run_down\\08.gif",
					".\\figure\\run_down\\09.gif",
					".\\figure\\run_down\\10.gif",
					".\\figure\\run_down\\11.gif"};
char pic2[12][100]={".\\figure\\run_up\\00.gif",
					".\\figure\\run_up\\01.gif",  //UP 
					".\\figure\\run_up\\02.gif",
					".\\figure\\run_up\\03.gif",
					".\\figure\\run_up\\04.gif",
					".\\figure\\run_up\\05.gif",
					".\\figure\\run_up\\06.gif",
					".\\figure\\run_up\\07.gif",
					".\\figure\\run_up\\08.gif",
					".\\figure\\run_up\\09.gif",
					".\\figure\\run_up\\10.gif",
					".\\figure\\run_up\\11.gif"};
char change[20][50]={".\\figure\\power\\00.gif",  // fly
					 ".\\figure\\power\\01.gif",
					 ".\\figure\\power\\02.gif",
					 ".\\figure\\power\\03.gif",
					 ".\\figure\\power\\04.gif",
					 ".\\figure\\power\\05.gif",
					 ".\\figure\\power\\06.gif",
					 ".\\figure\\power\\07.gif",
					 ".\\figure\\power\\08.gif",
					 ".\\figure\\power\\09.gif",
					 ".\\figure\\power\\10.gif",
					 ".\\figure\\power\\11.gif",
					 ".\\figure\\power\\12.gif",
					 ".\\figure\\power\\13.gif",
					 ".\\figure\\power\\14.gif",
					 ".\\figure\\power\\15.gif",
					 ".\\figure\\power\\16.gif",
					 ".\\figure\\power\\17.gif",
					 ".\\figure\\power\\18.gif",
					 ".\\figure\\power\\19.gif"};
char blo[50]=".\\figure\\blood.bmp";//blood
int flag_run=0,flag_jump=0;//image change
int fx=310,fy=0;//figure initial site
int flag_toup=0,flag_todown=0;//determine stand or move
int power=0,blood=20;// figure data
int back=0,use=0;
int wall[8]={0};
int energy=0,bar_long=0; 
//----------------------------------------------------//
void generate_lv1(int *x)//generate the map of lv1 
{
	char tmp[20];
	int i=0,c=0;
	i=3;
	while(1)
	{
		setvisualpage(page);
    	page=(page+1)%2;    
        setactivepage(page);
		setbkcolor(BLACK);
		cleardevice();
		settextstyle(DEFAULT_FONT,HORIZ_DIR,4);
		outtextxy(350,200,"Level 1");
		sprintf(tmp,"%d",i);
		outtextxy(350,300,tmp);
		i--;
		_sleep(1000);
		if(i==0)
			break;
	}
	for(i=0;i<60;i++){ 
		x[i]=rand()%3;
		if(x[i]==2)
			x[i]=11;
		} 
	for(i=60;i<100;i++){
		x[i]=rand()%2;
	}
}
void generate_lv2(int *x)//generate the map of lv2
{
	char tmp[20];
	int i=0,c=0;
	i=3;
	while(1)
	{
		setvisualpage(page);
    	page=(page+1)%2;    
        setactivepage(page);
		setbkcolor(BLACK);
		cleardevice();
		settextstyle(DEFAULT_FONT,HORIZ_DIR,4);
		outtextxy(350,200,"Level 2");
		sprintf(tmp,"%d",i);
		outtextxy(350,300,tmp);
		i--;
		_sleep(1000);
		if(i==0)
			break;
	}
	for(i=0;i<100;i++){
		if(c>30)
			x[i]=rand()%6;
		else
			x[i]=rand()%4;	
		if(x[i]==4)
			c-=30;	
		c=(c+10)%100;
	}
}
void generate_lv3(int *x)//generate the map of lv3
{
	char tmp[20];
	int i=0,c=0;
	i=3;
	while(1)
	{
		setvisualpage(page);
    	page=(page+1)%2;    
        setactivepage(page);
		setbkcolor(BLACK);
		cleardevice();
		settextstyle(DEFAULT_FONT,HORIZ_DIR,4);
		outtextxy(350,200,"Level 3");
		sprintf(tmp,"%d",i);
		outtextxy(350,300,tmp);
		i--;
		_sleep(1000);
		if(i==0)
			break;
	}
	for(i=0;i<200;i++){
		if(c>30)
			x[i]=rand()%9;
		else
			x[i]=rand()%4;	
		if(x[i]>=4)
			c-=30;	
		c=(c+10)%100;
	}
}

int level(int lev)   // input score
{
    int i;				//initialize the site
    for(i=0;i<8;i++)
        type[i]=0;
    for(i=0;i<8;i++)
        sit_x[i]=i*100;
    
    fx=310;			//initialize the figure data
    fy=0;
    flag_todown=0;
    flag_toup=0;
    power=0;
    speed=20;
    ai=0;
    
    switch(lev)		//determine the level
    {
    	case 1:
    		score=0;
    		generate_lv1(AI);
    		break;
    	case 2:
    		generate_lv2(AI);
    		break;
    	case 3:
    		generate_lv3(AI);
    		break;
    	case 4:
    		return level4();
    		break;
    }
    settextstyle(3,HORIZ_DIR,2);
	while(1){
		setvisualpage(page);		//change the page
    	page=(page+1)%3;    
        setactivepage(page);
               
        cleardevice();				//update the page
        
//generate the map---------------------------------------------------// 
        for(i=0;i<8;i++){//input map
			readimagefile(map[type[i]],sit_x[i],0,sit_x[i]+100,300);
		}								 
		for(i=0;i<8;i++){//update map
			sit_x[i]-=10;
			if(sit_x[i]==-100){
			sit_x[i]=700;
			type[i]=AI[ai];
			ai++;
			if(ai==100){
					x=level(lev+1);
					return x;
				}
			}
		}
		if(lev==3)
			readimagefile(saw[page_saw],0,35,50,265);			
		page_saw=-page_saw+1;

//------------------------------------------------------------//
//generate figure-------------------------------------------------//
	if(fy>=0&&flag_toup!=1&&flag_todown!=1&&power!=1)				//地面上 
			readimagefile(pic1[flag_run],fx,fy+215,fx+40,fy+265);
	if(fy<=-180&&flag_toup!=1&&flag_todown!=1&&power!=1)
			readimagefile(pic2[flag_run],fx,fy+215,fx+40,fy+265);
			
	if(GetAsyncKeyState(LEFT_KEY)!=0&&fx>0&&fy<=0&&fy>=-180)			//左右 
            fx-=10;
    if(GetAsyncKeyState(RIGHT_KEY)!=0&&fx<660&&fy<=0&&fy>=-180)
            fx+=10;	
			
	if(GetAsyncKeyState(UP_KEY)!=0&&fy==0&&power!=1)  //上升 
		      flag_toup=1;
	if(flag_toup==1&&power!=1&&flag_todown!=1)
			{		
				fy-=20;
				if((fy+240)>150)
                    readimagefile(pic1[flag_run],fx,fy+215,fx+40,fy+265);
				else if((fy+240)<=150)
					readimagefile(pic2[flag_run],fx,fy+215,fx+40,fy+265);
				if(fy<=-180){
					flag_toup=0;
					fy=-180;
				}
			}
			
	if(GetAsyncKeyState(DOWN_KEY)!=0&&fy==-180&&power!=1)  //下降 
		      flag_todown=1;
	if(flag_todown==1&&power!=1&&flag_toup!=1)
		{
			fy+=20;
			if((fy+240)<150)
				readimagefile(pic2[flag_run],fx,fy+215,fx+40,fy+265);
			if((fy+240)>=150)
				readimagefile(pic1[flag_run],fx,fy+215,fx+40,fy+265);
			if(fy>=0){
				flag_todown=0;
				fy=0;
			}
		}	
	flag_run=(++flag_run)%12;
	   
	if(GetAsyncKeyState(space_key)!=0&&energy>0&&use==0){//first press the spacekey 
		fy=-90;
		if(fx<=0)
			fx=10;
		}
	   
	if(GetAsyncKeyState(space_key)!=0&&energy>0){		//continue to press spacekey
	   	if((fy<-90&&fy>-180)||GetAsyncKeyState(UP_KEY)!=0)			
	   		back=1;												//determine go on or
	   	else if((fy>=-90&&fy<0)||GetAsyncKeyState(DOWN_KEY)!=0) //go down when don't 
	   		back=0;												//press the spacekey
		
        power=1;
        readimagefile(change[flag_jump],fx,fy+215,fx+50,fy+265);
        energy-=1;						//subtract the energy
        use=1;							
        speed=20;
        flag_jump=(++flag_jump)%20;
    	}
    else{
        if(use==1&&energy==0)					//判斷停止飛行的原因 
        	energy=-30;
		if(back==0&&use==1&&fy!=0&&fy!=-180){	//決定啟動向上向下 
			flag_todown=1;
			flag_toup=0;
		}
		else if(back==1&&use==1&&fy!=-180&&fy!=0){
			flag_toup=1;
			flag_todown=0; 
		}
        power=0;					//關閉飛行的狀態 
        use=0;
        speed=20;					
        energy+=2;					//回復能量 
	    if(energy>=201)
	    	energy=200;
	}
	if(use==1&&GetAsyncKeyState(UP_KEY)!=0&&fy>-180)//飛行的上下控制 
		fy-=8;
	if(use==1&&GetAsyncKeyState(DOWN_KEY)!=0&&fy<0)
		fy+=8;
//------------------------------------------------// 
//data---------------------------------//
	_sleep(speed);					//遊戲速度 
	
	for(i=0;i<blood;i++)
		readimagefile(blo,130+25*i,320,150+25*i,340);//印出血量 
	     
	setlinestyle(0,2,3);			//印出能量條 
	if(energy>120)
	    setfillstyle(1,10);
	else if(energy>80&&energy<120)
	   	setfillstyle(1,14);
	else 
	   	setfillstyle(1,12);
	
	if(energy<=0)
		bar_long=0;
	else
		bar_long=energy;
	
	bar(120,360,120+bar_long,380);
	setcolor(7);
	rectangle(120,360,320,380);
	setcolor(0);
	rectangle(118,358,322,382);
	
	score+=10;
	sprintf(s_sco,"%d",score);			//印出成績 
	setcolor(15);
	outtextxy(30,320,"BLOOD：");
	outtextxy(30,360,"ENERGY：");
	outtextxy(500,360,"SCORE：");
	outtextxy(600,360,s_sco);
//---------------------------------------//
	if(lev==3&&fx<=10)
		blood--;
//win or false-----------------------------//
	if(fy>=0&&flag_toup!=1&&flag_todown!=1)//沒有地板 
	{
        for(i=0;i<8;i++)
            if((fx+25>sit_x[i]+15)&&(fx+25<sit_x[i]+120))
                if(type[i]==1||type[i]==5){
            		//system("pause");
            		printf("*");
            		fy+=10; 
            		if(fy>=40){
            			fy=35;
            			return score;
            		}
            		if((fx+50==sit_x[i]+120)&&fy>0&&type[i+1]!=1&&type[i+1]!=5)
            			fx-=10;
				}else if(type[i]!=1&&type[i]!=5)
				{
					fy=0;
				}
    }
	if(fy<=-180&&flag_toup!=1&&flag_todown!=1)//沒有天空地板 
	{
        for(i=0;i<8;i++)
            if((fx+25>sit_x[i]+15||type[i]==5)&&(fx+25<sit_x[i]+120))
                if(type[i]==0||type[i]==5){
					//system("pause");
            		printf("*");
            		fy-=10; 
            		if(fy<=-220){
            			fy=-215;
            			return score;
            		}
            		if((fx+50==sit_x[i]+120)&&fy<-180&&type[i+1]!=0&&type[i+1]!=5)
            			fx-=10;
                }else if(type[i]!=0&&type[i]!=5)
				{
					fy=-180;
				}
            
    }
    if(fy>=-35)//踩到下刺 
	{
        for(i=0;i<8;i++)
            if((fx+25>sit_x[i]+15)&&(fx+25<sit_x[i]+120))
                if(type[i]==2||type[i]==4){
            		//system("pause");
            		printf("*");
            		blood--;
				}else if (fy>0&&(type[i]==0||type[i]==3||type[i]==6||type[i]==7||type[i]==8||type[i]==9||type[i]==10||type[i]==11)){
					fy=0;
				}
    }
	if(fy<=-145)//踩到上刺 
	{
        for(i=0;i<8;i++)
            if((fx+25>sit_x[i]+15)&&(fx+25<sit_x[i]+120))
                if(type[i]==3||type[i]==4){
					//system("pause");
            		printf("*");
            		blood--;
            		if(fy<-180)
            			fy=-180;
                }else if(fy<-180&&(type[i]==1||type[i]==2||type[i]==6||type[i]==7||type[i]==8||type[i]==9||type[i]==10||type[i]==11)){
                	fy=-180;
                } 
            
    }
//撞到牆-------------------------------------// 
    if((fy>=-125)||(fy<=-165)) 
	{
        for(i=0;i<8;i++)
            if((fx+40>sit_x[i]+38)&&(fx+40<sit_x[i]+53))
                if(type[i]==6){
            		//system("pause");
            		printf("*");
            		fx-=10;
					wall[i]=1; 
				}else{
					wall[i]=0;
				}
    }
    if((fy>=-95)||(fy<=-145))
	{
        for(i=0;i<8;i++)
            if((fx+40>sit_x[i]+38)&&(fx+40<sit_x[i]+53))
                if(type[i]==7){
            		//system("pause");
            		printf("*");
            		fx-=10;
            		wall[i]=1; 
				}else{
					wall[i]=0;
				}
    }
    if((fy>=-65)||(fy<=-115))
	{
        for(i=0;i<8;i++)
            if((fx+40>sit_x[i]+38)&&(fx+40<sit_x[i]+53))
                if(type[i]==8){
            		//system("pause");
            		printf("*");
            		fx-=10;
					wall[i]=1; 
				}else{
					wall[i]=0;
				}
    }
    if((fy>=-35)||(fy<=-85))
	{
        for(i=0;i<8;i++)
            if((fx+40>sit_x[i]+38)&&(fx+40<sit_x[i]+53))
                if(type[i]==9){
            		//system("pause");
            		printf("*");
            		fx-=10;
					wall[i]=1; 
				}else{
					wall[i]=0;
				}
    }
    if((fy>=-15)||(fy<=-55))
	{
        for(i=0;i<8;i++)
            if((fx+40>sit_x[i]+38)&&(fx+40<sit_x[i]+53))
                if(type[i]==10){
            		//system("pause");
            		printf("*");
            		fx-=10;
					wall[i]=1; 
				}else{
					wall[i]=0;
				}
    }
    
    if(blood<=0)
    	return score;
    if(score%1110==0){
    	blood++;
    	if(blood>20)blood=20;
    }
//-------------------------------------------------------//   
	} 
	delete [] s_sco;
}
void generate_lv4(int *x)
{
	char tmp[20];
	int i=0,c;
	i=3;
	while(1)
	{
		setvisualpage(page);
    	page=(page+1)%2;    
        setactivepage(page);
		setbkcolor(BLACK); 
		cleardevice();
		settextstyle(DEFAULT_FONT,HORIZ_DIR,4);
		outtextxy(350,200,"Level 4");
		sprintf(tmp,"%d",i);
		outtextxy(350,300,tmp);
		i--;
		_sleep(1000);
		if(i==0)
			break;
	}
	x[0]=8;
	for(i=1;i<100;i++){
		c=rand()%3;
		if(c==0)
			x[i]=x[i-1];
		else if(c==1&&x[i-1]>6)
			x[i]=x[i-1]-1;
		else if(c==1&&x[i-1]==6)
			x[i]=x[i-1]+1;	
		else if(c==2&&x[i-1]<10)
			x[i]=x[i-1]+1;
		else if(c==2&&x[i-1]==10)
			x[i]=x[i-1]-1;
	}
}
int level4()
{
	int i;
    for(i=0;i<8;i++)
        type[i]=0;
    for(i=0;i<8;i++)
        sit_x[i]=i*100;
    fx=610;
    fy=0;
    flag_todown=0;
    flag_toup=0;
    power=0;
    energy=200;
    speed=20;
    ai=0;
	generate_lv4(AI);
	settextstyle(3,HORIZ_DIR,2);
	while(1){
		setvisualpage(page);
    	page=(page+1)%3;    
        setactivepage(page);
               
        cleardevice();
//generate the map-----------------------------------------------------//        
		for(i=0;i<8;i++){
			readimagefile(map[type[i]],sit_x[i],0,sit_x[i]+100,300);
		}								 
		for(i=0;i<8;i++){
			sit_x[i]-=10;
			if(sit_x[i]==-100){
				sit_x[i]=700;
				type[i]=AI[ai];
				ai++;
				if(ai==100)
					return score;
				}
		}
		readimagefile(saw[page_saw],0,35,50,265);			
		page_saw=-page_saw+1;
//---------------------------------------------------//
//generate figure-------------------------------------------------//
	if(fy>=0&&flag_toup!=1&&flag_todown!=1&&power!=1)
			readimagefile(pic1[flag_run],fx,fy+215,fx+40,fy+265);
	if(fy<=-180&&flag_toup!=1&&flag_todown!=1&&power!=1)
			readimagefile(pic2[flag_run],fx,fy+215,fx+40,fy+265);

    if(GetAsyncKeyState(LEFT_KEY)!=0&&fx>0&&fy<=0&&fy>=-180&&wall[0]==0&&wall[1]==0&&wall[2]==0&&wall[3]==0&&wall[4]==0&&wall[5]==0&&wall[6]==0&&wall[7]==0)			//左右 
            fx-=10;
    if(GetAsyncKeyState(RIGHT_KEY)!=0&&fx<660&&fy<=0&&fy>=-180&&wall[0]==0&&wall[1]==0&&wall[2]==0&&wall[3]==0&&wall[4]==0&&wall[5]==0&&wall[6]==0&&wall[7]==0)
            fx+=10;	
			
	if(GetAsyncKeyState(UP_KEY)!=0&&fy>=0&&power!=1)  //上 
		      flag_toup=1;
	if(flag_toup==1&&power!=1&&flag_todown!=1)
			{		
				fy-=15;
				if((fy+240)>150)
                    readimagefile(pic1[flag_run],fx,fy+215,fx+40,fy+265);
				else if((fy+240)<=150)
					readimagefile(pic2[flag_run],fx,fy+215,fx+40,fy+265);
				if(fy<=-180){
					fy=-180;
					flag_toup=0;
				}
			}
			
	if(GetAsyncKeyState(DOWN_KEY)!=0&&fy<=-180&&power!=1)  //下 
		      flag_todown=1;
	if(flag_todown==1&&power!=1&&flag_toup!=1)
		{
			fy+=15;
			if((fy+240)<150)
				readimagefile(pic2[flag_run],fx,fy+215,fx+40,fy+265);
			if((fy+240)>=150)
				readimagefile(pic1[flag_run],fx,fy+215,fx+40,fy+265);
			if(fy>=0){
				fy=0;
				flag_todown=0;					
			}
		}	
	flag_run=(++flag_run)%12;
	   
	if(GetAsyncKeyState(space_key)!=0&&energy>0&&use==0){//first press the spacekey 
		fy=-90;
		}  
	if(GetAsyncKeyState(space_key)!=0){
	   	if((fy<-90&&fy>-180)||GetAsyncKeyState(UP_KEY)!=0)
	   		back=1;
	   	else if((fy>=-90&&fy<0)||GetAsyncKeyState(DOWN_KEY)!=0)
	   		back=0;
        power=1;
        readimagefile(change[flag_jump],fx,fy+215,fx+50,fy+265);
        use=1;
        speed=20;
        flag_jump=(++flag_jump)%20;
    	}
    else{
		if(back==0&&use==1&&fy!=0&&fy!=-180){
			flag_todown=1;
			flag_toup=0;
		}
		else if(back==1&&use==1&&fy!=-180&&fy!=0){
			flag_toup=1;
			flag_todown=0; 
		}
        power=0;
        use=0;
        speed=20;
	}
	if(use==1&&GetAsyncKeyState(UP_KEY)!=0&&fy>-180)
		fy-=8;
	if(use==1&&GetAsyncKeyState(DOWN_KEY)!=0&&fy<0)
		fy+=8;
//------------------------------------------------// 
//data---------------------------------//
	_sleep(speed);
	
	for(i=0;i<blood;i++)
		readimagefile(blo,130+25*i,320,150+25*i,340);
	     
	setlinestyle(0,2,3);
	setfillstyle(1,10);
	bar_long=energy;
	
	bar(120,360,120+bar_long,380);
	setcolor(7);
	rectangle(120,360,320,380);
	setcolor(0);
	rectangle(118,358,322,382);
	
	score+=10;
	sprintf(s_sco,"%d",score);
	setcolor(15);
	outtextxy(30,320,"BLOOD：");
	outtextxy(30,360,"ENERGY：");
	outtextxy(500,360,"SCORE：");
	outtextxy(600,360,s_sco);
//---------------------------------------//
//win or false-----------------------------//
	if(fx<=10)
		blood--;
//撞到牆-------------------------------------// 
    if((fy>=-125)||(fy<=-165)) 
	{
        for(i=0;i<8;i++)
            if((fx+40>sit_x[i]+38)&&(fx+40<sit_x[i]+53))
                if(type[i]==6){
            		//system("pause");
            		printf("*");
            		fx-=10;
					wall[i]=1; 
				}else{
					wall[i]=0;
				}
    }
    if((fy>=-95)||(fy<=-145))
	{
        for(i=0;i<8;i++)
            if((fx+40>sit_x[i]+38)&&(fx+40<sit_x[i]+53))
                if(type[i]==7){
            		//system("pause");
            		printf("*");
            		fx-=10;
            		wall[i]=1; 
				}else{
					wall[i]=0;
				}
    }
    if((fy>=-65)||(fy<=-115))
	{
        for(i=0;i<8;i++)
            if((fx+40>sit_x[i]+38)&&(fx+40<sit_x[i]+53))
                if(type[i]==8){
            		//system("pause");
            		printf("*");
            		fx-=10;
					wall[i]=1; 
				}else{
					wall[i]=0;
				}
    }
    if((fy>=-35)||(fy<=-85))
	{
        for(i=0;i<8;i++)
            if((fx+40>sit_x[i]+38)&&(fx+40<sit_x[i]+53))
                if(type[i]==9){
            		//system("pause");
            		printf("*");
            		fx-=10;
					wall[i]=1; 
				}else{
					wall[i]=0;
				}
    }
    if((fy>=-15)||(fy<=-55))
	{
        for(i=0;i<8;i++)
            if((fx+40>sit_x[i]+38)&&(fx+40<sit_x[i]+53))
                if(type[i]==10){
            		//system("pause");
            		printf("*");
            		fx-=10;
					wall[i]=1; 
				}else{
					wall[i]=0;
				}
    }
    
    if(blood<=0)
    	return score;
    if(score%1110==0){
    	blood++;
    	if(blood>20)blood=20;
    }
//-------------------------------------------------------// 	
	}	
	delete [] s_sco;	
}
/*int main()
{
	srand(time(NULL));	
    initwindow(700,400);
    int op=1,op1;
    
    scanf("%d",&op);
    
    op1=level(op);
    switch(op)
    {
        case 1:
            op1=level1();
            break;
        case 2:
            op1=level2();
            break;
        case 3:
			op1=level3();
			break;
		case 4:
			op1=level4();
			break; 
        case 5:
            exit(1);
    }

	getchar();
	
	//delete [] s_sco;
	closegraph();
	return 0;		
}*/
