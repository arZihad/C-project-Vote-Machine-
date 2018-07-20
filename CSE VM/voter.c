#include "header.h"

void vmenu()
{
    disp_v();
    if(timer==1)
    {
        int chk=0;

        char name[50],id[20],phn[15];
        struct candidate_list temp,temp2;
        printf("\t(Note : All of your input is case sensitive)\n");
        printf("\n\tName : ");
        scanf(" %[^\n]%*c",name);
        printf("\n\tID No : ");
        scanf("%[^\n]%*c",id);
        printf("\n\tPhone Number : ");
        scanf("%[^\n]%*c",phn);
        FILE *fp;
        fp=fopen("vdata.cfile","rb+");
        while(fread(&vdetails,sizeof(vdetails),1,fp)==1)
        {
            if(strcmp(id,vdetails.id)==0)
            {
                chk=1;
                break;
            }
        }
        if(chk==0)
        {
            printf("\n\n\tYour details not found in voter database.\n\n\t\tYou are redirecting to Mainmenu ");
            int i;
            for(i=0;i<5;i++)
            {
                printf(". ");
                Sleep(500);
            }
            mainmenu();
        }
        else
        {
            FILE *ff;
            ff=fopen("cdata.cfile","rb+");
            int sl=1;
            while(fread(&clist,sizeof(clist),1,ff)==1)
            {
                printf("\n\tSl : %d\n\tName : %s\n\tSign : %s\n\tCode : %d",sl,clist.name,clist.sign,clist.code);
                sl++;
            }
            printf("\n\n\tYou have enter candidate sign & code for submit vote ->>\n");
            char sgn[20];int code;
            printf("\n\t\tSign : ");
            scanf(" %[^\n]%*c",sgn);
            printf("\n\t\tCode : ");
            scanf("%d",&code);
            rewind(ff);
            while(fread(&clist,sizeof(clist),1,ff)==1)
            {
                if(strcmp(sgn,clist.sign)==0 && code==clist.code)
                {
                    printf("\n\t\tCandidate Name : %s\n\t\tCandidate Sign : %s\n\tCandidate Code : %d\n\t\tCandidate Age : %d\n",clist.name,clist.sign,clist.code,clist.age);
                    break;
                }
            }
            printf("Do you want to vote this person ?(Y/N)");
            switch(getch())
            {
                case 'y':;
                case 'Y':goto votin;break;
                default:
                    printf("\nTry again ! You are redirecting to Mainmenu . . .");
                    Sleep(1500);
                    mainmenu();
            }
            votin:
            clist.vote++;
            temp=clist;
            FILE *fg,*fl;
            fl=fopen("cache.cfile","rb+");
            fseek(fl,0,SEEK_CUR);
            strcpy(cache.name,vdetails.name);
            strcpy(cache.id,vdetails.id);
            strcpy(cache.csign,clist.sign);
            cache.code=clist.code;
            fwrite(&cache,sizeof(cache),1,fl);
            fclose(fl);
            fg=fopen("tempf.cfile","wb+");
            rewind(ff);
            while(fread(&clist,sizeof(clist),1,ff)==1)
            {
                if(strcmp(sgn,clist.sign)!=0 && code!=clist.code)
                {
                    fseek(fg,0,SEEK_CUR);
                    fwrite(&clist,sizeof(clist),1,fg);
                }
                else
                {
                    temp2=clist;
                    clist=temp;
                    fseek(fg,0,SEEK_CUR);
                    fwrite(&clist,sizeof(clist),1,fg);
                    clist=temp2;
                }
            }
            fclose(ff);
            fclose(fg);
            remove("cdata.cfile");
            rename("tempf.cfile","cdata.cfile");
        }
        printf("\nYou have voted %s successfully. Press any key to continue ",temp.name);
        getch();
        mainmenu();
    }
    else
    {
        printf("\n\tSorry !\n\nVoting is disabled by Admin . Please try later .\n\tYou are redirecting to Mainmenu ");
        int k;
        for(k=0;k<7;k++)
        {
            printf(". ");
            Sleep(500);
        }
        mainmenu();
    }
}
