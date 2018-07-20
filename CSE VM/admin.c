#include "header.h"

void password()
{
    disp();
    int x=0;
    char p[10]="open";
    char pa[10],ch;
    printf("\n\tEnter Password : ");
    while((ch=getch())!=13)
    {
        printf("*");
        pa[x]=ch;
        x++;
    }
    pa[x]='\0';
    if(strcmp(pa,p)==0)
    {
        printf("\n\n\tPassword Correct . \n\t\tRedirecting to Admin Panel ");
        int k;
        for(k=0;k<5;k++)
        {
            printf(". ");
            Sleep(600);
        }
        ad_pan();
    }

    else
    {
        printf("\n\n\tYou have entered wrong password . \n\t\tRedirecting to Main Menu ");
        int k;
        for(k=0;k<5;k++)
        {
            printf(". ");
            Sleep(600);
        }
        mainmenu();
    }
}

void ad_pan()
{
    disp_ad();
    printf("\n\t\t1. Voter List\n\t\t2. Edit Voter List\n\t\t3. Candidate List\n\t\t4. Edit Candidate List\n\t\t5. Vote Timer\n\t\t6. Vote Count\n\t\t7. Vote List\n\t\t8. Main Menu\n\t-----------------------------------------------------\n\t\tEnter Choice : ");
    switch(getch())
    {
    case '1':
        vtlist();
        break;
    case '2':
        editvl();
        break;
    case '3':
        can_list();
        break;
    case '4':
        cmodify();
        break;
    case '5':
            vtimer();
        break;
    case '6':
        vcounter();
        break;
    case '7':
        vlist();
        break;
    case '8':
        mainmenu();
        break;
    default :
        printf("\n\n\t\t Wrong Input . Please Wait ....");
        Sleep(500);
        ad_pan();
        break;
    }
}

void vtlist()
{
    int i=5,j,cnt=0;
    FILE *vl;
    disp_ad();
    printf("\t\t\t\t\t       Voter List\n\t\t\t\t\t--------------------------");
    vl=fopen("vdata.cfile","rb+");
    gotoxy(5,8);
    printf("Name");
    gotoxy(25,8);
    printf("Father");
    gotoxy(45,8);
    printf("Mother");
    gotoxy(65,8);
    printf("NID");
    gotoxy(75,8);
    printf("Phone");
    gotoxy(90,8);
    printf("Blood G.");
    gotoxy(100,8);
    printf("Address");
    gotoxy(0,9);
    printf("\t\t-----------------------------------------------------------------------------------");
    j=11;
    while(fread(&vdetails,sizeof(vdetails),1,vl)==1)
    {
        i=5;
        gotoxy(i,j);
        printf("%s",vdetails.name);
        i+=20;
        gotoxy(i,j);
        printf("%s",vdetails.fname);
        i+=20;
        gotoxy(i,j);
        printf("%s",vdetails.mname);
        i+=20;
        gotoxy(i,j);
        printf("%s",vdetails.id);
        i+=10;
        gotoxy(i,j);
        printf("%s",vdetails.phn);
        i+=15;
        gotoxy(i,j);
        printf("  %s",vdetails.bg);
        i+=10;
        gotoxy(i,j);
        printf("%s",vdetails.addr);
        j++;
        cnt++;
    }
    gotoxy(0,j+1);
    printf("\tTotal Voter : %d",cnt);
    fclose(vl);
    getch();
    ad_pan();
}

void editvl()
{
    disp_ad();
    printf("\t\t1. Add New Voter\n\n\t\t2. Delete Voter\n\n\t\t3. Back\n\n\t-----------------------------------------------\n\t\tEnter Choice : ");
    switch(getch())
    {
    case '1':
        addvoter();
        break;
    case '2':
        dvoter();
        break;
    case '3':
        ad_pan();
        break;
    }
}

void addvoter()
{
    disp_ad();
    FILE *fp;
    printf("\n\tName : ");
    scanf("%[^\n]%*c",vdetails.name);
    printf("\n\tFather's Name : ");
    scanf("%[^\n]%*c",vdetails.fname);
    printf("\n\tMother's Name : ");
    scanf("%[^\n]%*c",vdetails.mname);
    printf("\n\tBlood Group : ");
    scanf("%[^\n]%*c",vdetails.bg);
    printf("\n\tNational ID No. : ");
    scanf("%[^\n]%*c",vdetails.id);
    printf("\n\tPhone Number : ");
    scanf("%[^\n]%*c",vdetails.phn);
    printf("\n\tAddress : ");
    scanf("%[^\n]%*c",vdetails.addr);
    fp=fopen("vdata.cfile","rb+");
    fseek(fp,0,SEEK_END);
    fwrite(&vdetails,sizeof(vdetails),1,fp);
    fclose(fp);
    printf("\n\n\tThe record is sucessfully saved");
    printf("\n\n\tSave any more?(Y / N):");
    if(getch()=='n'){
        ad_pan();
    }
    else    {
        addvoter();
    }
}

void dvoter()
{
    disp_ad();
    int c=0;
    FILE *fp;
    FILE *fn;
    fn=fopen("test.cfile","wb+");
    fclose(fn);
    char nid[15];
    while(1)
    {
    printf("\n\tEnter Voter ID to delete : ");
    scanf("%[^\n]%*c",nid);
    fp=fopen("vdata.cfile","rb+");
    rewind(fp);
    while(fread(&vdetails,sizeof(vdetails),1,fp)==1)
    {
        if(strcmp(nid,vdetails.id)==0)
        {
            printf("\n\t\tName : %s\n\t\tFather Name : %s\n\t\tMother Name : %s\n\t\tBlood Group : %s\n\t\tMobile No : %s\n\t\tAddress : %s",vdetails.name,vdetails.fname,vdetails.mname,vdetails.bg,vdetails.phn,vdetails.addr);
            c=1;
        }
    }
    if(c==0)
    {
        printf("\n\t\tVoter Not Found\n\n\t\tPress Any Key To Go Back To Admin Panel");
        getch();
        ad_pan();
    }
    else
    {
        printf("\n\n\tDo you want to delete it ? (Y/N)");
        char ch;
        ch=getch();
        if(ch=='y' || ch=='Y')
        {
            fn=fopen("test.cfile","ab+");
            rewind(fp);
            while(fread(&vdetails,sizeof(vdetails),1,fp)==1)
            {
                if(strcmp(nid,vdetails.id)!=0)
                {
                    fseek(fn,0,SEEK_CUR);
                    fwrite(&vdetails,sizeof(vdetails),1,fn);
                }
            }
            fclose(fn);
            fclose(fp);
            remove("vdata.cfile");
            rename("test.cfile","vdata.cfile");
            fp=fopen("vdata.cfile","rb+");
            printf("\nVoter Deleted");
        }
    }
    break;
    }
    fflush(stdin);
    printf("\n\t\tDo you want to delete any more data ? (Y/N)");
    char cc;
    cc=getch();
    if(cc=='y' || cc=='Y')
        dvoter();
    else
        ad_pan();
}

void can_list()
{
    FILE *fp;
    int i=0;
    fp=fopen("cdata.cfile","rb+");
    disp_ad();
    while(fread(&clist,sizeof(clist),1,fp)==1)
    {
        i++;
        printf("\n\tSl :%d\tName : %s\tSign : %s\tCode : %d \tAge : %d yrs\n",i,clist.name,clist.sign,clist.code,clist.age);
    }
    if(i==0)
        printf("\n\t\tCandidate List Empty\n\tPress any key to continue . . ");
    getch();
    ad_pan();
}

void cmodify()
{

    disp_ad();
    printf("\n\t1. Create New List\n\t2. Eliminate Candidate From List");
    switch(getch())
    {
    case '1':
        ccand();
        break;
    case '2':
        dcand();
        break;
    default:
        ad_pan();
        break;
    }
}
void vtimer()
{
    disp_ad();
    FILE *fg;
    if(timer==0)
    {
        printf("\n\n\tDo you want to start voting session ?(If  you close this program then timer will automatically stop)");
        printf("\n\n\t\t1. Start\n\t\t2. Admin Panel\n\t---------------------------------------------------\n\t\tYour Choice : ");
        switch(getch())
        {
            case '1':
                fg=fopen("cache.cfile","wb+");
                fclose(fg);
                timer=1;checker=1;
                printf("\n\tSession Started . Press any key for Admin Panel ");
                getch();
                ad_pan();
            default:printf("\n\tGoing bank to Admin Panel");Sleep(1500);ad_pan();
        }
    }
    else
    {
        printf("\n\n\tDo you want to stop voting session ?(If  you close this program then timer will automatically stop)");
        printf("\n\n\t\t1. Stop\n\t\t2. Admin Panel\n\t---------------------------------------------------\n\t\tYour Choice : ");
        switch(getch())
        {
            case '1':timer=0;checker=0;printf("\n\tSession Stopped . Press any key for Admin Panel ");getch();ad_pan();
            default:printf("\n\tGoing bank to Admin Panel");Sleep(1500);ad_pan();
        }
    }
}


void vcounter()
{
    disp_ad();
    if(checker==1)
    {
        FILE *fp;
        struct candidate_list temp;
        int x,y=9;
        fp=fopen("cdata.cfile","rb+");
        int count=0,win=0;
        gotoxy(5,7);
        printf("Code");
        gotoxy(20,7);
        printf("Name");
        gotoxy(35,7);
        printf("Sign");
        gotoxy(50,7);
        printf("Votes");
        gotoxy(0,8);
        printf("--------------------------------------------------------------------------------------");

        while(fread(&clist,sizeof(clist),1,fp)==1)
        {
            x=5;
            gotoxy(x,y);
            printf("%d",clist.code);
            x+=15;
            gotoxy(x,y);
            printf("%s",clist.name);
            x+=15;
            gotoxy(x,y);
            printf("%s",clist.sign);
            x+=15;
            gotoxy(x,y);
            printf("%d",clist.vote);
            x+=15;
            y++;
            count=count+clist.vote;
            if(clist.vote>win)
                temp=clist;
        }
        gotoxy(10,y+1);
        printf("Total Votes : %d",count);
        if(count!=0)
        {
        printf("\n\n\t\t===================WINNER===================\n");
        printf("\n\t\tName : %s\n\t\tSign : %s\n\t\tCode : %d\n\t\tTotal Votes : %d",temp.name,temp.sign,temp.code,temp.vote);
        }
        printf("\n\n\tPress any key to continue . . .");
        getch();
        ad_pan();
    }
    else
    {
        printf("\n\tNo Election held yet .\nYou are redirecting to Admin Panel ...");
        Sleep(1500);
        ad_pan();
    }
}

void vlist()
{
    disp_ad();
    FILE *fp;
    fp=fopen("cache.cfile","rb+");
    if(fp!=NULL)
    {
        int x=5,y=7;
        gotoxy(5,7);
        printf("Voter Name");
        gotoxy(30,7);
        printf("Voter NID");
        gotoxy(55,7);
        printf("Candidate Sign");
        gotoxy(85,7);
        printf("Candidate Code");
        gotoxy(0,8);
        printf("--------------------------------------------------------------------------------------------");

        while(fread(&clist,sizeof(clist),1,fp)==1)
        {
            x=5;
            gotoxy(x,y);
            printf("%d",clist.code);
            x+=25;
            gotoxy(x,y);
            printf("%s",clist.name);
            x+=25;
            gotoxy(x,y);
            printf("%s",clist.sign);
            x+=30;
            gotoxy(x,y);
            printf("%d",clist.vote);
            y++;
        }
    }
    else
    {
        printf("\n\n\tNo data Found. Press any key to continue. . . ");
        getch();
        ad_pan();
    }
}

void dcand()
{
    disp_ad();
        FILE *fn;
        FILE *fp;
        char name[50],sgn[50],a;
        int x=0,code;
        while(1)
        {
            fp=fopen("cdata.cfile","rb+");
            fn=fopen("cn.cfile","wb+");
            fflush(stdin);
            printf("\n\tCandidate Name : ");
            scanf("%[^\n]%*c",name);
            printf("\n\tCandidate Sign : ");
            scanf("%[^\n]%*c",sgn);
            printf("\n\tCandidate code : ");
            scanf("%d",&code);
            rewind(fp);
            while(fread(&clist,sizeof(clist),1,fp)==1)
            {
                if(strcmp(sgn,clist.sign)==0 && code==clist.code)
                {
                    printf("\n\t\tCandidate Name : %s\n\t\tCandidate Sign : %s\n\tCandidate Code : %d\n\t\tCandidate Age : %d",clist.name,clist.sign,clist.code,clist.age);
                    x=1;
                }
            }
            if(x==1)
            {
                rewind(fp);
                while(fread(&clist,sizeof(clist),1,fp)==1)
                {
                    if(strcmp(sgn,clist.sign)!=0 && code!=clist.code)
                    {
                        fseek(fn,0,SEEK_CUR);
                        fwrite(&clist,sizeof(clist),1,fn);
                    }
                }
                fclose(fp);
                fclose(fn);
                remove("cdata.cfile");
                rename("cn.cfile","cdata.cfile");
                printf("\n\tDeletion Successful .");
            }
            else
                printf("\n\tCandidate Not Found");
            printf("\n\tDo you want to delete more ? (Y/N)");
            a=getch();
            if(a=='n' || a=='N') break;
        }
        ad_pan();
}
void ccand()
{
    FILE *fp;
        disp_ad();
        fp=fopen("cdata.cfile","wb+");
        fclose(fp);
        fp=fopen("cdata.cfile","rb+");
        while(1)
        {
            printf("\n\tCandidate Name : ");
            scanf("%[^\n]%*c",clist.name);
            printf("\n\tCandidate Sign : ");
            scanf("%[^\n]%*c",clist.sign);
            printf("\n\tCandidate Code : ");
            scanf("%d",&clist.code);
            printf("\n\tCandidate Age : ");
            scanf("%d",&clist.age);
            clist.vote=0;
            fseek(fp,0,SEEK_END);
            fwrite(&clist,sizeof(clist),1,fp);
            printf("\n\tCandidate added. Do you want to add more ? (Y/N) ");
            char c;
            c=getch();
            if(c=='n' || c=='N')
                break;
            fflush(stdin);
        }
        fclose(fp);
        ad_pan();
}
