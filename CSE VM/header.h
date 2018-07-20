#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<dos.h>
#include<windows.h>
#include<time.h>

struct vt_det
{
    char name[50],fname[50],mname[50],bg[5],id[20],phn[15],addr[100];
}vdetails;

struct candidate_list
{
    char name[50],sign[50];
    int age,code,vote;
}clist;

struct voterdet
{
    char name[50],id[20],csign[20];
    int code;
}cache;

int timer;
int checker;

void disp();
void gotoxy();
int mainmenu();
void password();
void ad_pan();
void disp_ad();
void disp_v();
void vtlist();
void editvl();
void addvoter();
void dvoter();
void can_list();
void cmodify();
void vmenu();
void vtimer();
void vcounter();
void vlist();
void dcand();
void ccand();
