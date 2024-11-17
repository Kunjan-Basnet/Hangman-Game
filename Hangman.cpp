#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<fstream.h>

union REGS in,out;
int button,x,y,xmouse=0,ymouse=0,play1=0,play2=0,temp1=0,exit1=0,exit2=0;
int help1=0,help2=0,play3,help3,i,j,exit3,score=0,highscore3;
int highscore1=0,highscore2=0;
char words[60][60]={"algorithm","flowchart","petabyte","modem","internet","bandwidth","database","diligence","hypertext","uniform","resource","locator","excite","garbage","liquid","crystal","display","cathode","tube","light","diode","joystick","inverter","simplex","buffer","accumulator","frames","asynchronous","digital","video","graphics","data","analog","hybrid"};
char word[60];
char name[50];
void play();
void menuhangman();
void help();
void getmouse(int *button,int *x,int *y);
int checkmidno(int start,int end,int coordinate);
void defult(int length);
void drawing(int incorrectcount);
void congo();
void loading();
void savescore();
void showscore();
//here is your main
void main()
{clrscr();

loading();
label1:
menuhangman();
in.x.ax=0;
int86(0x33,&in,&out);
in.x.ax=1;
int86(0x33,&in,&out);

while(1)
{
getmouse(&button,&x,&y);
play1=checkmidno(100,300,xmouse);
play2=checkmidno(40,70,ymouse);
exit1=checkmidno(100,300,xmouse);
exit2=checkmidno(340,370,ymouse);
help1=checkmidno(100,300,xmouse);
help2=checkmidno(140,170,ymouse);
highscore1=checkmidno(100,300,xmouse);
highscore2=checkmidno(240,270,ymouse);


if(button==1)
{
if(play1==1&&play2==1)
{
break;
}//play1,2 ko if
if(help1==1&&help2==1)
{
break;
}
if(exit1==1&&exit2==1)
{
break;
}
if(highscore1==1&&highscore2==1)
{
break;
}





}//button if


}
closegraph();
help3=0;
exit3=0;
play3=0;
highscore3=0;
menuhangman();
if(help3==1)
{help();
goto label1;
}//help ko sakkako
if (play3==1)
{
play();

}
if (exit3==1)
{
exit(0);

}
/*if (highscore3=1)
{
showscore();
goto label1;

} */







getch();


}

void play()
{

int gd=DETECT,gm;
initgraph(&gd,&gm,"c:\\TURBOC3\\bgi");
cout<<"ENTER YOUR NAME"<<endl;
cin>>name;
loading();
int random,length,i,j=0,incorrect=1,k=0,incorrectcount=0,t;
int noofcorrect=0;
srand(time(0));
random=rand()%34;
cout<<random;

char letter[1];

strcpy(word,words[random]);
length =strlen(word);
defult(length);
for (t=0;t<17;t++)
{
cin>>letter[0];
letter[1]=NULL;
for(i=0;i<length;i++)//checking process
{
if(word[i]==letter[0])
{setfillstyle(SOLID_FILL,GREEN);
rectangle(100,150,300,190);
floodfill(150,170,WHITE);
setcolor(RED);
outtextxy(135,165,"you are correct");
score++;
setcolor(WHITE);
sound(500);
delay(200);
nosound();
incorrect=0;
settextstyle(8,0,2);//here if error
outtextxy(125+k,77,letter);
settextstyle(0,0,0);
noofcorrect++;

} //1st if ko sakkyo

k=k+32;
} //for for checking sakkyo
k=0;
if(incorrect!=0)
{
setfillstyle(SOLID_FILL,RED);
rectangle(100,150,300,190);
floodfill(150,170,WHITE);
setcolor(GREEN);
outtextxy(135,165,"you are incorrect");

setcolor(WHITE);
sound(150);
delay(200);
nosound();
incorrectcount++;
drawing(incorrectcount);
}
incorrect=1;
if(noofcorrect==length)
{
score=6;
savescore();

congo();
getch();
main();

}



}//t wala for ko end
t=0;
score=0;

//exit(0);

}

void defult(int length)
{
int gd=DETECT,gm;
initgraph(&gd,&gm,"c:\\TURBOC3\\bgi");
line(450,15,450,400);//tree vertical yi chai default nai halnu parni vara
line(450,15,650,15);//tree horizontal

//outtextxy(20,20,"hello");

if(strcmp(word,"algorithm")==0)
{outtextxy(5,20,"step by step set of instruction is");
}
else if(strcmp(word,"flowchart")==0)
{outtextxy(5,20,"graphical representation of algorithm");
}
else if(strcmp(word,"petabyte")==0)
{outtextxy(20,20,"1024 terabytes is equal to one");
}
else if(strcmp(word,"modem")==0)
{outtextxy(20,20,"Device that converts analog signal");
}
else if(strcmp(word,"internet")==0)
{outtextxy(20,20,"interconnection of millions of computers ");
}
else if(strcmp(word,"bandwidth")==0)
{outtextxy(20,20,"maximum rate of data transfer is ");
}
else if(strcmp(word,"database")==0)
{outtextxy(20,20,"collection of organized data");
}
else if(strcmp(word,"diligence")==0)
{outtextxy(20,20,"capacity of computer to perform repetitive task ");
}
else if(strcmp(word,"hypertext")==0)
{outtextxy(20,20,"The HT in HTTP stands for ");
}
else if(strcmp(word,"uniform")==0)
{outtextxy(20,20,"The U in URL stands for");
}
else if(strcmp(word,"resource")==0)
{outtextxy(20,20,"The R in URL stands for");
}
else if(strcmp(word,"locator")==0)
{outtextxy(20,20,"The L in URL stands for");
}
else if(strcmp(word,"excite")==0)
{outtextxy(20,20,"It is the name of search engine");
}
else if(strcmp(word,"garbage")==0)
{outtextxy(20,20,"The G in GIGO stands for");
}

else if(strcmp(word,"liquid")==0)
{outtextxy(20,20,"L in LCD stands for");
}
else if(strcmp(word,"crystal")==0)
{outtextxy(20,20,"C in LCD stands for");
}
else if(strcmp(word,"display")==0)
{outtextxy(20,20,"D in LCD stands for");
}
else if(strcmp(word,"cathode")==0)
{outtextxy(20,20,"C in CRT stands for");
}
else if(strcmp(word,"tube")==0)
{outtextxy(20,20,"T in CRT stands for");
}
else if(strcmp(word,"light")==0)
{outtextxy(20,20,"L in LED stands for");
}
else if(strcmp(word,"diode")==0)
{outtextxy(20,20,"D in LED stands for");
}
else if(strcmp(word,"joystick")==0)
{outtextxy(20,20,"Input device used for gaming");
}
else if(strcmp(word,"inverter")==0)
{ outtextxy(20,20,"NOT gate is also known as");
}
else if(strcmp(word,"simplex")==0)
{outtextxy(20,20,"data transfer mode where receiver has no role,");
}
else if(strcmp(word,"buffer")==0)
{outtextxy(20,20,"B in MBR stands for");
}
else if(strcmp(word,"accumulator")==0)
{outtextxy(20,20,"In terms of computer AC stands for");
}
else if(strcmp(word,"frames")==0)
{outtextxy(20,20,"Magnetic tapes are divided into vertical column called");
}
else if(strcmp(word,"asynchronous")==0)
{outtextxy(20,20,"A in ADSL stands for");
}
else if(strcmp(word,"digital")==0)
{outtextxy(20,20,"D in ADSL stands for");
}
else if(strcmp(word,"video")==0)
{outtextxy(20,20,"V in VGA stands for");
}
else if(strcmp(word,"graphics")==0)
{outtextxy(20,20,"G in VGA stands for");
}
else if(strcmp(word,"data")==0)
{outtextxy(20,20,"Collection of raw facts ");
}
else if(strcmp(word,"analog")==0)
{outtextxy(20,20," computer that measure physical values");
}
else if(strcmp(word,"hybrid")==0)
{outtextxy(20,20,"computer having features of both analog and digital");
}

//to show thre above screen
//outtextxy(100,50,"your word has been generated");
for(i=1;i<=length;i++)
{
outtextxy(125+j,100,"___ ");
j=j+30;
}
j=0;
//to move the pointer all the way  down
for(i=0;i<=12;i++)
{
cout<<"\n";

}
cout<<"enter your guess \n";






}

void menuhangman()
{
int gd=DETECT,gm;
initgraph(&gd,&gm,"c:\\TURBOC3\\bgi");
//buttons
//play
setcolor(RED);
setfillstyle(SOLID_FILL,RED);
rectangle(100,40,300,70);
floodfill(101,41,RED);
setcolor(GREEN);
outtextxy(180,50,"PLAY");
if(play1==1&&play2==1&&button==1)
{

play3=1;

}
else
{outtextxy(80,450,"Input your choice with mouse");
}
//help
setcolor(RED);
setfillstyle(SOLID_FILL,RED);
rectangle(100,140,300,170);
floodfill(101,141,RED);

setcolor(GREEN);
outtextxy(180,150,"HELP");


if(help1==1&&help2==1&&button==1)
{

help3=1;

}

//high score
setcolor(RED);
setfillstyle(SOLID_FILL,RED);
rectangle(100,240,300,270);
floodfill(101,241,RED);

setcolor(GREEN);
outtextxy(160,250,"HIGHSCORE");
if(highscore1==1&&highscore2==1&&button==1)
{

//outtextxy(500,300,"Highscore=10");

}

//exit
setcolor(RED);
setfillstyle(SOLID_FILL,RED);
rectangle(100,340,300,370);
floodfill(101,341,RED);

setcolor(GREEN);
outtextxy(180,350,"EXIT");
if(exit1==1&&exit2==1&&button==1)
{exit1=0;
exit2=0;
exit3=1;
}





//tree
line(450,15,450,400);//tree vertical
line(450,15,650,15);//tree horizontal

//human

line(550,15,550,50);//rope
circle(550,100,50);//head
circle(525,90,5);
circle(575,90,5);

arc(550,160,50,130,40);

line(550,150,550,350);//spinal cord

line(550,350,600,400);//right leg

line(550,350,500,400);//left leg

line(550,250,500,250);//left hand

line(550,250,600,250);//right hand

}
void getmouse(int *button,int *x,int *y)
{

in.x.ax=3;
int86(0x33,&in,&out);
*button=out.x.bx;
*x=out.x.cx;
*y=out.x.dx;
xmouse=*x;
ymouse=*y;
}
int checkmidno(int start,int end,int coordinate)
{
int i;
for(i=start;i<=end;i++)
{
if(coordinate==i)
{return(1);}
}
}
void help()
{closegraph();
//clearscr();
int gd=DETECT,gm;
initgraph(&gd,&gm,"c:\\TURBOC3\\bgi");
outtextxy(100,25,"FOLLOW THE INSTRUCTIONS TO PLAY THE GAME:");
outtextxy(100,50,"-> CAREFULLY LOOK AT THE GIVEN HINTS");
outtextxy(100,75,"-> GUESS A LETTER THAT IS IN SECRET WORD WHICH FILLS THE BLANKSPACE");
outtextxy(100,100,"-> GUESS ONE LETTER AT A TIME");
outtextxy(100,125,"-> ONE WRONG GUESS WILL DRAW ONE BODY PART OF HANGMAN");
outtextxy(100,150,"-> GAME WILL TERMINATE IF USER GUESS ALL THE WORD CORRECTLY");
outtextxy(100,175,"-> GAME WILL ALSO TERMINATE IF USER GUESS WRONG AND COMPLETELY");
outtextxy(100,200,"   DRAWN HANGMAN IS APPEARED IN THE SCREEN");
outtextxy(100,400,"PRESS ANY KEY TO CONTINUE......");
getch();
}
void drawing(int incorrectcount)
{
switch(incorrectcount)
{
case 1:
line(550,15,550,50);//rope
outtextxy(450,450,"guess=1");
break;
case 2:
circle(550,100,50);//head
outtextxy(525,75,"x");
outtextxy(575,75,"x");
outtextxy(450,450,"guess=1,2");
break;
case 3:
line(550,150,550,350);//spinal cord
outtextxy(450,450,"guess=1,2,3");
break;
case 4:
line(550,250,500,300);//left hand
outtextxy(450,450,"guess=1,2,3,4");
break;
case 5:
line(550,250,600,300);//right hand
outtextxy(450,450,"guess=1,2,3,4,5");
break;
case 6:
line(550,350,500,400);//left leg
outtextxy(450,450,"guess=1,2,3,4,5,6");
break;
case 7:
line(550,350,600,400);//right leg
outtextxy(450,450,"guess=1,2,3,4,5,6,7");
score=0;
cout<<"you could not guess the correct word was \n" <<word<<"\n press any key ko exit";
getch();
main();
break;
default:
cout<<"impossible";
break;






}//switch ko end

}

void congo()
{

int gd=DETECT,gm;
initgraph(&gd,&gm,"c:\\TURBOC3\\bgi");
int cp=0,cs,cz=0,ct=0;
for(cs=0;cs<25;cs++)
{
cout<<"\n";

}

cout<<"\t \t \t press any key to return \n"<<"\t \t \t to the main menu";
while(!kbhit())
{settextstyle(8,0,5);
setcolor(cp);
outtextxy(70,50,"CONGRATULTIONS ");
outtextxy(70,150,"YOU ");
outtextxy(70,250,"WON");
ct=400-cz;
if(ct>50)
{
setcolor(WHITE);


//circle(50,400-z,50);
ellipse(50,400-cz,0,360,30,50);

line(50,450-cz,50,500-cz);
setfillstyle(SOLID_FILL,RED);
floodfill(51,351-cz,WHITE);
//circle(550,400-z,50);
ellipse(550,400-cz,0,360,30,50);
line(550,450-cz,550,500-cz);
setfillstyle(SOLID_FILL,RED);
floodfill(551,351-cz,WHITE);
delay(500);
setfillstyle(SOLID_FILL,BLACK);
floodfill(51,351-cz,BLACK);
setfillstyle(SOLID_FILL,BLACK);
floodfill(551,351-cz,BLACK);

cz=cz+50;

}
cp=(cp+1)%10;

setcolor(WHITE);
}




cp=0;
cs=0;cz=0;
ct=0;
}
void loading()
{


	int li,lk=205,lavg,lt,ltemp;

	int gd=DETECT,gm;
	initgraph(&gd,&gm,"c:\\TURBOC3\\bgi");



	outtextxy(145,238,"LOADING");//loading start
	rectangle(700,230,1000,250);

	for(li=0;li<=280;li=li+10)
	{
	delay(50);//delay here for loading
	rectangle(205,235,215+li,245);
	ltemp=lk;
	lk=215+li;
	lt=ltemp+lk;
	lavg=lt/2;
	setfillstyle(1,11);
	floodfill(lavg,237,15);
    }//loading end
li=0;
lk=205;
lavg=0;
lt=0;
ltemp=0;
closegraph();







}

void savescore()
{
ofstream fout;

fout.open("name.txt",ios::app|ios::out);
fout<<name<<"\n";
fout.close();
}
void showscore()
{
int gd=DETECT,gm;
initgraph(&gd,&gm,"c:\\TURBOC3\\bgi");

ofstream fout;
fout.open("score.txt",ios::app|ios::out);
fout<<score<<"\n";
fout.close();
ifstream fin;
fin.open("name.txt",ios::in);
while(!fin.eof())
{fin>>name;
cout<<"name\t"<<name<<"\n";
}
fin.close();
fin.open("score.txt",ios::in);
while(!fin.eof())
{
fin>>score;
cout<<"\t\tscore\t"<<score<<"\n";
}
fin.close();
getch();
}















