#include<windows.h>
#ifdef_APPLE_
#include <GLUT/glut.h>
#else
#include<GL/glut.h>
#endif
#include<stdlib.h>
#include<stdio.h>
#include<iostram.h>
#include<string>

//game speed
int FPS =50;

//game track
int start=0;
int gv =0;
int level =0;

//track score
int score =0;

//form move track
int roadDivTopMost =0;
int roadDivTop =0;
int roadDivMd1 =0;
int roadDivBtm =0;

//for card left and right
int lrIndex =0;

//car coming
int car1 =0;
int lrIndex1 =0;
int lrIndex1 =0;
int car2 = +35;
int lrINdex2 =0;
int car3 =+70;
int lrIndex3=0;

//for display text
const int font1 =(int)GLUT_BITMAP_TIMES_ROMAN_24;
const int font2 =(int)GLUT_BITMAP_HELVETICA_18;
const int font3 =(int)GLUT_BITMAP_8_BY_13;

char s[30];
void renderBitmapString(float x,float y,void*font,const char*string)
{
const char*c;
glRasterPos2f(x,y);
for(c=string;*c !='\0'; c++)
{
glutBitmapCharacter(font, *c);
}
}


void tree(int x,int y)
{
int new x=x;
int new y=y;

//tree left
//bottom
glcolor3f(0.871,0.722,0.529);
glBegin(GL_TRIANGLE);
glVertex2f(newx+11,new+55);
glVertex2f(newx+12,new+55-10);
glVertex2f(newx+10,new+55-10);
glEnd();

//up
glcolor3f(0.133,0.545,0.133);
glBegin(GL_TRIANGLE);
glVertex2f(newx+11,new+55+3);
glVertex2f(newx+12+3,new+55-3);
glVertex2f(newx+10-3,new+55-3);
glEnd();

void startGame()
{
//road
glcolor3f(0.412,0.412,0.412);
glBegin(GL_POLYGON);
glVertex2f(20,0);
glVertex2f(20,100);
glVertex2f(80,100);
glVertex2f(80,0);
glEnd();


//road left border
glcolor3f(1.000,1.000,1.000);
glBegin(GL_POLYGON);
glVertex2f(20,0);
glVertex2f(20,100);
glVertex2f(23,100);
glVertex2f(23,0);
glEnd();

//road right border
glcolor3f(1.000,1.000,1.000);
glBegin(GL_POLYGON);
glVertex2f(77,0);
glVertex2f(77,100);
glVertex2f(80,100);
glVertex2f(80,0);
glEnd();

//road midLe border
//top
glcolor3f(1.000,0.412,0.412);
glBegin(GL_POLYGON);
glVertex2f(48,roadDivTop+80);
glVertex2f(48,roadDivTop+100);
glVertex2f(52,roadDivTop+100);
glVertex2f(52,roadDivTop+80);
glEnd();
roadDivTop--;
if(roadDivTop<-100)
{
roadDivTop =20;
score++;
}


//Middle
glColor3f(1.000,0.412,0.000);
glBegin(GL_POLYGON);
glVertex2f(48,roadDivTop+40);
glVertex2f(48,roadDivTop+60);
glVertex2f(52,roadDivTop+60);
glVertex2f(52,roadDivTop+40);
glEnd();

roadDivTop--;
if(roadDivMd1<-60)
{
roadDivMd1 =60;
score++;
}
//bottom

glColor3f(1.000,1.000,0.000);
glBegin(GL_POLYGON);
glVertex2f(48,roadDivTop+0);
glVertex2f(48,roadDivTop+20);
glVertex2f(52,roadDivTop+20);
glVertex2f(52,roadDivTop+0);
glEnd();
roadDivBtm--;
if(roadDivBtm<-20)
{
roadDivBtm =100;
score++;
}

//score board

glColor3f(0.000,0.000,0.000);
glBegin(GL_POLYGON);
glVertex2f(80,97);
glVertex2f(100,97);
glVertex2f(100,98-8);
glVertex2f(80,98-0);
glEnd();

//print score
char buffer [50];
sprintf(buffer,"SCORE: %d",score);
glcolor3f(0.000,1.000,0.000);
renderBitmapString(80.5,95,(void *)font3,buffer);

//speed print
char buffer1 [50];
sprintf(buffer1, "SPEED:%dkm/h",FPS);
glcolor3f(0.000,1.000,0.000);
renderBitmapString(80.5,95-2,(void *)font3,buffer);

//level print

if(score % 50 ==0)
{
int last = score/50;
if(last !=level)
{
level =score/50;
FPS=FPS+2;
}
}
char level_buffer [50];
sprintf(level_buffer,"LEVEL : %d",level);
glColor3f(0.000,1.000,0.000);
renderBitmapString(80.5,95-4,(void *)font3,level_buffer);


//increse speed with level
//main car
//front tire
glColor3f(0.000,0.000,0.000);
glBegin(GL_POLYGON);
glVertex2f(lrIndex+26-2,5);
glVertex2f(lrIndex+26-2,7);
glVertex2f(lrIndex+30+2,7);
glVertex2f(lrIndex+30+2,5);
glEnd();

//back Tire
glColor3f(0.000,0.000,0.000);
glBegin(GL_POLYGON);
glVertex2f(lrIndex+26-2,1);
glVertex2f(lrIndex+26-2,3);
glVertex2f(lrIndex+30+2,3);
glVertex2f(lrIndex+30+2,1);
glEnd();

//car body

glColor3f(0.678,1.000,0.184);
glBegin(GL_POLYGON);
glVertex2f(lrIndex+26,1);
glVertex2f(lrIndex+26,8);
glColor3f(0.000,0.545,0.545);

glVertex2f(lrIndex+28,10);
glVertex2f(lrIndex+30,8);
glVertex2f(lrIndex+30,1);
glEnd();

//opposite car1
glColor3f(0.000,0.000,0.000);
glBegin(GL_POLYGON);
glVertex2f(lrIndex+26-2,car1+100-4);
glVertex2f(lrIndex+26-2,car1+100-6);
glVertex2f(lrIndex+30+2,car1+100-6);
glVertex2f(lrIndex+30+2,car1+100-4);
glEnd();

glColor3f(0.000,0.000,0.000);
glBegin(GL_POLYGON);
glVertex2f(lrIndex+26-2,car1+100);
glVertex2f(lrIndex+26-2,car1+100-2);
glVertex2f(lrIndex+30+2,car1+100-2);
glVertex2f(lrIndex+30+2,car1+100);
glEnd();

glColor3f(0.000,0.000,0.000);
glBegin(GL_POLYGON);
glVertex2f(lrIndex+26-2,car1+100);
glVertex2f(lrIndex+26-2,car1+100-7);
glVertex2f(lrIndex+30+2,car1+100-9);
glVertex2f(lrIndex+26-2,car1+100-7);
glVertex2f(lrIndex+30+2,car1+100);
glEnd();
car1--;
if(car1<-100)
{
car1=0;
lrIndex1=lrIndex;
}

//kill check car1
if((abs(lrIndex-lrIndex1)<8) && (car1+100<10))
{
start =0;
gv=1;
}

//opposite car2

glColor3f(0.000,0.000,0.000);
glBegin(GL_POLYGON);
glVertex2f(lrIndex+26-2,car2+100-4);
glVertex2f(lrIndex+26-2,car2+100-6);
glVertex2f(lrIndex+30+2,car2+100-6);
glVertex2f(lrIndex+30+2,car2+100-4);
glEnd();


glColor3f(0.000,0.000,0.000);
glBegin(GL_POLYGON);
glVertex2f(lrIndex+26-2,car2+100);
glVertex2f(lrIndex+26-2,car2+100-2);
glVertex2f(lrIndex+30+2,car2+100-2);
glVertex2f(lrIndex+30+2,car2+100);
glEnd();


glColor3f(0.294,0.000,0.510);
glBegin(GL_POLYGON);
glVertex2f(lrIndex+26,car2+100);
glVertex2f(lrIndex+26,car2+100-7);
glVertex2f(lrIndex+28,car2+100-9);
glVertex2f(lrIndex+30,car2+100-7);
glVertex2f(lrIndex+30,car2+100);
glEnd();
car2--;
if(car2<-100)
{
car2=0;
lrIndex2=lrIndex;
}

//kill check car1
if((abs(lrIndex-lrIndex1)<8) && (car2+100<10))
{
start =0;
gv=1;
}

//opposite car3
glColor3f(0.000,0.000,0.000);
glBegin(GL_POLYGON);
glVertex2f(lrIndex+26-2,car3+100-4);
glVertex2f(lrIndex+26-2,car3+100-6);
glVertex2f(lrIndex+30+2,car3+100-6);
glVertex2f(lrIndex+30+2,car3+100-4);
glEnd();


glColor3f(0.000,0.000,0.000);
glBegin(GL_POLYGON);
glVertex2f(lrIndex+26-2,car3+100);
glVertex2f(lrIndex+26-2,car3+100-2);
glVertex2f(lrIndex+30+2,car3+100-2);
glVertex2f(lrIndex+30+2,car3+100);
glEnd();


glColor3f(1.000,0.271,0.000);
glBegin(GL_POLYGON);
glVertex2f(lrIndex+26,car3+100);
glVertex2f(lrIndex+26,car3+100-7);
glVertex2f(lrIndex+28,car3+100-9);
glVertex2f(lrIndex+30,car3+100-7);
glVertex2f(lrIndex+30,car3+100);
glEnd();
car3--;
if(car3<-100)
{
car3=0;
lrIndex2=lrIndex;
}

//kill check car1
if((abs(lrIndex-lrIndex1)<8) && (car2+100<10))
{
start =0;
gv=1;
}


void fristDesign()
{
glColor3f(0.000,0.392,0.000);
glBegin(GL_POLYGON);
glVertex2f(0,55);
glVertex2f(100,55);
glColor3f(0.604,0.804,0.196);
glVertex2f(100,50-50);
glVertex2f(0,50-50);
glEnd();

//Road DEsign in FRont Paage

glColor3f(00,0,0);
glBegin(GL_TRIANGLE);
glVertex2f(32-2+21,55);
glVertex2f(32+58,55);
glVertex2f(32-22,50-50);
glEnd();

//road MIddle
glColor3f(1,1,1);
glBegin(GL_TRIANGLE);
glVertex2f(32-2+21,55);
glVertex2f(50+2,50-50);
glVertex2f(50-2,50-50);
glEnd();

//road sky
glColor3f(0.000,0.749,1.000);
glBegin(GL_POLYGON);
glVertex2f(100,100);
glVertex2f(0,100);
glColor3f(0.686,0.749,0.933);
glVertex2f(0,55);
glVertex2f(100,55);
glEnd();

//Hill 1
glColor3f(0.235,0.702,0.443);
glBegin(GL_TRIANGLE);
glVertex2f(20,55+10);
glVertex2f(20+7,55);
glVertex2f(0,55);
glEnd();

//hill 2
glColor3f(0.000,0.502,0.000);
glBegin(GL_TRIANGLE);
glVertex2f(20+15,55+12);
glVertex2f(20+20+10,55);
glVertex2f(0+10,55);
glEnd();

//hill 3
glColor3f(0.235,0.702,0.443);
glBegin(GL_TRIANGLE);
glVertex2f(87,55+10);
glVertex2f(100,55);
glVertex2f(60,55);
glEnd();

//hill4
glColor3f(0.000,0.502,0.000);
glBegin(GL_TRIANGLE);
glVertex2f(70,70);
glVertex2f(90,55);
glVertex2f(50,55);
glEnd();

//tree left
//bottom

glColor3f(0.871,0.722,0.529);
glBegin(GL_TRIANGLE);
glVertex2f(11,55);
glVertex2f(12,55-10);
glVertex2f(10,55-10);
glEnd();

//up

//hill 2
glColor3f(0.133,0.545,0.133);
glBegin(GL_TRIANGLE);
glVertex2f(11,55+3);
glVertex2f(12+3,55-3);
glVertex2f(10-3,55-3);
glEnd();

tree(5,_15);
tree(9,5);
tree(85,9);
tree(75,-5);



//menu place Holder
glColor3f(0.098,0.098,0.439);
glBegin(GL_POLYGON);
glVertex2f(32-4,50+5+10);
glVertex2f(32+46,50+5+10);
glVertex2f(32+46,50-15+10);
glVertex2f(32-4,50-15+10);
glEnd();

glColor3f(00,0,0.000);
glBegin(GL_POLYGON);
glVertex2f(32-4,50+5+10);
glVertex2f(32+46,50+5+10);
glVertex2f(32+46,50+4+10);
glVertex2f(32-4,50+4+10);
glEnd();
glBegin(GL_POLYGON);
glVertex2f(32-45,50+5+10);
glVertex2f(32+46,50+5+10);
glVertex2f(32+46,50-15+10);
glVertex2f(32-45,50-15+10);
glEnd();
glBegin(GL_POLYGON);
glVertex2f(32-4,50-14+10);
glVertex2f(32+46,50-14+10);
glVertex2f(32+46,50-15+10);
glVertex2f(32-4,50-15+10);
glEnd();
glVertex2f(32-4,50+5+10);
glVertex2f(32-5,50+5+10);
glVertex2f(32-5,50-15+10);
glVertex2f(32-4,50-15+10);
glEnd();

//text infomation in fist page
if(gv==1)
{
glColor3f(1.000, 0.000, 0.000);
renderBitmapString(35,60+10,(void *)font1,"Game Over");
glColor3f(1.000, 0.000, 0.000);
char buffer2[50];
sprintf(buffer2,"Your score is :%d",score);
renderBitmapString(33,60-4+10,(void *)font1,buffer2);

glColor3f(1.000, 1.000, 0.000);
renderBitmapString(30,80,(void *)font1,"2d CAR Racing Game");

glColor3f(0.000, 1.000, 0.000);
renderBitmapString(35,50+10,(void *)font2,"PRESS SPACE TO START");
renderBitmapString(35,50-3+10,(void *)font2,"PRESS ESC TO EXIT");

glColor3f(0.000, 1.000, 0.000);
renderBitmapString(30,50-6+10,(void *)font3,"PRESS UP to increase speed");
renderBitmapString(30,50-6+10,(void *)font3,"PRESS DOWN to decrease speed");
renderBitmapString(30,50-10+10,(void *)font3,"PRESS RIGHT to turn Right");
renderBitmapString(30,50-12+10,(void *)font3,"PRESS LEFT to turn Left");

glColor3f(0.000, 1.000, 1.000);
renderBitmapString(30-5,50-40,(void *)font3,"");
renderBitmapString(30-5,50-43,(void *)font3,"");


void display()
{
glClear(GL_COLOR_BUFFER_BIT);

if(start==1)
{
glClearColor(0.000, 0.392, 0.000, 1);
startGame();
}
else
{
firstDesign();
}
glFlush();
glutSwapBUffers();

void spe_key(int key , int x, int y)
{
switch(key)
{
case GLUT_KEY_DOWN:
if(FPS>(50+(level*2)))
FPS=FPS-2;
break;

case GLUT_KEY_UP:
FPS=FPS+2;
break;

case GLUT_KEY_LEFT:
if(lrIndex>=0)
{
lrIndex = lrIndex -(FPS/10);
if(lrIndex<0)
{
lrIndex = -1;
}
}
break;

case GLUT_KEY_LEFT:
if(lrIndex<=44)
{
lrIndex = lrIndex -(FPS/10);
if(lrIndex>44)
{
lrIndex = 45;
}
}
break;

default:
break;
}
}

void processKeys(unsigned char key, int x, int y)
{
switch(key)
{
case'';
if(start ==0)
{
start= 1;
gv= 0;
FPS= 50;
roadDivTopMost =0;
roadDivTop =0;
roadDivMd1 =0;
roadDivBtm=0;
lrIndex =0;
car1 =0;
lrIndex1 =0;
car2 =0;
lrIndex2 =0;
car3 =0;
lrIndex3 =0;
score =0;
level =0;
}
}
break;
case 27:
exit(0);
brak;
default:
break;
}
}
void timer(int)
{
glutPostRedisplay();
glutTimerFunc(1000/FPS,timer,0);
}


int main(int argc, char *argv[])
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
glutInitWindowSize(500,650);
glutInitWindowPosition(200,20);
glutCreateWindow("car game");

glutDisplayFunc(display);
glutSpecialFunc(spe_key);
glutKeyboardFunc(processKeys);

glOrtho(0,100,0,100,-1,1);
glClearColor(0.184, 0.310, 0.310, 1);

glutTimerFunc(1000, timer,0);
glutMainLoop();

return 0;
}

