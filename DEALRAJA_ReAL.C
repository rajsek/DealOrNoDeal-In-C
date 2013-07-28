//need to done just add 1)welcome screen2)combain the box no in side the box3) display rest odf the things in the  below text fof box 4 ) do seperate screen for banker waiting5) screen for deal or deal 6) final screen
#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>


	char ch;
	long float multipler,banker_box[26],persent=100,left=26,banker_amt=0,i,deal_amt,temp,rs2[26]={ 0,1,5,10,25,50,75,100,200,300,400,500,750,1000,5000,10000,25000,50000,75000,100000,250000,500000,750000,1000000,25000000,50000000},rs1[26] ={ 0,1,5,10,25,50,75,100,200,300,400,500,750,1000,5000,10000,25000,50000,75000,100000,250000,500000,750000,1000000,25000000,50000000};
	long int status2[26]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},status[26]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
	int box[25],ur_case,round=1,deal;
void rand1();
void banker();
void round_fn();
void play(int);
int check_open(int);
void open_case(int );
void find_display(int );
void box1();
void box2();
void Analyze();

void display()
{

 int i,j,k=0;
 clrscr();
 textcolor(YELLOW);
 textbackground(LIGHTBLUE);
 for(j=0;j<4;j++)
 { for(i=1;i<=6;i++)
  {
   ++k;
   if((status[k-1]==1)&&((ur_case-1)!=(k-1)))
   {

    gotoxy(15+(i*6),2+(j*4));
    cprintf(" %c%c%c%c\n",218,196,196,191);
    gotoxy(15+(i*6),3+(j*4));
    cprintf("%c%c%c%c%c%c\n",218,196,196,196,196,191);
    gotoxy(15+(i*6),4+(j*4));
    cprintf("%c %2d %c\n",179,k,179);
    gotoxy(15+(i*6),5+(j*4));
    cprintf("%c%c%c%c%c%c",192,196,196,196,196,217);
   }
  }
  if(j==3)
  {
	for(i=3;i<=4;i++)
	{     k++;
	      if((status[k-1]==1)&&((ur_case-1)!=(k-1)))
	      {
		gotoxy(15+(i*6),2+((j+1)*4));
		cprintf(" %c%c%c%c\n",218,196,196,191);
		gotoxy(15+(i*6),3+((j+1)*4));
		cprintf("%c%c%c%c%c%c\n",218,196,196,196,196,191);
		gotoxy(15+(i*6),4+((j+1)*4));
		cprintf("%c %2d %c\n",179,k,179);
		gotoxy(15+(i*6),5+((j+1)*4));
		cprintf("%c%c%c%c%c%c",192,196,196,196,196,217);
	      }
	}
  }


 }
  textcolor(MAGENTA);
  gotoxy(2,18);
  printf("ur box=>");
  gotoxy(2,19);
  cprintf("     %c%c%c%c\n",218,196,196,191);
  gotoxy(2,20);
  cprintf("    %c%c%c%c%c%c\n",218,196,196,196,196,191);
  gotoxy(2,21);
  cprintf("    %c %2d %c\n",179,ur_case,179);
  gotoxy(2,22);
  cprintf("    %c%c%c%c%c%c",192,196,196,196,196,217);
  textcolor(WHITE);
  gotoxy(18,1);
  printf("***DEAL OR NO_DEAL GAME show(RAJASEKAR)*** ");
 gotoxy(1,2);printf("|    RS  |on/off|");
 for(i=1;i<=13;i++)
 {
	gotoxy(1,i+2);
	if(status2[i-1]==0)
	{  textcolor(BROWN);
	   textbackground(CYAN);
	}
	else
	{
	   textcolor(WHITE);
	   textbackground(BLUE);
	}

	cprintf("|$%7.2lf|%6ld|",rs2[i-1],status2[i-1]);
	textcolor(WHITE);
	textbackground(BLUE);
 }
 gotoxy(60,2);printf("|     RS     |on/off|");
 for(i=1;i<=13;i++)
 {
	gotoxy(60,i+2);
	if(status2[i+12]==0)
	{  textcolor(BROWN);
	   textbackground(CYAN);
	}
	else
	{
	   textcolor(WHITE);
	   textbackground(BLUE);
	}
	cprintf("|$%11.2lf|%6ld|",rs2[i+12],status2[i+12]);
	textcolor(WHITE);
	textbackground(BLUE);
 }

}
void main()
{       clrscr();
	rand1();
	box2();
	gotoxy(30,7);
	printf("DELA or NO DEAL");
	gotoxy(30,8);
	printf("Written by D.rajasekar");
	box1();
	gotoxy(26,18);
	printf("Enter your suitcase NO:");
	scanf("%d",&ur_case);
	do
	{       display();
		play(round);
		round_fn();
		banker();
		clrscr();
		box2();
		gotoxy(30,7);
		printf("BANKER CALL Wait pls...");
		gotoxy(30,8);
		printf("WAIT few seconds");
		delay(5000);
		Analyze();
		clrscr();
		box2();
		gotoxy(30,8);
		printf("BANKER OFFER= %.2lf",banker_amt);
		box1();
		gotoxy(26,18);
		printf("Enter 1 for deal or 2 for no deal: ");
		scanf("%d",&deal);
		if (deal==3)
			exit(0);
		++round;


	}while((round<=9) && (deal != 1));
	if(deal== 1)
		deal_amt=banker_amt;
	else
		deal_amt=rs1[ur_case-1];
	box2();
	gotoxy(22,7);
	printf("The get %.2lfRs from banker",deal_amt);
	gotoxy(25,8);
	printf("Amount in ur Box:%.2lf",rs1[ur_case-1]);
	box1();
	gotoxy(26,18);
	printf("Thank you for playing......");
	gotoxy(26,19);
	printf(" IT's a good DEAL\n");
	getch();

}
void play(int x)
{
	int i,j,k,open,time=0;
	if(x<=6)
		i=7-x;
	else
	{
		i=1;
	}
	for(j=0;i!=time;j++)
	{
		display();
		gotoxy(32,22);
		printf("****Round=%d****",x);
		gotoxy(21,23);
		printf("*****left of case to open: %d*****\n",i-time);
		gotoxy(15,24);
		printf("Enter the case to open: ");
		scanf("%d",&open);
		clrscr();
		k=check_open(open);
		gotoxy(16,17);
		textcolor(YELLOW);
		box2();
		gotoxy(30,7);
		if(k==0)
		{	printf("InValid Choice.. Enter in between (1-26)");
		}
		else if(k==1)
		{       gotoxy(25,7);
			printf("The case No: %d is already open...",open);
			gotoxy(25,8);
			printf("Enter the Valid UnOpen case No:");
		}
		else if (k==2)
		{       printf("IT's ur case...");
			gotoxy(30,8);
			printf("Try other then ur case ...");
		}
		else
		{
			printf("Valid case is OPEN");
			delay(1250);
			open_case(open);
			--left;
			--k;
			++time;
		}
		textcolor(LIGHTGREEN);
		gotoxy(44,48);
		textcolor(WHITE);
		delay(1000);

	}
}

int check_open(int x)
{
	if(x>26)
		return 0;
	else if( status[x-1] == 0)
		return 1;
	else if( x==ur_case)
		return 2;
	else
		return 3;
}
void open_case(int x)
{       box1();
	gotoxy(16,17);
	textcolor(BLINK+YELLOW);
	cprintf("Amount in OPENED case NO:%d ==%.2lf",x,rs1[x-1]);
	gotoxy(36,28);
	textcolor(LIGHTGREEN);
	gotoxy(44,48);
	textcolor(WHITE);
	status[x-1]=0;
	find_display(x);
	delay(500);



}
void box2()
{
	int li,lp;
	clrscr();
	textcolor(RED);
	for(li=20;li<61;li++)
	{
		gotoxy(li,10);
		delay(30);
		cprintf("/");
	}
	for(li=60;li>=20;li--)
	{
		gotoxy(li,5);
		delay(30);
		cprintf("\\");
	}
	for(lp=6;lp<10;lp++)
	{
		gotoxy(20,lp);
		delay(100);
		cprintf("-");
	}
	for(lp=9;lp>=6;lp--)
	{
		gotoxy(60,lp);
		delay(100);
		cprintf("-");
	}
}

void box1()
{
	int li,lp;
	textcolor(GREEN);
	for(li=10;li<71;li++)
	{
		gotoxy(li,15);
		delay(30);
		cprintf("/");
	}
	for(li=70;li>=10;li--)
	{
		gotoxy(li,22);
		delay(30);
		cprintf("\\");
	}
	for(lp=16;lp<=21;lp++)
	{
		gotoxy(10,lp);
		delay(100);
		cprintf("-");
	}
	for(lp=21;lp>=16;lp--)
	{
		gotoxy(70,lp);
		delay(100);
		cprintf("-");
	}

}

void find_display(int x)
{       int i;
	for(i=0;i<26;i++)
	{
		if( rs1[x-1]==rs2[i])
			status2[i]=0;
	}
}

void rand1()
{       int x,y,i;
	time_t t;
	srand((unsigned) time(&t));
	for(i=0;i<26;i++)
	{
		x= rand()%26;
		y= rand()%26;
		temp=rs1[x];
		rs1[x]=rs1[y];
		rs1[y]=temp;
	}
	/*for(i=0;i<13;i++) "those who need to verify the random manner of this program"
	{
		printf("\n %d=>%.2lf\t %d=>%.2lf\t\t",i+1,rs1[i],i+14,rs1[i+13]);
	} */
}




void banker()
{       int i;
	printf("\n");
	banker_amt=0;
	for(i=0;i<26;i++)
	{
		banker_box[i]=(rs1[i]*status[i]/left);
		banker_amt+=banker_box[i];
	  //	printf("%d=>%.2lf\t",i,banker_box[i]);
	}
	banker_amt=banker_amt*multipler;
       //	printf("banker=%lf",banker_amt);
}
void round_fn()
{
	if(left>=20)
		multipler=(40/persent);
	else if(left >=15)
		multipler=(50/persent);
	else if(left >=11)
		multipler=(60/persent);
	else if(left >=8)
		multipler=(70/persent);
	else if(left >=6)
		multipler=(80/persent);
	else if(left ==5)
		multipler=(90/persent);
	else if(left ==4)
		multipler=(100/persent);
	else if(left ==3)
		multipler=(110/persent);
	else
	{	multipler=(120/persent);
	}
       //	printf("\n\nmultipler %.2f",multipler);
}
void Analyze(void)
{
  int a;
 gotoxy(30,10); printf("BANKER CALL");
 gotoxy(25,11); printf("ษอออออออออออออออออออออออออออออป");
 gotoxy(25,12); printf("บ ฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐ บ");
 gotoxy(25,13); printf("ศอออออออออออออออออออออออออออออผ");
 for( a=27;a<=53;a++)
 { delay(100);
   gotoxy(a,12);printf("%c",219);
 }
 gotoxy(25,11); printf("ษอออออออออออออออออออออออออออออป");
 gotoxy(25,12); printf("บ ฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐ บ");
 gotoxy(25,13); printf("ศอออออออออออออออออออออออออออออผ");
 for( a=53;a>=27;a--)
 { delay(100);
   gotoxy(a,12);printf("%c",219);
 }
}





