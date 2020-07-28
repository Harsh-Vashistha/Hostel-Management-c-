#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<conio.h>
#include<ctype.h>
#include<dos.h>
#include<windows.h>

int MAX_SIZE=2;      //no. of rooms in hostel

void SetColor(int ForgC)  //to set color of text
{
     WORD wColor;

     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;


     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {

          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
}


//FUNCTION TO ADD COLOR TO CONSOLE

void SetColorAndBackground(int ForgC, int BackC)
{
     WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);;
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
     return;
}


void ClearConsoleToColors(int ForgC, int BackC)
{
     WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);

     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

     COORD coord = {0, 0};

     DWORD count;

     CONSOLE_SCREEN_BUFFER_INFO csbi;

     SetConsoleTextAttribute(hStdOut, wColor);
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {

          FillConsoleOutputCharacter(hStdOut, (TCHAR) 32, csbi.dwSize.X * csbi.dwSize.Y, coord, &count);
          FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, csbi.dwSize.X * csbi.dwSize.Y, coord, &count );

          SetConsoleCursorPosition(hStdOut, coord);
     }
     return;
}

COORD coord = {0,0}; ///intilises x,y to 0,0
void gotoxy(int x, int y){
    coord.X = x; coord.Y = y; ///takes in c,y co-ordinates
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


void tabledraw()
{
    int ii, j;
    gotoxy(1,1);
    printf("%c",201);
    for(ii = 1; ii < 210; ii++){
        gotoxy(ii, 1);
        printf("%c",205);
    }
    gotoxy(210,1);
    printf("%c",187);
    for(ii= 2; ii < 60; ii++){
        gotoxy(210, ii);
        if(ii == 6){
            printf("%c",185);
        }else{
            printf("%c",186);
        }

    }
     printf("%c",188);
    gotoxy(110, 30);
    printf("%c",188);
    for(ii = 211; ii > 0; ii--){
        gotoxy(ii,50);
        if(ii == 35)
        {
            printf("%c",202);
        }else{
            printf("%c",205);
        }
    }
    gotoxy(1,30);
    printf("%c",201);
    for(ii = 50; ii > 0; ii--){
        gotoxy(0,ii);
        if(ii == 6){
            printf("%c",204);
        }else{
            printf("%c",186);
        }
    }

    for(ii = 1; ii < 110; ii++){
        gotoxy(ii,6);
        if(ii == 35){
            printf("%c",203);
        }else{
            printf("%c",205);
        }
    }

    for(ii = 7; ii < 30; ii++){
        gotoxy(35,ii);
        printf("%c",186);
    }

}

void screenclear(){
    int i,j;
    for(i = 37; i < 110; i++){
        for(j = 7; j < 30; j++){
            gotoxy(i,j);printf(" ");
        }
    }
    return;
}


void heading(const char st[]){
    SetColorAndBackground(31,28);
    gotoxy(45,8);printf("%s",st);
    SetColorAndBackground(17,15);
}


void window(){
    tabledraw();
    gotoxy(28,2);
    SetColor(35);
    printf("HOSTEL MANAGEMENT ENGINE");
    gotoxy(25,3);
    printf("JAYPEE INSTITUTE, NOIDA,SEC 62");
    gotoxy(35,4);
    printf("2018-2019");
    gotoxy(25,24);
    SetColor(17);

}


int i,j,main_exit;


struct stu {

 char name[60];
 int age;
 char city[60];
 char mail_id[30];
 char room_no[8];
 char namefather[60];
 //setcolor(37);
 int phonefather;
 int phone;
 char hname[6];
 char rollnumber[15];
 };
struct stu ee,add1;


 int frontt=-1;
 int rear=-1;
  struct queuee
 {
     struct stu q;

 };

struct queuee que[100];


//defining global variables

//declaring functions
void menu();
void new_entry();
void edit();
void alldata();
void erase();
void see();
void sorter();
void end();

 void enQueue(struct stu value)
 {
     screenclear();
   if(rear == 100-1)
   {

      gotoxy(37,12);printf("Queue is Full!!! Insertion is not possible!!!");
   }
   else{
      if(frontt ==-1)
      rear++;
      //inserting data in queue
      strcpy(que[rear].q.name,value.name);
      que[rear].q.age = value.age;
      strcpy(que[rear].q.city,value.city);
      strcpy(que[rear].q.mail_id ,value.name);
      strcpy(que[rear].q.room_no ,value.room_no);
      strcpy(que[rear].q.namefather,value.namefather);
      que[rear].q.phonefather = value.phonefather;
      strcpy(que[rear].q.hname,value.hname);
      strcpy(que[rear].q.rollnumber,value.rollnumber);
     gotoxy(37,14); printf("Insertion success!!!");
   }
}

void deQueue()
{
   if(frontt == rear)
      printf("\nQueue is Empty!!! Deletion is not possible!!!");
   else
    {
        char p[10];
        strcpy(p,que[frontt].q.rollnumber);
      printf("\nData DELETED!!  with roll no: %s",p);
      frontt++;
      if(frontt == rear)
	 frontt = rear = -1;
   }
}


 void display()
 {
screenclear();
   if(rear == -1)
     {
         gotoxy(37,12);
     printf("Queue is Empty!!!");}
   else{
screenclear();
      int i;
      gotoxy(37,12);printf("Queue elements are:");
      for(i=frontt; i<=rear; i++)
	  {
frontt=-1;
     int rear=-1;
	     gotoxy(37,13); printf(" name is==%s",que[i].q.name);

 gotoxy(37,14);    printf("age is ==%d",que[i].q.age);


 gotoxy(37,15); printf("city ==%s",que[i].q.city);



    gotoxy(37,16); printf(" email id is==%s",que[i].q.mail_id);

     gotoxy(37,17); printf("room no is==%d",que[i].q.room_no);

    gotoxy(37,18); printf("father name==%s",que[i].q.namefather);
    ;
    gotoxy(37,19); printf("father phone no==%d",que[i].q.phonefather);

   gotoxy(37,20); printf("student phone no==%d",que[i].q.phone);



	  }
   }
}




 int pp=0;

struct stu wait_entry()
{
    screenclear();
    int choice;
    gotoxy(37,12);
    printf("eneter 1 to show wait list");
       gotoxy(37,14);
    printf("eneter 2 to eneter data in wait list");
    gotoxy(37,16);scanf("%d",&choice);
    if(choice==1)
        display();
else if(choice==2)
{
    heading("Wait List Entry");
screenclear();
 //  FILE *ptr;
   // ptr=fopen("waitlist.dat","a+");
     gotoxy(37,12);printf("enter name ");
    gotoxy(55,12);scanf("%s",ee.name);

    gotoxy(37,13);printf("enter age  ");
    gotoxy(55,13);scanf("%d",&ee.age);

  gotoxy(37,14);  printf("enter city  ");
  gotoxy(55,14);  scanf("%s",ee.city);

   gotoxy(37,15); printf("enter mail_id ");
    gotoxy(55,15);scanf("%s",&ee.mail_id);
   // que[rear].stu.name = value.name;
    gotoxy(37,16);printf("enter room no ");
    gotoxy(55,16);scanf("%d",&ee.room_no);

    gotoxy(37,17);printf("enter fathers name ");
    gotoxy(62,17);scanf("%s",&ee.namefather);

gotoxy(37,18);    printf("enter fathers phone no ");
   gotoxy(62,18); scanf("%d",&ee.phonefather);

gotoxy(37,19);    printf("enter students phone no  ");
   gotoxy(65,19); scanf("%d",&ee.phone);

 gotoxy(37,20);   printf("enter hostel name  ");
    gotoxy(55,20);scanf("%s",&ee.hname);
gotoxy(37,21);    printf("enter roll no  ");
 gotoxy(55,21);   scanf("%d",&ee.rollnumber);



    FILE *ptr,*hostel;
    ptr=fopen("waitlist.txt","a+");

   if(ptr)
   {
       screenclear();
    fprintf(ptr,"%s %s  %d %s %d %s %s %d %s %s\n",ee.rollnumber, ee.name, ee.age, ee.city, ee.phone, ee.mail_id, ee.namefather, ee.phonefather, ee.room_no, ee.hname);
   gotoxy(37,12); printf("!!data succesfully entered in waitlist!");
  gotoxy(37,14);
   enQueue(ee);
   getch();
   menu();
    return ee;

   }
   else
   {
       screenclear();
   gotoxy(37,12); printf("!file could not open");
    return ee;

    }
}

}

//defining structures
struct date{
 int month,day,year;
};
struct {

 char name[60];
 int age;
 char city[60];
 char mail_id[30];
 char room_no[8];
 char namefather[60];
 int phonefather;
 int phone;
 char hname[6];
 char rollnumber[10];
 struct date dob;
 }add,upd,check,rem,sort;

//--------------------------------------------------------------------------------------------------------------------
//main function
int main()
{
 ClearConsoleToColors(2,1);
 Sleep(500);
 ClearConsoleToColors(2,2);
 Sleep(500);
 ClearConsoleToColors(2,3);
 Sleep(1000);
 //menu();
 ClearConsoleToColors(17,15);
    SetConsoleTitle("Hostel Management Engine");
    window();
    //use_pass_field();
    menu();
    return 0;
 return 0;
}


//menu function
void menu()
{
     int x=2;
    SetColor(36);
    int choice;
    Beep(300,300);


   while(1){
        gotoxy(x,8); printf("1.Enter new Student's data");
        gotoxy(x,10);printf("2.Update existing account");
        gotoxy(x,12);printf("3.Check the details of an account");
        gotoxy(x,14);printf("4.Removing existing account");
        gotoxy(x,16);printf("5.View all student list");
        gotoxy(x,18);printf("6.Enter in waitlist");
        gotoxy(x,20);printf("7.Exit");
        gotoxy(x,22);
        //gotoxy(x,20);printf("7. Exit");
        //gotoxy(x,22);printf("Enter your choice: ");
        scanf("%d",&choice);


 //printf("\n\n\t\t1.Enter new Student's data\n\t\t2.Update information of existing account\n\t\t3.Check the details of existing account\n\t\t4.Removing existing account\n\t\t5.View all students list\n\t\t6.Enter in waitlist\n\t\t7.Exit\n\n\n\n\n\t\t Enter your choice:");

 switch(choice)
 {

 case 1:
   //  delay(1000);

 new_entry();

 break;

 case 2:

    // delay(1000);
 edit();

 break;

 case 3:

    // delay(1000);
 see();

 break;

 case 4:

    // delay(1000);
 erase();

 break;
 case 5:

   //  delay(1000);
 alldata();

 break;


 case 6:

   //  delay(1000);
 wait_entry();
 //end();
 break;


 case 7:

    // delay(1000);
         end();
          break;
 default:
     printf("\nWRONG CHOICE");
     printf("\n\nENTER YOUR CHOICE AGAIN");
     menu();
 }
}
}

//------------------------------------------------------------------------------------------------------------------
//function to display all students of a hostel
void sorter()
{
   // FILE *hostel;
  Beep(700,150);
 int choice,test=0;
 printf("Enter HOSTEL choice:\n\n\t\t \n1.ABB-3 \n\n\t\t \n2.H-3 \n\n\t\t \n3.Sarojini \n\n\t\t \n4.H-2 \n\n");
 scanf("%d",&choice);

 FILE *fp,*hostel;
 switch(choice)
 {
 case 1: hostel=fopen("ABB3.dat","r");
 break;
 case 2: hostel=fopen("H3.dat","r");
 break;
 case 3: hostel=fopen("Sarojini.dat","r");
 break;
 case 4: hostel=fopen("H2.dat","r");
 break;
 default: sorter();
 }
 while(fscanf(hostel,"%s ",/*check.rollnumber, check.name, &check.dob.month, &check.dob.day, &check.dob.year, &check.age, check.city, &check.phone, check.mail_id, check.namefather, &check.phonefather, check.room_no,*/ check.hname));
 {
 fp=fopen("record.dat","r");
 while(fscanf(fp,"%s ",/*sort.rollnumber, sort.name, &sort.dob.month, &sort.dob.day, &sort.dob.year, &sort.age, sort.city, &sort.phone, sort.mail_id, sort.namefather, &sort.phonefather, sort.room_no,*/ sort.hname)!=EOF)
 {
 if(strcmp(check.hname,sort.hname)==0)
{

 if(test==0)
 {
 printf("\t\tFollowing is the list of requested students:");
	printf("\n\tROLL NO.\t\tNAME\t\tROOM NO.\n");
 }
 printf("\n %s", check.hname);
 test++;
 }
 }
 }

 fclose(fp);
 if (test==0)
 printf("\nNO RECORDS!!\n");

 tt:
 printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
 scanf("%d",&main_exit);

 if (main_exit==1)
 menu();
 else if(main_exit==0)
 end();
 else
 {
 printf("\nInvalid!\a");
 goto tt;
 }

}

//------------------------------------------------------------------------------------------------------------------

//new entry function
void new_entry()
{


  screenclear();
    heading("New  Entry");
    SetColor(45);
   // int isFound = 0, print = 37;
    Beep(700,150);
 int choice;
 FILE *ptr,*hostel;

 ptr=fopen("record.dat","a+");


 int count=0;
 while(fscanf(ptr,"%s %s %d/%d/%d %d %s %d %s %s %d %s %s\n",add.rollnumber, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.city, &add.phone, add.mail_id, add.namefather, &add.phonefather, add.room_no, add.hname)!=EOF)
 {
     count++;

 }
 fseek(ptr,0,SEEK_SET);
if(count<MAX_SIZE)
{
 rollnumber:
     screenclear();
 fseek(ptr,0,SEEK_SET);
 heading(" ADD STUDENTS DATA ");
 gotoxy(37,10);printf("Enter your roll number:");
 gotoxy(60,10);scanf("%s",check.rollnumber);
 while(fscanf(ptr,"%s %s %d/%d/%d %d %s %d %s %s %d %s %s\n",add.rollnumber, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.city, &add.phone, add.mail_id, add.namefather, &add.phonefather, add.room_no, add.hname)!=EOF)
 {

 if (strcmp(check.rollnumber,add.rollnumber)==0)
 {
 gotoxy(37,14); printf("Students roll no. already in use!");
 gotoxy(37,16); printf("Press any key to re-enter");

 getch();
 goto rollnumber;
 }
 }

 strcpy(add.rollnumber,check.rollnumber);
 gotoxy(37,11);printf("Enter the name:");
 gotoxy(55,11);scanf("%[^\t]s",add.name);
 gotoxy(37,12);printf("Enter the date of birth(mm/dd/yyyy):");
 gotoxy(74,12);scanf("%d/%d/%d",&add.dob.month,&add.dob.day,&add.dob.year);
 gotoxy(37,13);printf("Enter the age:");
  gotoxy(55,13);scanf("%d",&add.age);
  gotoxy(37,14);printf("Enter the city:");
  gotoxy(55,14);scanf("%s",add.city);
 gotoxy(37,15); printf("Enter the phone number: ");
  gotoxy(65,15);scanf("%d",&add.phone);
  gotoxy(37,16);printf("Enter your email id :");
  gotoxy(65,16);scanf("%s",add.mail_id);
  gotoxy(37,17);printf("Enter your Father's name:");
  gotoxy(67,17);scanf("%s",add.namefather);
  gotoxy(37,18);printf("Enter your Father's phone no.:");
  gotoxy(70,18);scanf("%d",&add.phonefather);
  gotoxy(37,19);printf("Enter your room no.:");
  gotoxy(65,19);scanf("%s",add.room_no);
  gotoxy(37,20);printf("Enter your hostel name 1. ABB3   2.H3");
 gotoxy(37,21);  printf("3. Sarojini     4.H2 :");
  gotoxy(60,22);scanf("%s",add.hname);
 fprintf(ptr,"%s %s %d/%d/%d %d %s %d %s %s %d %s %s\n",add.rollnumber, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.city, add.phone, add.mail_id, add.namefather, add.phonefather, add.room_no, add.hname);

	//adding student roll no. to hostels' list
	if(strcmp(add.hname,"ABB3")==0)
	{
	hostel=fopen("ABB3.dat","a+");
	//fprintf(hostel, "%s\n", add.rollnumber);
	fprintf(hostel,"%s %s %d/%d/%d %d %s %d %s %s %d %s %s\n",add.rollnumber, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.city, add.phone, add.mail_id, add.namefather, add.phonefather, add.room_no, add.hname);

	fclose(hostel);
	}
	else if(strcmp(add.hname,"H3")==0)
	{
	hostel=fopen("H3.dat","a+");
	fprintf(hostel,"%s %s %d/%d/%d %d %s %d %s %s %d %s %s\n",add.rollnumber, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.city, add.phone, add.mail_id, add.namefather, add.phonefather, add.room_no, add.hname);
	fclose(hostel);
	}
	else if(strcmp(add.hname,"Sarojini")==0)
	{
	hostel=fopen("Sarojini.dat","a+");
	fprintf(hostel,"%s %s %d/%d/%d %d %s %d %s %s %d %s %s\n",add.rollnumber, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.city, add.phone, add.mail_id, add.namefather, add.phonefather, add.room_no, add.hname);
	fclose(hostel);
	}
	else if(strcmp(add.hname,"H2")==0)
	{
	hostel=fopen("H2.dat","a+");
	fprintf(hostel,"%s %s %d/%d/%d %d %s %d %s %s %d %s %s\n",add.rollnumber, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.city, add.phone, add.mail_id, add.namefather, add.phonefather, add.room_no, add.hname);
	fclose(hostel);
	}
	//----------------------------------------

 fclose(ptr);
 gotoxy(37,22); printf("Student added successfully!");
retry:
     screenclear();
  gotoxy(37,12);printf("Enter 1 to go to the main menu");
   gotoxy(37,14);printf(" Enetr 0 to exit:");
 scanf("%d",&main_exit);

 if (main_exit==1)
 menu();
 else if(main_exit==0)
 end();
 else
 {
  gotoxy(37,16);printf("Invalid!");
 goto retry;
 }
}

else
{
    screenclear();
   gotoxy(37,12); printf("!!Hostels are full!!");
   printf("enter in waitlist");
   getch();
   menu();

}
}


//------------------------------------------------------------------------------------------------------------------
//function to view all students
void alldata()
{

  screenclear();
    heading("View All Students Data");
    SetColor(45);
   // int isFound = 0, print = 37;
      Beep(700,150);
 FILE *view;
 view=fopen("record.dat","r");
 int test=0;

 gotoxy(40,12);printf("  ROLL NO.    NAME       city          PHONE          HOSTEL NAME");
int pp=14;
 while(fscanf(view,"%s %s %d/%d/%d %d %s %d %s %s %d %s %s\n",add.rollnumber, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.city, &add.phone, add.mail_id, add.namefather, &add.phonefather, add.room_no, add.hname)!=EOF)
 {
 gotoxy(40,pp);printf("%8s %8s %10s     %10d            %s",add.rollnumber,add.name,add.city,add.phone,add.hname);
 test++;
 pp=pp+1;
 }
 fclose(view);

 if (test==0)
 {
 gotoxy(37,14);printf("NO RECORDS!!");}
getch();
 alldata_invalid:
     screenclear();
 gotoxy(37,12);printf("Enter 1 to go to the main menu");
 gotoxy(37,14);printf(" Enter 0 to exit:");
 scanf("%d",&main_exit);

 if (main_exit==1)
 menu();
 else if(main_exit==0)
 end();
 else
 {
 gotoxy(37,18);printf("Invalid!");
 goto alldata_invalid;
 }
}

//------------------------------------------------------------------------------------------------------------------
//function to view all data of 1 student
void see()
{
    screenclear();
    heading("Edit Record");
    SetColor(45);
   // int isFound = 0, print = 37;
    a:
   Beep(700,150);
 FILE *ptr;
 int test=0;
 int choice;
 ptr=fopen("record.dat","r");
 gotoxy(37,10);printf("Do you want to check by");
 gotoxy(37,12); printf("1.Roll no ");
 gotoxy(37,14);printf("2.Name");
  gotoxy(37,16);printf("press any key to enter:");
  getch();
  screenclear();
 gotoxy(37,10); printf("Enter your choice");
 scanf("%d",&choice);
 if (choice==1)
 {
     gotoxy(37,12);printf("Enter the roll number:");
 scanf("%s",check.rollnumber);

 while (fscanf(ptr,"%s %s %d/%d/%d %d %s %d %s %s %d %s %s\n",add.rollnumber, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.city, &add.phone, add.mail_id, add.namefather, &add.phonefather, add.room_no, add.hname)!=EOF)
 {
 if(strcmp(add.rollnumber,check.rollnumber)==0)
 {
 test=1;
screenclear();
heading("Students Data");
 gotoxy(37,11);
 printf("ROLL NO.:");
 gotoxy(40,11);printf("%s",add.rollnumber);
  gotoxy(37,13);printf("Name:%s",add.name);
  gotoxy(37,14);printf("DOB:%d/%d/%d",add.dob.month, add.dob.day, add.dob.year);
 gotoxy(37,15);printf("Age:%d",add.age);
 gotoxy(37,16);printf("city:%s", add.city);
 gotoxy(37,17);printf("Phone number:%d",add.phone);
 gotoxy(37,18);printf("E-Mail id:%s",add.mail_id);
 gotoxy(37,19);printf("Father's name:%s ",add.namefather);
 gotoxy(37,20);printf("Father's Phone No.:%d ",add.phonefather);
 gotoxy(37,21);printf("Room No:%s",add.room_no);
 gotoxy(37,22);printf("Hostel:%s",add.hname);
 getch();
 }
 }
 }
 else if (choice==2)
 {
     screenclear();
    gotoxy(37,12);printf("Enter the name:");
gotoxy(37,14); scanf("%s",check.name);
 while (fscanf(ptr,"%s %s %d/%d/%d %d %s %d %s %s %d %s %s\n",add.rollnumber, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.city, &add.phone, add.mail_id, add.namefather, &add.phonefather, add.room_no, add.hname)!=EOF)
 {
 if(strcmp(add.name,check.name)==0)
 {
     screenclear();
 test=1;
heading("Students Data");
 gotoxy(37,11);
 printf("ROLL NO.:");
 gotoxy(40,11);printf("%s",add.rollnumber);
  gotoxy(37,13);printf("Name:%s",add.name);
  gotoxy(37,14);printf("DOB:%d/%d/%d",add.dob.month, add.dob.day, add.dob.year);
 gotoxy(37,15);printf("Age:%d",add.age);
 gotoxy(37,16);printf("city:%s", add.city);
 gotoxy(37,17);printf("Phone number:%d",add.phone);
 gotoxy(37,18);printf("E-Mail id:%s",add.mail_id);
 gotoxy(37,19);printf("Father's name:%s ",add.namefather);
 gotoxy(37,20);printf("Father's Phone No.:%d ",add.phonefather);
 gotoxy(37,21);printf("Room No:%s",add.room_no);
 gotoxy(37,22);printf("Hostel:%s",add.hname);
 getch();

 //printf("\nROLL NO.:%s\nName:%s \nDOB:%d/%d/%d \nAge:%d \ncity:%s \nPhone number:%d \nE-Mail id:%s \nFather's name:%s \n Father's Phone No.:%d \nRoom No:%s \nHostel:%s \n",add.rollnumber, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.city, add.phone, add.mail_id, add.namefather, add.phonefather, add.room_no, add.hname);
 }
 }
 }
//clear
 fclose(ptr);
 if(test!=1)
 {
     screenclear();
 gotoxy(37,12);printf("Record not found!!");
 gotoxy(37,14);printf("press any key to continue");
 getch();
 }
 invld:
     screenclear();
 gotoxy(37,12);printf("Enter 0 to try again");
 gotoxy(37,14);printf("Enter 1 to return to main menu");
 gotoxy(37,16);printf("Enter 2 to exit:");
 scanf("%d",&main_exit);
 if (main_exit==1)
 menu();
 else if (main_exit==2)
 end();
 else if(main_exit==0)
 goto a;
 else
 {
 printf("Invalid!");
 goto invld;
	}
}

//------------------------------------------------------------------------------------------------------------------
//function to update student info
//
//
void edit()
{
    screenclear();
    heading("Edit Record");
    SetColor(45);
    int isFound = 0, print = 37;
    Beep(700,150);
 int choice,test=0;
 FILE *old,*newrec;
 old=fopen("record.dat","r");
 newrec=fopen("new.dat","w");

 gotoxy(37,12);printf("Enter ROLL NO:");
 scanf("%s",upd.rollnumber);
 while(fscanf(old,"%s %s %d/%d/%d %d %s %d %s %s %d %s %s\n",add.rollnumber, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.city, &add.phone, add.mail_id, add.namefather, &add.phonefather, add.room_no, add.hname)!=EOF)

 {
 if (strcmp(add.rollnumber,upd.rollnumber)==0)
 { test=1;
 gotoxy(37,14);printf(" What you want to change?");
 gotoxy(37,16);printf("1.Room no.");
 gotoxy(37,18);printf("2.Phone");
 gotoxy(37,20);printf("Enter your choice");
 gotoxy(40,22);printf("(1 for room no. and 2 for phone ):");

 scanf("%d",&choice);
screenclear();
 if(choice==1)
 {
 gotoxy(37,13);printf("Enter the new room no.:");
 scanf("%s",upd.room_no);
 fprintf(newrec,"%s %s %d/%d/%d %d %s %d %s %s %d %s %s\n",add.rollnumber, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.city, add.phone, add.mail_id, add.namefather, add.phonefather, upd.room_no, add.hname);
 gotoxy(37,14);printf("Changes saved!");
 getch();
 }

 else if(choice==2)
 {
     screenclear();
 gotoxy(37,13);printf("Enter the new phone number:");
 scanf("%d",&upd.phone);
 fprintf(newrec,"%s %s %d/%d/%d %d %s %d %s %s %d %s %s\n",add.rollnumber, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.city, upd.phone, add.mail_id, add.namefather, add.phonefather, add.room_no, add.hname);
 gotoxy(37,14);printf("Changes saved!");
 getch();
 }

 }
 else
 fprintf(newrec,"%s %s %d/%d/%d %d %s %d %s %s %d %s %s\n",add.rollnumber, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.city, add.phone, add.mail_id, add.namefather, add.phonefather, add.room_no, add.hname);
 }
 fclose(old);
 fclose(newrec);
 remove("record.dat");
 rename("new.dat","record.dat");

	if(test!=1)
    {

 gotoxy(37,14);printf("Record not found!!");
 getch();
    }

 ginvlde:
     screenclear();
	gotoxy(37,14);printf("Enter 0 to try again");
	gotoxy(37,16);printf("Enetr 1. to return to main menu");
	gotoxy(37,18);printf(" Enter 2 to exit:");
 scanf("%d",&main_exit);
 if (main_exit==1)
	menu();
 else if (main_exit==2)
 end();
 else if(main_exit==0)
 edit();
 else
 {
 printf("\nInvalid!\a");
 goto ginvlde;
 }

}


//------------------------------------------------------------------------------------------------------------------
//function to delete records
//prints into new file and deletes the old one
//also renames


FILE *old,*newrec;
int test=0;
void erase()
{
screenclear();
    heading("Delete Record");
    SetColor(45);
    int isFound = 0, print = 37;
Beep(700,150);
 old=fopen("record.dat","r");
 newrec=fopen("new.dat","w");
 gotoxy(37,17);printf("Enter the roll no. you want to delete:");
 scanf("%s",rem.rollnumber);
 while (fscanf(old,"%s %s %d/%d/%d %d %s %d %s %s %d %s %s\n",add.rollnumber, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.city, &add.phone, add.mail_id, add.namefather, &add.phonefather, add.room_no, add.hname)!=EOF)
 {
 if(strcmp(add.rollnumber,rem.rollnumber)!=0)
 fprintf(newrec,"%s %s %d/%d/%d %d %s %d %s %s %d %s %s\n",add.rollnumber, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.city, add.phone, add.mail_id, add.namefather, add.phonefather, add.room_no, add.hname);

 else
 {
     screenclear();
     test++;
 gotoxy(37,12);printf("Record deleted successfully!\n");
 getch();
 }
 }
 fclose(old);
 fclose(newrec);
 remove("record.dat");
 rename("new.dat","record.dat");
 if(test==0)
 { screenclear();
     gotoxy(37,12);
	printf("Record not found!!");
	getch();
 }
 erasevalid:
     screenclear();
  gotoxy(37,14);printf("Enter 0 to try again");
  gotoxy(37,16);printf("Enter 1 to return to main menu ");
  gotoxy(37,18);printf("Enter 2 to exit:");
 scanf("%d",&main_exit);
 if (main_exit==1)
 menu();
 else if (main_exit==2)
 end();
 else if(main_exit==0)
 erase();
 else
 {
 gotoxy(37,20); printf("Invalid!");
 goto erasevalid;
	}
}
//------------------------------------------------------------------------------------------------------------------
//function displaying developer credits
void end()
{
    screenclear();
    heading("CREDITS");
    SetColor(45);
    int isFound = 0, print = 37;
    Beep(700,150);
    SetColor(32);
 gotoxy(37,10);printf("Developed by::::::::::::");
 SetColor(35);
 ; gotoxy(37,12);printf("HARSH VASHISTHA");
   gotoxy(37,14);printf("RISHAV KATOCH");
 gotoxy(37,16);printf("SONU KUMAR");
  gotoxy(37,18);printf("SHIVAM KULSHRESTHA");
SetColor(38);
}

