#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>

int n,i,j,tatSum=0,wtSum=0,idle=0;
char ch='i';

struct process
{
 int id;
 int at;
 int bt;
 int pt;
 int ct;
 int tat;
 int wt;
}pr[10];

void checkCalIdle()
{
 for(i=0;i<n;i++)
 {
   if(pr[i].at==0)
   {
     ch='n';
     break;
   }
 }


 if(ch=='i')
 {
  int min=pr[0].at;
  for(i=0;i<n;i++)
  {
   if(pr[i].at<min)
     min=pr[i].at;

  }
  idle=min;
 }

}

void printingGanttChart()
{

  sleep(1);
  cout<<"\n\nGantt Chart\n";
  sleep(1);
  cout<<"|";
  if(ch=='i')
   {
    for(j=0;j<idle*2;j++)
    cout<<"Ä";
    cout<<"|";
   }
  for(i=0;i<n;i++)
  {
   for(j=0;j<pr[i].bt*2;j++){cout<<"Ä";}
   cout<<"|";
  }
  sleep(1);
  cout<<endl<<"|";

  if(ch=='i')
   {
    for(j=0;j<idle*2;j++)
    cout<<" ";
    cout<<"|";
   }
  for(i=0;i<n;i++)
  {
   for(j=0;j<pr[i].bt-1;j++){cout<<" ";}
   cout<<"P"<<pr[i].id;
   for(j=0;j<pr[i].bt-1;j++){cout<<" ";}
   cout<<"|";
  }

  sleep(1);
  cout<<endl<<"|";

  if(ch=='i')
   {
    for(j=0;j<idle*2;j++)
    cout<<"Ä";
    cout<<"|";
   }
  for(i=0;i<n;i++)
  {
   for(j=0;j<pr[i].bt*2;j++){cout<<"Ä";}
   cout<<"|";
  }



}

void outputingTable()
{
 cout<<"\nProcess\tBT\tPriority\tAT\tCT\tTAT\tWT\n";
 for(i=0;i<n;i++)
 {
  cout<<"\nP"<<pr[i].id<<"\t"<<pr[i].bt<<"\t"<<pr[i].pt<<"\t\t"<<pr[i].at<<"\t"<<pr[i].ct<<"\t"<<pr[i].tat<<"\t"<<pr[i].wt;
  sleep(1);
 }
}

void PriorSorting()
{
  process temp;

 for(i=0;i<n;i++)
 {
  for(j=i+1;j<n;j++)
  {
   if(pr[i].at>pr[j].at)
   {
    temp=pr[i];
    pr[i]=pr[j];
    pr[j]=temp;
   }
  }
 }

}

/*void PriorSorting()
{
 process temp;

 for(i=0;i<n;i++)
 {
  for(j=i+1;j<n;j++)
  {
   if(pr[i].pt>pr[j].pt)
   {
    temp=pr[i];
    pr[i]=pr[j];
    pr[j]=temp;
   }
  }
 }

}*/

void Input()
{
  for(i=0;i<n;i++)
 {
  pr[i].id=i+1;
  clrscr();

  cout<<"\n! Enter Details of Process "<<i+1<<" !";
  cout<<"\nEnter Arrival Time : ";
  cin>>pr[i].at;

  cout<<"Enter Burst Time : ";
  cin>>pr[i].bt;

  cout<<"Enter Priority : ";
  cin>>pr[i].pt;

 }
}


void Calculate()
{
  for(i=0;i<n;i++)
 {


  if(i==0)
    pr[i].ct=pr[i].bt+idle;
  else
    pr[i].ct=pr[i-1].ct+pr[i].bt;

  pr[i].tat=pr[i].ct-pr[i].at;

  pr[i].wt=pr[i].tat-pr[i].bt;

 }
}

void border()
{
 clrscr();

 gotoxy(0,0);
 for(i=0;i<80;i++)
 {

   cout<<"*";
   }

   gotoxy(0,2);
   for(i=0;i<22;i++)
   {

   cout<<"*\n";
   }

    for(i=0;i<80;i++)
 {

   cout<<"*";
   }

   for(i=2;i<24;i++)
   {
   gotoxy(80,i);
   cout<<"*";
   }



   sleep(1);
   gotoxy(2,2);

}

void openingPage()
{
  //clrscr();
  gotoxy(1,1);
  textcolor(MAGENTA);
  gotoxy(2,7);cout<<"                JAIN (DEEMED - TO - BE UNIVERSITY)\n";sleep(1);
  gotoxy(2,9);cout<<"                             ACTIVITY 2\n";                 sleep(1);
  gotoxy(2,11);cout<<"                     PRIORTY PREMPTIVE SCHEDULING ALGORITHM \n"; sleep(1);
  gotoxy(2,15);
  cout<<"                         TEAM MEMBERS   :";
 gotoxy(40,17);  cout<<"1. Rahul Yadav\t(19BCAR6038)";
 gotoxy(40,18);  cout<<"2. Samiksha M\t(19BCAR8033)";
 gotoxy(40,19);  cout<<"3. Sagar Pal\t(19BCAR1084)";
 gotoxy(40,20);  cout<<"4. Dinesh Reddy\t(19BCAR1073)";
 gotoxy(40,21);  cout<<"5. Ammar Hussain\t(19BCAR2060)";

  getch();

}



void main()
{
 border();
 openingPage();
 clrscr();

 textcolor(MAGENTA);
 border();
 gotoxy(3,3);cout<<"Enter no. of Processes(max:10) : ";
 cin>>n;

 Input();

 PriorSorting();

 checkCalIdle();

 Calculate();
 textcolor(YELLOW);

 border();
 outputingTable();


 printingGanttChart();

 for(i=0;i<n;i++)
 {
  tatSum+=pr[i].tat;
  wtSum+=pr[i].wt;
 }

 cout<<"\n\nAverage TAT : "<<(float) tatSum/n<<" ms";
 cout<<"\nAverage WT : "<<(float) wtSum/n<<" ms";
 sleep(2);
 getch();
 clrscr();
 border();
 gotoxy(35,12);textcolor(YELLOW); cout<<"THANK YOU :)";
 sleep(2);
 getch();
}