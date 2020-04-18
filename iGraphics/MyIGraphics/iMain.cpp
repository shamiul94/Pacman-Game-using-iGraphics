#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include "iGraphics.h"


int arr[10] , tem[6];

void horizontal(double x , double y , int i);
void vertical(double x , double y , int i);
void gettime(int t[]);
void colon();


void vertical(double x , double y , int i)
{
    double s;
    if(i%2==0)
        s=194+40;
    else
        s=184+40;
    double ax[6]={i*s+x,i*s+x+5,i*s+x+5,i*s+x,i*s+x-5,i*s+x-5};
    double ay[6]={y,y+10,y+190,y+200,y+190,y+10};

    iFilledPolygon(ax , ay , 6);
}

void horizontal(double x , double y , int i)
{
    double s;
    if(i%2==0)
        s=194+40;
    else
        s=184+40;
    double ax[6]={i*s+x,i*s+x+10,i*s+x+150,i*s+x+160,i*s+x+150,i*s+x+10};
    double ay[6]={y,y+5,y+5,y,y-5,y-5};

    iFilledPolygon(ax , ay , 6);
}
void gettime(int t[])
{
    int am=1 , tem ;
    time_t ctime;
    struct tm * current;
    time ( &ctime );
    current = localtime ( &ctime );
    t[0] = current->tm_hour;
    t[1] = current->tm_min;
    t[2] = current->tm_sec;
    tem=t[0];
    if(tem>=12)
        am=0 ;
    if(am==1)
        iText(1299,59,"AM",GLUT_BITMAP_HELVETICA_18);
    else
        iText(1299,59,"PM");

    if(t[0]==0)
        t[0]=12;
    else if(t[0]>12)
        t[0]=t[0]-12;
    arr[0]=t[0]/10;
    arr[1]=t[0]%10;
    arr[2]=t[1]/10;
    arr[3]=t[1]%10;
    arr[4]=t[2]/10;
    arr[5]=t[2]%10;
}

void colon()
{
    iFilledCircle(463,473,10,20);
    iFilledCircle(463,193,10,20);
    iFilledCircle(921,473,10,20);
    iFilledCircle(921,193,10,20);
}


void iDraw()
{
    int i ;
    iClear();
    iSetColor(255,255,255);
    iFilledRectangle(0,0,1350,700);
    iSetColor(255,0,0);
    colon();
    gettime(tem);
    for(i=0 ; i<6 ; i++)
    {
        if(arr[i]==0)
        {
            horizontal(40,526,i);
            horizontal(40,120,i);
            vertical(38,324,i);
            vertical(38,120,i);
            vertical(202,120,i);
            vertical(202,324,i);
        }
        else if(arr[i]==1)
        {
            vertical(202,120,i);
            vertical(202,324,i);
        }
        else if(arr[i]==2)
        {
            horizontal(40,526,i);
            horizontal(40,322,i);
            horizontal(40,120,i);
            vertical(38,120,i);
            vertical(202,324,i);
        }
        if(arr[i]==3)
        {
            horizontal(40,526,i);
            horizontal(40,322,i);
            horizontal(40,120,i);
            vertical(202,120,i);
            vertical(202,324,i);
        }
        if(arr[i]==4)
        {
            horizontal(40,322,i);
            vertical(38,324,i);
            vertical(202,120,i);
            vertical(202,324,i);
        }
        if(arr[i]==5)
        {
            horizontal(40,526,i);
            horizontal(40,322,i);
            horizontal(40,120,i);
            vertical(38,324,i);
            vertical(202,120,i);
        }
        if(arr[i]==6)
        {
            horizontal(40,526,i);
            horizontal(40,322,i);
            horizontal(40,120,i);
            vertical(38,324,i);
            vertical(38,120,i);
            vertical(202,120,i);
        }
        if(arr[i]==7)
        {
            horizontal(40,526,i);
            vertical(202,120,i);
            vertical(202,324,i);
        }
        if(arr[i]==8)
        {
            horizontal(40,526,i);
            horizontal(40,322,i);
            horizontal(40,120,i);
            vertical(38,324,i);
            vertical(38,120,i);
            vertical(202,120,i);
            vertical(202,324,i);
        }
        if(arr[i]==9)
        {
            horizontal(40,526,i);
            horizontal(40,322,i);
            horizontal(40,120,i);
            vertical(38,324,i);
            vertical(202,120,i);
            vertical(202,324,i);
        }
    }

}

void iMouseMove(int mx, int my)
{

}

void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		printf("x=%d y=%d\n",mx , my);
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{

	}
}

void iKeyboard(unsigned char key)
{
	if(key == 'x')
	{
		exit(0);
	}
}

void iSpecialKeyboard(unsigned char key)
{
    if(key==GLUT_KEY_END)
    {
        exit(0);
    }
}

int main()
{
    iSetColor(0 , 255 , 0);
    iInitialize(1350 , 700 , "7segment watch/RUMMAN/1505038" );
    return 0 ;
}
