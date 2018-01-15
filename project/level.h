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
void generate_lv1(int *x);
void generate_lv2(int *x);
void generate_lv3(int *x);
void generate_lv4(int *x);
