#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<dos.h>
#include<fstream.h>
#include<graphics.h>
#include<string.h>
#define UP 72
#define LEFT 75
#define RIGHT 77
#define DOWN 80
#define ENTER 13
static int n=0;
class CAR;
class obstacle;
class phighscore;

void game_name()
{cleardevice();
 int y=100,i=0; int userpat=1;
 for(i=0;i<=240;i+=5)
 {cleardevice();
  setcolor(CYAN);
  settextstyle(GOTHIC_FONT,0,2);
  outtextxy(i,y,"CS-6A");
  outtextxy(600-i,y,"CAR RACING");
  delay(100);
 }
 setlinestyle(SOLID_LINE, userpat, 5);
 line(330,100,340,130);
}

void startup()
{cleardevice();
 game_name();
 int midx,midy,t,radius=15;
 midx=(getmaxx()/2.0);
 midy=(3*getmaxy()/4.0);
 setcolor(getmaxcolor());
 settextstyle(SANS_SERIF_FONT,0,2);
 outtextxy(275,385,"LOADING...");

 //alternate rotation selector
	   //forward swing
	   for(t=270; t<=720; t+=30) //720 instead of 630
	   {    if(t<360)
		{setcolor(BLUE);
		 setfillstyle(SOLID_FILL,BLUE);
		 circle((midx+radius*cos(t*3.14/180.0)),(midy+radius*sin(t*3.14/180.0)),2);
		 floodfill((midx+radius*cos(t*3.14/180.0)),(midy+radius*sin(t*3.14/180.0)),BLUE);
		}
		else if(t<630)
		{
		    setcolor(BLUE);
		    setfillstyle(SOLID_FILL,BLUE);
		    circle((midx+radius*cos(t*3.14/180.0)),(midy+radius*sin(t*3.14/180.0)),2);
		    floodfill((midx+radius*cos(t*3.14/180.0)),(midy+radius*sin(t*3.14/180.0)),BLUE);


		setfillstyle(EMPTY_FILL,0);
		floodfill((midx+radius*cos((t-90)*3.14/180.0)),(midy+radius*sin((t-90)*3.14/180.0)),BLUE);
		setcolor(0);
		circle((midx+radius*cos((t-90)*3.14/180.0)),(midy+radius*sin((t-90)*3.14/180.0)),2);
		}
		else
		{setfillstyle(EMPTY_FILL,0);
		floodfill((midx+radius*cos((t-90)*3.14/180.0)),(midy+radius*sin((t-90)*3.14/180.0)),BLUE);
		setcolor(0);
		circle((midx+radius*cos((t-90)*3.14/180.0)),(midy+radius*sin((t-90)*3.14/180.0)),2);

		}

		delay(150);
	   }

	   //reverse swing
	    for(t=90;t<=540;t+=30)  //450 to 540
	   {
		 if(t<180)
		{


		 setcolor(BLUE);
		 setfillstyle(SOLID_FILL,BLUE);
		circle((midx+radius*cos(t*3.14/180.0)),(midy+radius*sin(t*3.14/180.0)),2);

		floodfill((midx+radius*cos(t*3.14/180.0)),(midy+radius*sin(t*3.14/180.0)),BLUE);

		}
		else if(t<=450)
		{
		 setcolor(BLUE);
		 setfillstyle(SOLID_FILL,BLUE);
		 circle((midx+radius*cos(t*3.14/180.0)),(midy+radius*sin(t*3.14/180.0)),2);
		 floodfill((midx+radius*cos(t*3.14/180.0)),(midy+radius*sin(t*3.14/180.0)),BLUE);


		setfillstyle(EMPTY_FILL,0);
		floodfill((midx+radius*cos((t-90)*3.14/180.0)),(midy+radius*sin((t-90)*3.14/180.0)),BLUE);
		setcolor(0);
		circle((midx+radius*cos((t-90)*3.14/180.0)),(midy+radius*sin((t-90)*3.14/180.0)),2);
		}
		else
		{
		setfillstyle(EMPTY_FILL,0);
		floodfill((midx+radius*cos((t-90)*3.14/180.0)),(midy+radius*sin((t-90)*3.14/180.0)),getmaxcolor()); //can change to blue
		setcolor(0);
		circle((midx+radius*cos((t-90)*3.14/180.0)),(midy+radius*sin((t-90)*3.14/180.0)),2);
		}

		delay(200);
	   }
 setcolor(GREEN);
 settextstyle(DEFAULT_FONT,0,1);
 cleardevice();
 outtextxy(400,400,"Press any key to continue...");
 getch();
}
class CAR
{
  public:
    int vel ,level,xpos,ypos,life;
    long int score;
    long int levelmax[ 3];
    CAR()
    {
    level = 0;
    vel = 1;
    xpos= 240;
    ypos=400;
    score = 0;
    levelmax[ 0 ] = 10000;
    levelmax[ 1 ] = 20000;
    levelmax[ 2 ] = 30000;
    }
    void CAR::left();
    void CAR::right();
    void CAR::draw();


}car;
void CAR::left()
  {  if ( car.xpos > 10 )
    {
	car.xpos -= 20;
    }
  }
 void CAR::right()
    {
    if ( car.xpos < (490 -40))
	{
	 car.xpos+= 20;
	}
    return ;
    }
 void CAR::draw()
   {setcolor(MAGENTA);   //car begins
    setfillstyle(SOLID_FILL,RED);
    bar3d(xpos,ypos,xpos+40,ypos+40,2,3);
    setcolor(YELLOW);
    setfillstyle(SOLID_FILL,YELLOW);
    bar3d(xpos,ypos+40,xpos+10,ypos+45,2,3);
    bar3d(xpos+30,ypos+40,xpos+40,ypos+45,2,3);//car ends
   }
class obstacle
{public:
 int xdisp,ydisp,radius;
 int colour;
 obstacle()
 {radius=20;
  colour=rand()%6;
 }
 void xdisp_rand()
 {
  int i;int dummy=10;
  randomize();
  i=rand()%12;
  if(i==0)
  xdisp=((2*i+1)*radius+dummy);
  else
  xdisp=((2*i+1)*radius);
 }

 void obstacle_draw()
 {if ( ydisp< 480 )
    {
      ydisp+= 10;
      setcolor(getmaxcolor());
      setfillstyle( 1,colour);
      circle(xdisp,ydisp,radius);
      floodfill(xdisp,ydisp,getmaxcolor());
    }
    else
    {
      ydisp= 0;
    }
 }

 void move_obstacle()
 {if ( ydisp== 0 )
	{
		xdisp_rand();
		ydisp++;
	}
	else if ( ydisp< 0 )
	{ydisp++;
	}
	else
	{
		obstacle_draw();
	}
 }

 int  col_detect()
 {int i,arr[7];
  arr[0]=sqrt(pow((car.xpos-xdisp),2)+pow((car.ypos-ydisp),2));
  arr[1]=sqrt(pow(((car.xpos+20)-xdisp),2)+pow((car.ypos-ydisp),2));
  arr[2]=sqrt(pow(((car.xpos+40)-xdisp),2)+pow((car.ypos-ydisp),2));
  arr[3]=sqrt(pow((car.xpos-xdisp),2)+pow(((car.ypos+20)-ydisp),2));
  arr[4]=sqrt(pow((car.xpos-xdisp),2)+pow(((car.ypos+40)-ydisp),2));
  arr[5]=sqrt(pow(((car.xpos+20)-xdisp),2)+pow(((car.ypos+20)-ydisp),2));
  arr[6]=sqrt(pow(((car.xpos+40)-xdisp),2)+pow(((car.ypos+40)-ydisp),2));

  for(i=0;i<7;i++)
  { if(arr[i]<=radius)
	{return(1);}
  }
  return(0);
 }

}obs1,obs2,obs3;


void pause()
{while(!kbhit());}

class phighscore
{
public:
char name[30];
long int score;
friend void sort_display();

void input()
{cleardevice();char ch;
cout<<"\npress enter to fill details else q to quit;";
while((ch=getch())!=ENTER)
{if(ch=='q')
  return;
}
cleardevice();
fstream file;
settextstyle(DEFAULT_FONT,0,2);
outtextxy(100,50,"ENTER SCORE DETAILS");
settextstyle(DEFAULT_FONT,0,0);
outtextxy(100,200,"enter player name:");
gotoxy(25,15);
cin.seekg(0,ios::end);
cin.getline(name,10,'\n');
score=car.score;
file.open("hiscore.bin",ios::out | ios::binary |ios::app);
file.write((char*)this,sizeof(phighscore));
file.close();
}

};



void  sort_display()
{ cleardevice();
  phighscore temp;phighscore players[10];
  fstream file;
  int i,j=0; char str[20];
  phighscore *p;
  p=new phighscore[sizeof(phighscore)];
  file.open("hiscore.bin",ios::in | ios::binary);
  file.seekg(0,ios::beg);

  while(file.read((char*)p,sizeof(phighscore))!=NULL)
  {
  strcpy(players[j].name,p->name);
  players[j].score=p->score;
  n=j++;
  }

  file.close();
  for(i=0;i<n;i++)
 {
        for(j=0;j<n-i;j++)
        {
        if((players[j].score)< (players[j+1].score))
        {
        temp=players[j];
        players[j]= players[j+1];
        players[j+1]=temp;
        }
        }
}

 settextstyle(DEFAULT_FONT,0,2);
 outtextxy(1*getmaxx()/3,50,"HIGH SCORES");
 setcolor(WHITE);
for(i=0;i<n;i++)
 {
 sprintf(str,"%ld",players[i].score);
 settextstyle(DEFAULT_FONT,0,0);
 outtextxy(200,150+i*50,players[i].name);
 outtextxy(400,150+i*50,str);
 }

}

void modify_details(int *life)
{    int level=car.level; phighscore current;
    car.score = car.score + 10*car.vel;
    setcolor( 5 );
    settextstyle( 2, 0, 6 );
    outtextxy( 530, 10, "Score " );
    gotoxy( 75, 2 );
    cout << car.score;


    if ( car.score > car.levelmax[ level ] )
    {
      if ( car.level < 2 )//max level 3
      {
	car.level++;
        settextstyle(DEFAULT_FONT,0,3);
        outtextxy(250,250,"YOU ARE UPGRADED TO NEXT LEVEL");
        delay(2000);
        car.vel++;
     }
      else
       {cleardevice();
        setcolor(GREEN);
	settextstyle(GOTHIC_FONT, 0, 2);
	outtextxy(1*getmaxx()/3,getmaxy()/2,"YOU WON THE GAME");
        delay(1500);
        current.input();
	return;

       }
    }
    outtextxy(530,30,"Level");
    gotoxy(75,3);
    cout<< car.level;
    outtextxy(530, 50, "Life" );
    gotoxy( 75, 4);cout << *life;
    return ;
}


void move_background(int  *life)
{   int i,z;
    z=(i+40)/car.vel;
    car.draw();
    for (i = 0;i < 480;i += 50 )
    {
    setcolor( WHITE);
    setfillstyle( 8, WHITE );
    bar( 0, i, 10, z);
    bar( 490, i , 500, z);
    }
    modify_details(life);
    return ;
}

int play_game()
{
    int life = 3, ch;  obs1.ydisp=0;obs2.ydisp=-20;obs3.ydisp=-40; phighscore current;
 reentry:
    while ( life )
    {
	cleardevice();
	delay(5/car.vel);
	obs1.move_obstacle();
	obs2.move_obstacle();
	obs3.move_obstacle();
	move_background(&life);

   if(obs1.col_detect()||obs2.col_detect()||obs3.col_detect())
	{
		cleardevice();
                setcolor(WHITE);
		settextstyle(GOTHIC_FONT, 0, 5);
		outtextxy(1*getmaxx()/3,getmaxy()/2,"You lost a life");
		delay(1000);
		life--;
		if ( life == 0 )
		{cleardevice();
                setcolor(WHITE);
                settextstyle(GOTHIC_FONT,0, 5);
		outtextxy(1*getmaxx()/3,getmaxy()/2," GAME OVER");
		delay(1500);
                current.input();
                car.score=0;
	        return 0;
		}
		obs1.ydisp= 5;
		obs2.ydisp= -15;
		obs3.ydisp=-25;
	goto reentry;
	}
    if ( kbhit() )
    {
       ch = getch();
       switch ( ch )
       {
	case LEFT: car.left();delay(200);
	break;
	case RIGHT: car.right();delay(200);
	break;
        case 'p':pause();break;

	case 'q': return(0);
	}
    }
    else
	{
	delay( 500 );
	}
    }
    getch();
    return ( 0 );
}
void high_score()
{sort_display();
 getch();
}
void instruction()
{
cleardevice();
setcolor(RED);
settextstyle(DEFAULT_FONT,0,2);
setfillstyle(4,RED);
outtextxy(1*getmaxx()/3,50,"INSTRUCTION");
bar(200,80,400,85);
setcolor(WHITE);
settextstyle(DEFAULT_FONT,0,0);
setfillstyle(4,WHITE);
outtextxy(80,100,"The objective of the game is to avoid the circular obstacles from");
outtextxy(80,120,"hitting the car");
outtextxy(80,140,"The controls used are:");
outtextxy(80,160,"<-     to move left");
outtextxy(80,180,"->     to move right");
outtextxy(80,200,"p      to pause the game");
outtextxy(80,220,"q      to quit");
outtextxy(300,400,"press any key to go back to main menu");

getch();
return;

}
void about_us()
{
cleardevice();
setcolor(RED);
settextstyle(DEFAULT_FONT,0,2);
setfillstyle(4,RED);
outtextxy(1*getmaxx()/3,50,"ABOUT US");
bar(200,80,400,85);
setcolor(WHITE);
settextstyle(DEFAULT_FONT,0,0);
setfillstyle(4,WHITE);
outtextxy(20,100,"The project is dated to FEb 2014...I thank my friends Varun JM and ");
outtextxy(20,120,"Shrinidhi Kanchi for their kind motivation which led to the success of this game..");
outtextxy(20,140,"The game has been created by Kiran B R and Kavya Puranik of 6th CS SJCE");
outtextxy(0,400,"The copyright of this game is owned by ");
outtextxy(0,420,"Kiran B R ");
setcolor(GREEN);
settextstyle(DEFAULT_FONT,0,0);
setfillstyle(4,GREEN);
outtextxy(300,460,"press any key to go back to main menu");

getch();
return;
}
void main_menu()
{
    int select= 1,ch, y= 140;
    do
    {
	do
	{
	 cleardevice();
	 setcolor(MAGENTA);
	 settextstyle(DEFAULT_FONT, 0, 4);
	 setfillstyle(SLASH_FILL, RED);
	 outtextxy( 230, 30, "MENU" );
	 settextstyle( DEFAULT_FONT, 0, 2 );
	 setcolor(BLUE);
	 outtextxy( 200, 140, "1.PLAY GAME" );
	 outtextxy( 200, 190, "2.HIGH SCORE" );
	 outtextxy( 200, 240, "3.INSTRUCTION" );
	 outtextxy( 200, 290, "4.ABOUT US" );
	 outtextxy( 200, 340, "5.EXIT" );
	 setcolor(RED);
	 rectangle( 25, y-25,600, y+25);
	 ch= getch();
    switch ( ch)
    {
    case UP:
		if ( y> 140 )
		{
		y-= 50;
		select--;
		}
                else
                {y=340;
                select=5;
                }
		break;
    case DOWN: if ( y< 340 )
		{
		y+= 50;
		select++;
		}
                else
                {y=140;
                 select+=4;
                }
		break;
    case ENTER: ch = 1;
		break;
    default: break;
    }
   }while (ch != 1 );


   switch ( select )
    {
    case 1:play_game();
    break;
    case 2: high_score();
    break;
    case 3: instruction();
    break;
    case 4: about_us();
    break;
    case 5:cleardevice();
           exit( 0 );
    break;
    }
 }while (1);

}

int main()
{ int gd,gm,errorcode;
  gd=DETECT;
  initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
   errorcode = graphresult();
  if (errorcode != grOk)
  {
   printf("Graphics error: %s\n", grapherrormsg(errorcode));
   printf("Press any key to halt:");
   getch();
   exit(1);
  }
   cleardevice;
   startup();
   main_menu();
   closegraph();
   return 0;
}
