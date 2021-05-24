#include<stdio.h>
struct info
{
    char name[30],address[30],gender[30],mail[30],password[30],time[100],phone[50];
    int age,serial,day,month,year,iday,imonth,iyear,chi,ch;//ch==time option
} x[100];
int counter_for_time_options,counter;
void del();
void delete_meeting_time(int a,int b,int c,int ch);
void delete_entered_time(int a,int b,int c,int ch);
void edit();
void view();
void make_choice();
void set_it(int i,int ch);
int next_page();
void first_screen();
void move_on();
void add();
void see_history();
void choose_time_option(int i,int a,int b,int c,int q);
int get_serial();
void set_password(int i);
void your_time(int i);
int check_with_the_previously_entered_time(int a,int b,int c,int ch);
int check_date_with_meeting_time(int a,int b,int c,int ch);
void increase_day(int i,int a,int b,int c,int ch,int t);
void set_it(int i,int ch);
void main()
{
    first_screen();
    return 0;
}
int next_page()
{
    char c;
    printf("\n\n\t\t\t\t\t\t\t\tPRESS ANY KEY TO GO TO HOME PAGE......");
    scanf("%c",&c);
    if(c!='\n') next_page();
        else make_choice();
}
void first_screen()
{
    int p;
    printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t   ******************************************");
    printf("\n\t\t\t\t\t\t\t\t   ******************************************\n\n");
    printf("\n\n\n\t\t\t\t\t\t\t\t\t          * WELCOME TO *\t\t\t ");
    printf("\n\n\n\t\t\t\t\t\t\t\t             * FIXING AN APPOINTMENT SITE * ");
    printf("\n\n\n\n\t\t\t\t\t\t\t\t   ******************************************");
    printf("\n\t\t\t\t\t\t\t\t   ******************************************\n\n\n\n");
    printf("n\n\t\t\t\t\t\t\t\tPRESS ANY KEY TO CONTINUE.....");
    fflush(stdin);
    getch();
    system("cls");
    make_choice();
}
void make_choice()
{
    int c,p;
    system("cls");
    while(c!=6)
    {
        printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t   ##########################################");
        printf("\n\t\t\t\t\t\t\t\t   ******************************************");
        printf("\n\n\n\n\n\t\t\t\t\t\t\t\t\t          *Enter your choice*\t\t\t ");
        printf("\n\n\n\t\t\t\t\t\t\t\t             1. Add Information ");
        printf("\n\t\t\t\t\t\t\t\t             2. View Information");
        printf("\n\t\t\t\t\t\t\t\t             3. Edit Information");
        printf("\n\t\t\t\t\t\t\t\t             4. Delete Information");
        printf("\n\t\t\t\t\t\t\t\t             5. See Record");
        printf("\n\t\t\t\t\t\t\t\t             6.Exit");
        printf("\n\n\n\n\t\t\t\t\t\t\t\t   ##########################################");
        printf("\n\t\t\t\t\t\t\t\t   ******************************************");

        printf("\n\n\n\t\t\t\t\t\t\t\t             Option=");
        scanf("%d",&c);
        fflush(stdin);
        if(c==1)
        {
            system("cls");
            printf("\n\n\n\n\t\t\t\t\t\t\t\tPLEASE FILL UP THE FOLLOWING INFORMATIONS........");
            add();
        }
        else if(c==2)
        {
            system("cls");
            view();
        }
        else if(c==3)
        {

            system("cls");
            edit();
        }
        else if(c==4)
        {
            system("cls");
            del();
        }

        else if(c==5)
        {
            system("cls");
            see_history();
        }
        else if(c==6)
        {
            system("cls");
            printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tTHANK YOU.........\n\n\n\n\n\n\n\n\n\n");

        }
        else
        {
            system("cls");
            printf("\n\nINVALID INPUT\nTRY AND BY USING VALID INPUTS....");
        }
        if(c!=6)
        {
            printf("\n\n");
            p=next_page();
            if(p!=0) break;
            else system("cls");
        }
    }
}


void see_history()
{
    int srl,z=0,t=0,xserial,xage,xday,xmonth,xyear,xiday,ximonth,xiyear,xchi;
    char c,cpass[20],xname[100],xaddress[100],xmail[100],xgender[100],xphone[100],xpassword[30],xtime[100];
    FILE *H=fopen("History.txt","w");
    FILE *S=fopen("record.txt","r");
    if(H==NULL||S==NULL)
    {
        printf("\n\n\n\n\t\t\t\t\t\t\t\t\tTHE RECORD FILE IS EMPTY......\n");
        return ;
    }
    fprintf(H,"\t\t\t\t-----------------------------------------------------------------------------------------------------------\n");
    fprintf(H,"\t\t\t\t\tSERIAL\t\tNAME\t\t\tTIME\t\t\tDate\n");
    fprintf(H,"\t\t\t\t----------------------------------------------------------------------------------------------------------\n");
    printf("\n\n\n\t\t\t\t------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t-------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\tSERIAL\t\tNAME\t\t\tTIME\t\t\tDate\n");
    printf("\t\t\t\t-------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t-------------------------------------------------------------------------------------------------\n");
    while((fscanf(S,"%d,%[^,],%[^,],%[^,],%d,%[^,],%[^,],%[^,],%d/%d/%d,%[^,],%d,%d,%d,%d\n",&xserial,xname,xaddress,xmail,&xage,xgender,xphone,xpassword,&xday,&xmonth,&xyear,xtime,&xiday,&ximonth,&xiyear,&xchi))==16)
    {
        printf("\t\t\t\t\t%4d %20s %30s %6d/%d/%d\n\n",xserial,xname,xtime,xday,xmonth,xyear);
        fprintf(H,"\t\t\t\t\t%4d %20s %30s %6d/%d/%d\n\n",xserial,xname,xtime,xday,xmonth,xyear);

    }
    fclose(S);
    fclose(H);
    FILE *f1=fopen("History.txt","r");
    FILE *f2=fopen("copy.txt","w");
    if(f1==NULL||f2==NULL)
    {
        printf("Error!!! \n");
        return ;
    }
    while(1)
    {
        c=getc(f1);
        if(c==EOF) break;
        putc(c,f2);
    }
    fclose(f2);
    fclose(f1);
    int rem=remove("History.txt");
    int rim=rename("copy.txt","History.txt");

}


void move_on()
{
    int p;
    printf("\n\n\t\t\t\t\t\t\t\t\tENTER ONE(1) TO SET TIME FOR YOUR MEETING: ");
    scanf("%d",&p);
    if(p!=1)
    {
        system("cls");
        move_on();
    }
    else system("cls");
}
void add()
{
    int i;
    char s[90];
    i=get_serial();
    fflush(stdin);
    printf("\t\t\t\t\t\t\t\t\t\n\n\n");
    printf("\t\t\t\t\t\t\t\t\tEnter client's Name = ");
    gets(x[i].name);
    fflush(stdin);
    printf("\t\t\t\t\t\t\t\t\tEnter Address = ");
    gets(x[i].address);
    fflush(stdin);
    printf("\t\t\t\t\t\t\t\t\tEnter E-mail = ");
    gets(x[i].mail);
    fflush(stdin);
    printf("\t\t\t\t\t\t\t\t\tEnter age = ");
    scanf("%d",&x[i].age);
    fflush(stdin);
    printf("\t\t\t\t\t\t\t\t\tGender(Male/Female/Other) = ");
    gets(x[i].gender);
    fflush(stdin);
    printf("\t\t\t\t\t\t\t\t\tEnter phone number = ");
    gets(x[i].phone);
    fflush(stdin);
    x[i].serial=i;
    printf("\n\t\t\t\t\t\t\t\t\tYOUR SERIAL NUMBER IS  %d\n\n\n",i);
    set_password(i);
    move_on();
    your_time(i);
    fflush(stdin);
    counter=0;
    counter_for_time_options=0;
    int k;
    printf("\n\t\t\t\t\t\t\tENTER...\n\t\t\t\t\t\t\t\t\t(1)TO CONFIRM YOUR APPOINTMENT\n\t\t\t\t\t\t\t\t\t(0)TO RETURN TO HOMEPAGE\n\t\t\t\t\t\t\t\t\tYOUR CHOICE:");
    scanf("%d",&k);
    if(k==1)
    {
        FILE *F=fopen("check time with entered time.txt","a");
        fprintf(F,"%d %d %d %d\n",x[i].iday,x[i].imonth,x[i].iyear,x[i].chi);
        fclose(F);
        FILE *t=fopen("check time with meeting time.txt","a");
        fprintf(t,"%d %d %d %d\n",x[i].day,x[i].month,x[i].year,x[i].ch);
        fclose(t);
        FILE *si;
        si=fopen("record.txt","a");
        fprintf(si,"%d,%s,%s,%s,%d,%s,%s,%s,%d/%d/%d,%s,%d,%d,%d,%d",x[i].serial,x[i].name,x[i].address,x[i].mail,x[i].age,x[i].gender,x[i].phone,x[i].password,x[i].day,x[i].month,x[i].year,x[i].time,x[i].iday,x[i].imonth,x[i].iyear,x[i].chi);
        fprintf(si,"\n");
        fclose(si);
        printf("\n\t\t\t\t\t\t\t\t\tInformation saved successfully!");
        gets(s);
    }
    else make_choice();
    system("cls");
    counter_for_time_options=0;

}


void set_password(int i)
{
    char a[100],b[100],t[10];
    int a1;
    fflush(stdin);
    printf("\t\t\t\t\t\t\t\t\tFOLLOW THE PROCEDURE TO SET YOUR PASSWORD.....\n\t\t\t\t\t\t\t\t\tPRESS ENTER....");
    gets(t);
    system("cls");
    fflush(stdin);
    printf("\n\n\n\t\t\t\t\t\t\t\t\tTYPE YOUR PASSWORD:  ");
    gets(a);
    fflush(stdin);
    printf("\n\n\n\t\t\t\t\t\t\t\t\tRE-TYPE YOUR PASSWORD:  ");
    gets(b);
    fflush(stdin);
    a1=strcmp(a,b);
    if(a1==0)
    {
        strcpy(x[i].password,a);
        printf("\n\n\t\t\t\t\t\t\t\t\t......YOUR PASSWORD HAS BEEN SET......\n");
    }
    else
    {
        printf("\n\t\t\t\t\t\t\t\t\t********BOTH PASSWORDS DO NOT MATCH*********\n\t\t\t\t\t\t\t\t\tPLEASE TYPE YOUR PASSWORDS CAREFULLY\n");
        set_password(i);
    }
}
int get_serial()
{
    int i,y;
    FILE *G=fopen("Q.txt","r");
    fscanf(G,"%d",&i);
    fclose(G);
    y=i;
    i=i+1;
    G=fopen("Q.txt","w");
    fprintf(G,"%d",i);
    fclose(G);
    return y;
}



void your_time(int i)
{
    int a,b,c;
    printf("\n\n\n\n\t\t\t\t\t\t\t\t\tENTER MEETING DATE(DATE/MONTH/YEAR)\n\t\t\t\t\t\t\t\t\tLIKE(1/01/2002):");///
    fflush(stdin);
    scanf("%d/%d/%d",&a,&b,&c);
    fflush(stdin);
    if((a>31)||(a<=0)||(b>12)||(b<=0)||(c<=0)||(c<2021))
    {   system("cls");
        printf("\n\n\n\t\t\t\t\t\t\t\t\tWRONG INPUT.....\n\t\t\t\t\t\t\t\t\tPLEASE CHECK AND TRY AGAIN...\n");
        your_time(i);
    }
    else
    {
        system("cls");
        choose_time_option(i,a,b,c,0);
    }
}


void choose_time_option(int i,int a,int b,int c,int q)//q=previous choice of time
{
    int ch,t,r,ch2;
    if((q!=1)&&(q!=2)&&(q!=3)) q=0;
    printf("\n\n\n\t\t\t\t\t\t\t###################################################\n");
    printf("\t\t\t\t\t\t\t<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
    printf("\n");
    counter_for_time_options++;
    if(counter_for_time_options>1)
    {
        if(q==1)
            printf("\t\t\t\t\t\t\t\t\tTHE REMAINING TIME OPTIONS:\n\t\t\t\t\t\t\t\t\t2. 12:00 p.m -1:00 p.m\n\t\t\t\t\t\t\t\t\t3. 4:00 p.m -5:00 p.m\n");

        if(q==2)
            printf("\t\t\t\t\t\t\t\t\tTHE REMAINING TIME OPTIONS:\n\t\t\t\t\t\t\t\t\t1. 10:00 a.m - 11:00 a.m\n\t\t\t\t\t\t\t\t\t3. 4:00 p.m -5:00 p.m\n");

        if(q==3)
            printf("\t\t\t\t\t\t\t\t\tTHE REMAINING TIME OPTIONS:\n\t\t\t\t\t\t\t\t\t1. 10:00 a.m - 11:00 a.m\n\t\t\t\t\t\t\t\t\t2. 12:00 p.m -1:00 p.m\n");

    }
    else printf("\t\t\t\t\t\t\t\t\tTIME OPTIONS:\n\t\t\t\t\t\t\t1. 10:00 a.m - 11:00 a.m\n\t\t\t\t\t\t\t2. 12:00 p.m -1:00 p.m\n\t\t\t\t\t\t\t3. 4:00 p.m -5:00 p.m\n");
    printf("\n\n\t\t\t\t\t\t\t\t\tYour choice: ");
    scanf("%d",&ch);
    if((ch>0)&&(ch<4))
    {
        x[i].iday=a,x[i].imonth=b,x[i].iyear=c,x[i].chi=ch;
        t=check_with_the_previously_entered_time(a,b,c,ch);
        r=check_date_with_meeting_time(a,b,c,ch);

        if((t!=0)||(r!=0))
        {

            printf("\t\t\t\t\tWE ARE REALLY SORRY TO INFORM YOU THAT THE TIME YOU CHOOSE HAS BEEN ALREADY OCCUPIED.......\n\n\t\t\t\t\t\t\t\tENTER\n\n\t\t\t\t\t\t\t0.TO FIX YOUR APPOINTMENT TIME FOR ANOTHER DAY\n\n\t\t\t\t\t\t\t1.TO CHOOSE ANOTHER TIME SLOT\n\n\n\t\t\t\t\t\t\t\t\tyour choice:");
            scanf("%d",&ch2);
            if(ch2==0) increase_day(i,a,b,c,ch,t);
            else
            {
                system("cls");
                printf("\n\n\n\t\t\tPLEASE CHOOSE DIFFERENT TIME OPTION SO THAT WE CAN FIX YOUR APPOINTMENT DATE AS SOON AS POSSIBLE");
                choose_time_option(i,a,b,c,ch);
            }
        }
        else increase_day(i,a,b,c,ch,t);
    }
    else
    {
        printf("\n\n\n\n\t\t\t\t\t\t\t\t\tINVALID OPTION\n\n\n\n\t\t\t\t\t\t\t\t\tPLEASE CHOOSE A VALID INPUT.....");
        choose_time_option(i,a,b,c,0);
    }

}


int check_with_the_previously_entered_time(int a,int b,int c,int ch)
{
    int m,n,o,ch3,t=0;
    FILE *F1=fopen("check time with entered time.txt","r");
    while((fscanf(F1,"%d %d %d %d",&m,&n,&o,&ch3))==4)
    {

        if((m==a)&&(n==b)&&(o==c)&&(ch3==ch))
        {
            t++;
        }

    }
    if(t>0)t=1;
    fclose(F1);
    return t;
}



void increase_day(int i,int a,int b,int c,int ch,int t)
{
    int b1,c1,a1=a+t;
    if(a1<=30) x[i].day=a1,x[i].month=b,x[i].year=c;
    else
    {
        b1=(a1/30)+b;
        if(b1<=12)
        {
            x[i].day=(a1%30),x[i].month=b1,x[i].year=c;
        }
        else
        {
            x[i].day=a1%30,x[i].month=b1%12,x[i].year=c+(b1/12);
        }
    }
    int p;
    p=check_date_with_meeting_time(x[i].day,x[i].month,x[i].year,ch);
    if(p==0) set_it(i,ch);
    else
    {
        counter++;
        if(counter>1)
            printf("\n\t\t\t\t\t\tSORRY FOR THE DELAY ,BUT HERE IS THE DATE WHICH WE COULD PROVIDE YOU:\n ");
        increase_day(i,x[i].day,x[i].month,x[i].year,ch,p);
    }

}



int check_date_with_meeting_time(int a,int b,int c,int ch)
{
    int m,n,o,ch3,p=0;
    FILE *F1=fopen("check time with meeting time.txt","r");
    while((fscanf(F1,"%d %d %d %d",&m,&n,&o,&ch3))==4)
    {

        if((m==a)&&(n==b)&&(o==c)&&(ch3==ch))
        {
            p++;
        }
    }
    fclose(F1);
    return p;
}

void set_it(int i,int ch)
{
    x[i].ch=ch;
    if(ch==1)strcpy(x[i].time,"10:00 a.m - 11:00 a.m");
    else if(ch==2)strcpy(x[i].time,"12:00 p.m - 1:00 p.m");
    else if(ch==3)strcpy(x[i].time,"4:00 p.m - 5:00 p.m");
    printf("\n\n\t\t\t\t\t\t\t\tSERIAL NO:%d\n\n\t\t\t\t\t\t\tYOUR MEETING TIME %s\n\t\t\t\t\t\t\tDATE = %d/%d/%d\n\n\n",i,x[i].time,x[i].day,x[i].month,x[i].year);
}



void view()
{
    int srl,z=0,xserial,xage,xday,xmonth,xyear,xiday,ximonth,xiyear,xchi;
    char cpass[20],xname[100],xaddress[100],xmail[100],xgender[100],xphone[100],xpassword[30],xtime[100];
    printf("\n\n\n\t\t\t\t\t\t\t\tENTER YOUR SERIAL NUMBER :");
    scanf("%d",&srl);
    fflush(stdin);
    FILE *V=fopen("record.txt","r");
    while((fscanf(V,"%d,%[^,],%[^,],%[^,],%d,%[^,],%[^,],%[^,],%d/%d/%d,%[^,],%d,%d,%d,%d\n",&xserial,xname,xaddress,xmail,&xage,xgender,xphone,xpassword,&xday,&xmonth,&xyear,xtime,&xiday,&ximonth,&xiyear,&xchi))==16)
    {

        if(srl==xserial)
        {
            z++;
            printf("\t\t\t\t\t\t\t\tENTER YOUR PASSWORD:");
            fflush(stdin);
            gets(cpass);
            if(strcmp(cpass,xpassword)==0)
            {

                printf("\n\n\t\t\t\t\t\t\t\tHERE YOU GO......\n\n");
                printf("\t\t\t\t\t\t\t\tYOUR SERIAL NUMBER=%d\n",xserial);
                printf("\t\t\t\t\t\t\t\tNAME = ");
                puts(xname);
                printf("\t\t\t\t\t\t\t\tADDRESS = ");
                puts(xaddress);
                printf("\t\t\t\t\t\t\t\tAge=%d\n\t\t\t\t\t\t\t\tGENDER =%s\n\t\t\t\t\t\t\t\tE-MAIL =%s\n\t\t\t\t\t\t\t\tPHONE NUMBER = %s\n",xage,xgender,xmail,xphone);
                printf("\t\t\t\t\t\t\t\tMEETING DATE:%d/%d/%d\n",xday,xmonth,xyear);
                printf("\t\t\t\t\t\t\t\tMEETING TIME:%s\n\n\n",xtime);


            }
            else
            {
                char c;
                printf("\n\n\t\t\t\t\t\t\t\tWRONG PASSWORD\n");
                printf("\n\t\t\t\t\t\t\t\tPRESS ENTER TO SEE THE MENU....");
                scanf("%c",&c);
                system("cls");
                make_choice();
            }
        }
    }
    if(z==0)printf("\n\n\n\t\t\t\t\t\t\t\tCOULDN'T FIND SUCH SREIAL NUMBER \n");
    fclose(V);
}



void edit()
{
    int q,srl,z=0,xserial,xage,xday,xmonth,xyear,xiday,ximonth,xiyear,xchi;
    char cpass[20],xname[100],xaddress[100],xmail[100],xgender[100],xphone[100],xpassword[30],xtime[100];
    printf("\n\n\n\n\t\t\t\t\t\tEnter your serial.no : ");
    scanf("%d",&srl);
    fflush(stdin);
    FILE *V=fopen("record.txt","r");
    FILE *w=fopen("copy1.txt","w");
    while((fscanf(V,"%d,%[^,],%[^,],%[^,],%d,%[^,],%[^,],%[^,],%d/%d/%d,%[^,],%d,%d,%d,%d\n",&xserial,xname,xaddress,xmail,&xage,xgender,xphone,xpassword,&xday,&xmonth,&xyear,xtime,&xiday,&ximonth,&xiyear,&xchi))==16)
    {
        if(srl==xserial)
        {
            z++;
            printf("\n\t\t\t\t\t\tEnter your password:");
            fflush(stdin);
            gets(cpass);
            if(strcmp(cpass,xpassword)!=0)
            {
                fprintf(w,"%d,%s,%s,%s,%d,%s,%s,%s,%d/%d/%d,%s,%d,%d,%d,%d\n",xserial,xname,xaddress,xmail,xage,xgender,xphone,xpassword,xday,xmonth,xyear,xtime,xiday,ximonth,xiyear,xchi);
                printf("\n\t\t\t\t\t\t\tWrong password.");
            }
            else
            {
                printf("\n\t\t\t\t\t\tWHAT DO YOU WANT TO EDIT?\n\t\t\t\t\t\tENTER YOUR OPTION :  \n");
                printf("\n\t\t\t\t\t\t\t1.Name\n\t\t\t\t\t\t\t2.Address\n\t\t\t\t\t\t\t3.Age\n\t\t\t\t\t\t\t4.Gender\n\t\t\t\t\t\t\t5.Phone Number \n\t\t\t\t\t\t\t6.E-mail\n\n");
                printf("\n\n\n\n\t\t\t\t\t\tOption=");
                scanf("%d",&q);//option
                if(q==1)
                {
                    fflush(stdin);
                    printf("\n\t\t\t\t\t\t\tEnter Your Name= ");
                    gets(xname);
                }
                else if(q==2)
                {
                    fflush(stdin);
                    printf("\n\t\t\t\t\t\t\tEnter the New Address= ");
                    gets(xaddress);
                }
                else if(q==3)
                {
                    fflush(stdin);
                    printf("\n\t\t\t\t\t\t\tEnter the Age= ");
                    scanf("%d",&xage);
                }
                else if(q==4)
                {
                    fflush(stdin);
                    printf("\n\t\t\t\t\t\t\tGender(Female/Male/Other)= ");
                    scanf("%[^\n]",&xgender);
                }
                else if(q==5)
                {
                    fflush(stdin);
                    printf("\n\t\t\t\t\t\t\tEnter the New Phone no = ");
                    scanf("%[^\n]",&xphone);
                }
                else if(q==6)
                {
                    fflush(stdin);
                    printf("\n\t\t\t\t\t\t\tEnter the new E-mail = ");
                    scanf("%[^\n]",&xmail);
                }
                else
                {
                    printf("\n\n\n\t\t\t\t\t\t\tInvalid Serial \nTry Again !!\n\n");
                }
                fprintf(w,"%d,%s,%s,%s,%d,%s,%s,%s,%d/%d/%d,%s,%d,%d,%d,%d\n",xserial,xname,xaddress,xmail,xage,xgender,xphone,xpassword,xday,xmonth,xyear,xtime,xiday,ximonth,xiyear,xchi);

            }
        }
        else  fprintf(w,"%d,%s,%s,%s,%d,%s,%s,%s,%d/%d/%d,%s,%d,%d,%d,%d\n",xserial,xname,xaddress,xmail,xage,xgender,xphone,xpassword,xday,xmonth,xyear,xtime,xiday,ximonth,xiyear,xchi);
    }
    if(z==0)printf("\n\t\t\t\t\t\t\tCould not find the data\n");
    fclose(V);
    fclose(w);
    int rem;
    rem=remove("record.txt");
    int rin=rename("copy1.txt","record.txt");

}



void del()
{
    int xchoice,q,srl,z=0,xserial,xage,xday,xmonth,xyear,xiday,ximonth,xiyear,xchi;
    char cpass[20],xname[100],xaddress[100],xmail[100],xgender[100],xphone[100],xpassword[30],xtime[100];
    printf("\n\t\t\t\t\t\t\tTo delete your information enter these following info.......\n\n\t\t\t\t\t\t\tYour serial.no:");
    scanf("%d",&srl);
    fflush(stdin);
    FILE *V=fopen("record.txt","r");
    FILE *w=fopen("copy2.txt","w");
    while((fscanf(V,"%d,%[^,],%[^,],%[^,],%d,%[^,],%[^,],%[^,],%d/%d/%d,%[^,],%d,%d,%d,%d\n",&xserial,xname,xaddress,xmail,&xage,xgender,xphone,xpassword,&xday,&xmonth,&xyear,xtime,&xiday,&ximonth,&xiyear,&xchi))==16)
    {
        if(srl==xserial)
        {
            z++;
            printf("\n\t\t\t\t\t\t\tEnter your password: ");
            fflush(stdin);
            gets(cpass);
            if(strcmp(cpass,xpassword)==0)
            {
                if(strcmp(xtime,"10:00 a.m - 11:00 a.m")==0)xchoice=1;
                else if(strcmp(xtime,"12:00 p.m - 1:00 p.m")==0)xchoice=2;
                else if(strcmp(xtime,"4:00 p.m - 5:00 p.m")==0)xchoice=3;

                delete_meeting_time(xday,xmonth,xyear,xchoice);
                delete_entered_time(xiday,ximonth,xiyear,xchi);
                printf("\n\t\t\t\t\t\t\tYour information is deleted\n");

            }
            else
            {
                printf("\n\t\t\t\t\t\t\tWrong password.");
                fprintf(w,"%d,%s,%s,%s,%d,%s,%s,%s,%d/%d/%d,%s,%d,%d,%d,%d\n",xserial,xname,xaddress,xmail,xage,xgender,xphone,xpassword,xday,xmonth,xyear,xtime,xiday,ximonth,xiyear,xchi);

            }
        }
        else  fprintf(w,"%d,%s,%s,%s,%d,%s,%s,%s,%d/%d/%d,%s,%d,%d,%d,%d\n",xserial,xname,xaddress,xmail,xage,xgender,xphone,xpassword,xday,xmonth,xyear,xtime,xiday,ximonth,xiyear,xchi);
    }
    if(z==0)printf("Could not find the data\n");
    fclose(V);
    fclose(w);
    int rem,rin;
    rem=remove("record.txt");
    rin=rename("copy2.txt","record.txt");


}



void delete_meeting_time(int a,int b,int c,int ch)
{
    int m,n,o,p;
    FILE *S1=fopen("check time with meeting time.txt","r");
    FILE *S2=fopen("temp1.txt","w");
    while((fscanf(S1,"%d %d %d %d\n",&m,&n,&o,&p))==4)
    {

        if((m==a)&&(n==b)&&(o==c)&&(p==ch));
        else
        {

            fprintf(S2,"%d %d %d %d\n",m,n,o,p);
        }
    }
    fclose(S1);
    fclose(S2);
    int assss=remove("check time with meeting time.txt");
    int bis=rename("temp1.txt","check time with meeting time.txt");

}



void delete_entered_time(int a,int b,int c,int ch)
{
    int m,n,o,p;
    FILE *S1=fopen("check time with entered time.txt","r");
    FILE *S2=fopen("temp.txt","w");
    while((fscanf(S1,"%d %d %d %d\n",&m,&n,&o,&p))==4)
    {

        if((m==a)&&(n==b)&&(o==c)&&(p==ch));
        else
        {

            fprintf(S2,"%d %d %d %d\n",m,n,o,p);
        }
    }
    fclose(S1);
    fclose(S2);
    int assss=remove("check time with entered time.txt");
    int bis=rename("temp.txt","check time with entered time.txt");

}
