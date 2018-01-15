#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<string.h>

#define A_KEY 0x41
#define B_KEY 0x42
#define C_KEY 0x43
#define D_KEY 0x44
#define E_KEY 0x45
#define F_KEY 0x46
#define G_KEY 0x47
#define H_KEY 0x48
#define I_KEY 0x49
#define J_KEY 0x4A
#define K_KEY 0x4B
#define L_KEY 0x4C
#define M_KEY 0x4D
#define N_KEY 0x4E
#define O_KEY 0x4F
#define P_KEY 0x50
#define Q_KEY 0x51
#define R_KEY 0x52
#define S_KEY 0x53
#define T_KEY 0x54
#define U_KEY 0x55
#define V_KEY 0x56
#define W_KEY 0x57
#define X_KEY 0x58
#define Y_KEY 0x59
#define Z_KEY 0x5A
#define BS_KEY 0x08
#define EN_KEY 0x0D

struct RANK
{
	char name[10],ra[10],reco[10];
}p[10],k;
FILE *fp;
char win[10],tm[10];
int io=0,rankpage=0,number,t,ch=0;

int showrank()
{
	if((fp=fopen("record.dat","rb"))==NULL)
		printf("ERROR");	
	/*for(i=0;i<10;i++){
		printf("%d",i);
		itoa(i+1,tm,10);
		strcpy(k.ra,"No.");
		strcat(k.ra,tm);
		strcpy(k.name,"*****\0");
		strcpy(k.reco,"00000\0");
		fwrite(&k,sizeof(RANK),1,fp);
		}
	fclose(fp);*/
	io=0;
	while(!feof(fp)&&fread(&p[io],sizeof(RANK),1,fp)&&io<10){
		io++;
		}
	while(1)
	{
		setvisualpage(rankpage);
    	rankpage=-rankpage+1;    
        setactivepage(rankpage);
		cleardevice();
		settextstyle(7,HORIZ_DIR, 7);
		outtextxy(220,30,"RANK");
		settextstyle(10,HORIZ_DIR, 3);
		for(io=0;io<5;io++)
		{
		outtextxy(30,100+50*io,p[io].ra);
		outtextxy(110,100+50*io,p[io].name);
		outtextxy(250,100+50*io,p[io].reco);
		}
		for(io=0;io<5;io++)
		{
		outtextxy(380,100+50*io,p[io+5].ra);
		outtextxy(460,100+50*io,p[io+5].name);
		outtextxy(600,100+50*io,p[io+5].reco);
		}
		if(mousex()>400&&mousey()>350&&mousex()<650&&mousey()<390){
		settextstyle(7,HORIZ_DIR, 4);
		outtextxy(400,350,"RETURN>>");
		if(ismouseclick(WM_LBUTTONDOWN)){
			fclose(fp);
			return 0;
			} 
		}else{
		settextstyle(10,HORIZ_DIR, 4);
		outtextxy(400,350,"RETURN>>");
		}
	}
}
void entername()
{
	strcpy(win,"\0");
	while(1)
	{
	setvisualpage(rankpage);
    rankpage=-rankpage+1;    
    setactivepage(rankpage);
	cleardevice();
	settextstyle(6,HORIZ_DIR, 5);
	outtextxy(120,80,"NEW RECORD!!!");
	settextstyle(6,HORIZ_DIR, 3);
	outtextxy(240,180,"YOUR NAME¡G");
	line(150,300,550,300);
	settextstyle(1,HORIZ_DIR,4);
	
	if(GetAsyncKeyState(A_KEY)!=0&&strlen(win)<=9) {strncat(win,"A",1);} 
	if(GetAsyncKeyState(B_KEY)!=0&&strlen(win)<=9) {strncat(win,"B",1);}
	if(GetAsyncKeyState(C_KEY)!=0&&strlen(win)<=9) {strncat(win,"C",1);}
	if(GetAsyncKeyState(D_KEY)!=0&&strlen(win)<=9) {strncat(win,"D",1);}
	if(GetAsyncKeyState(E_KEY)!=0&&strlen(win)<=9) {strncat(win,"E",1);}
	if(GetAsyncKeyState(F_KEY)!=0&&strlen(win)<=9) {strncat(win,"F",1);}
	if(GetAsyncKeyState(G_KEY)!=0&&strlen(win)<=9) {strncat(win,"G",1);}
	if(GetAsyncKeyState(H_KEY)!=0&&strlen(win)<=9) {strncat(win,"H",1);}
	if(GetAsyncKeyState(I_KEY)!=0&&strlen(win)<=9) {strncat(win,"I",1);}
	if(GetAsyncKeyState(J_KEY)!=0&&strlen(win)<=9) {strncat(win,"J",1);}
	if(GetAsyncKeyState(K_KEY)!=0&&strlen(win)<=9) {strncat(win,"K",1);}
	if(GetAsyncKeyState(L_KEY)!=0&&strlen(win)<=9) {strncat(win,"L",1);}
	if(GetAsyncKeyState(M_KEY)!=0&&strlen(win)<=9) {strncat(win,"M",1);}
	if(GetAsyncKeyState(N_KEY)!=0&&strlen(win)<=9) {strncat(win,"N",1);}
	if(GetAsyncKeyState(O_KEY)!=0&&strlen(win)<=9) {strncat(win,"O",1);}
	if(GetAsyncKeyState(P_KEY)!=0&&strlen(win)<=9) {strncat(win,"P",1);}
	if(GetAsyncKeyState(Q_KEY)!=0&&strlen(win)<=9) {strncat(win,"Q",1);}
	if(GetAsyncKeyState(R_KEY)!=0&&strlen(win)<=9) {strncat(win,"R",1);}
	if(GetAsyncKeyState(S_KEY)!=0&&strlen(win)<=9) {strncat(win,"S",1);}
	if(GetAsyncKeyState(T_KEY)!=0&&strlen(win)<=9) {strncat(win,"T",1);}
	if(GetAsyncKeyState(U_KEY)!=0&&strlen(win)<=9) {strncat(win,"U",1);}
	if(GetAsyncKeyState(V_KEY)!=0&&strlen(win)<=9) {strncat(win,"V",1);}
	if(GetAsyncKeyState(W_KEY)!=0&&strlen(win)<=9) {strncat(win,"W",1);}
	if(GetAsyncKeyState(X_KEY)!=0&&strlen(win)<=9) {strncat(win,"X",1);}
	if(GetAsyncKeyState(Y_KEY)!=0&&strlen(win)<=9) {strncat(win,"Y",1);}
	if(GetAsyncKeyState(Z_KEY)!=0&&strlen(win)<=9) {strncat(win,"Z",1);}
	if(GetAsyncKeyState(BS_KEY)!=0&&strlen(win)<=10) {memmove(win+strlen(win)-1,"\0",1);}
	if(GetAsyncKeyState(EN_KEY)!=0&&strlen(win)<=10) {memmove(win+strlen(win),"\0",1);break;}
	
	outtextxy(165,260,win);
	
	_sleep(100);
	}
} 
void updaterank(int ss)
{
	RANK tt; 
	int i,j,p1,p2;
	
	if((fp=fopen("record.dat","r+b"))==NULL)
		printf("ERROR");
	i=0;
	while(!feof(fp)&&fread(&p[i],sizeof(RANK),1,fp)&&i<10){
		i++;
		}
	number=atoi(p[9].reco);
	if(number<ss)
	{
		itoa(ss,p[9].reco,10);
		entername();
		strcpy(p[9].name,win);
	}
	//sort
	for(i=0;i<9;i++)
		for(j=i+1;j<10;j++)
		{
			p1=atoi(p[i].reco);
			p2=atoi(p[j].reco);
			if(p1<p2)
			{
				tt=p[i];
				p[i]=p[j];
				p[j]=tt;
			}
		}
	
	for(i=0;i<10;i++)
	{
		//printf("%s %s\n",p[i].name,p[i].reco);
		itoa(i+1,tm,10);
		strcpy(p[i].ra,"No.");
		strcat(p[i].ra,tm);
		fseek(fp,sizeof(RANK)*(i),SEEK_SET);
		fwrite(&p[i],sizeof(RANK),1,fp);
	}
	fclose(fp);
}
/*int main()
{
	initwindow(700,400);
	int x;
	
	//entername();

	
	updaterank(210);

	x=showrank();
	closegraph();
	return 0;
}*/
