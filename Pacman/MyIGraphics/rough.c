# include "iGraphics.h"

int x = 300, y = 300, r = 20;
double mx , my ;
double enemydx=0 , enemydy=0 ;
int i=0 ;

double left=60 , bottom=20 ;

int a[80], b[80];

void bound_horizontal() ;
void bound_vertical() ;
void bound_small_horizontal() ;
void bound_small_vertical() ;
void boundary() ;
void sixteen() ;

/*
	function iDraw() is called again and again by the system.

	*/
void sixteen()
{

}

void bound_horizontal()
{
    iFilledRectangle(left, bottom , 1200 , 15);///nicher ta
    iFilledRectangle(left, bottom+735 , 1200 , 15 );///uprer ta
}

void bound_vertical()
{
    int i , j ;
    double rshift = 0 , upshift = 0 ;
    for(i=1 ; i<=2 ; i++)
    {
        rshift = 0 ;
        for(j=0 ; j<2 ; j++)
        {
            iFilledRectangle(left+rshift ,bottom+upshift , 15 , 240);
            rshift=1200 ;
        }
        upshift=510 ;
    }
}

void bound_small_horizontal()
{
    int i , j ;
    double rshift = 0 , upshift = 240 , updiff ;
    for(i=1 ; i<=4 ; i++)
    {
        rshift = 0 ;
        updiff = 90 ;
        for(j=0 ; j<2 ; j++)
        {
            iFilledRectangle(left+rshift ,bottom+upshift , 240 , 15);
            rshift=720+240+15 ;
        }
        upshift = upshift+updiff ;
    }
}

void bound_small_vertical()
{
    int i , j ;
    double rshift = 240-15 , upshift = 240 , updiff ;
    for(i=1 ; i<=2 ; i++)
    {
        rshift = 240-15 ;
        updiff = 90 * 2;
        for(j=0 ; j<2 ; j++)
        {
            iFilledRectangle(left+rshift ,bottom+upshift , 15 , 90+15);
            rshift=rshift+720+15 ;
        }
        upshift = upshift+updiff ;
    }
}

void boundary()
{
    bound_horizontal();
    bound_small_horizontal();
    bound_small_vertical();
    bound_vertical();
}

void middle_vertical()
{
    int i , j ;
    double upshift=0 ;
    for(i=1 ; i<=4 ; i++)
    {
        iFilledRectangle(652.5 , bottom+upshift , 15 , 85 );
        if(i==1||i==3)
            upshift=upshift+85+63 ;
        else if(i==2)
            upshift=upshift+85+270 ;
    }
}



void pacman(double mx , double my)
{
    double a[3]= {152+mx , 120+mx , 152+mx } , b[3]= {135+my  , 120+my , 105+my } ;
    int mxx , myy ;
    mxx=mx ;
    myy=my ;
    iSetColor(20, 200, 200);
    iFilledCircle(70+mx , 50+my , 20 , 20 );
    iSetColor(0 , 0 ,0 );
    if((mxx%2==0&&myy%2==0)||(mxx%2&&myy%2))
        iFilledPolygon( a, b , 3) ;
}


void enemy()
{

    double x , y  ;
    x=40+enemydx ;
    y=40+enemydx ;
    iSetColor(232,232,232);
    iFilledRectangle(x , y , 50 , 50);
    iSetColor(0,0,0);
    iFilledRectangle(x+2 , y+2 , 10 ,10);
    if(i%5)
    {
        enemydx+=.2 ;
    }
    else
    {
        enemydx+=2 ;
    }
    i++ ;

}

void iDraw()
{
    double x1=20 , y1=20 , x2 =300, y2=300 ;

    //place your drawing codes here
    iClear();

    ///iRectangle(double left, double bottom, double dx, double dy);

    ////iLine( x1,  y1,  x2,  y2);
///    boundary();
    pacman( mx , my  );
    ///iSetColor(18 , 0 , 200);
    enemy();
    //iFilledRectangle(10, 30, 20, 20);
    iSetColor(20, 200, 0);
    boundary();
    middle_vertical();
    iText(40, 40, "Hi, I am iGraphics");
}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouseMove(int mx, int my)
{
    printf("x = %d, y= %d\n",mx,my);
    //place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouse(int button, int state, int mx, int my)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        //place your codes here
        //	printf("x = %d, y= %d\n",mx,my);
        x += 11;
        y += 11;
    }
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        //place your codes here
        x -= 11;
        y -= 11;
    }
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
	*/
void iKeyboard(unsigned char key)
{
    if (key == 'q')
    {
        exit(0);
    }
    //place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
	*/
void iSpecialKeyboard(unsigned char key)
{

     if (key == GLUT_KEY_UP)
    {
        my+=21 ;
        a[0]=60+mx ;
        b[0]= 70+my  ;
        a[1]= 70+mx ;
        b[1]= 50+my ;
        a[2]= 80+mx ;
        b[2]= 70+my  ;
        tem++ ;
    }
    if (key == GLUT_KEY_DOWN)
    {
        my-=21 ;
        a[0]= 60+mx ;
        b[0]= 30+my ;
        a[1]= 70+mx ;
        b[1]= 50+my ;
        a[2]= 80+mx;
        b[2]= 30+my;
        tem++ ;
    }
    if (key == GLUT_KEY_RIGHT)
    {
        mx+=21 ;
        a[0]= 90+mx ;
        b[0]= 60+my ;
        a[1]= 70+mx ;
        b[1]= 50+my ;
        a[2]= 90+mx;
        b[2]= 40+my;
        tem++ ;
    }
    if (key == GLUT_KEY_LEFT)
    {
        mx-=21 ;
        a[0]= 50+mx ;
        b[0]= 60+my ;
        a[1]= 70+mx ;
        b[1]= 50+my ;
        a[2]= 50+mx ;
        b[2]= 40+my ;
        tem++ ;
    }

    if(key==GLUT_KEY_END)
    {
        exit(1);
    }
    pacman(mx , my  ,tem );

    //place your codes for other keys here
}


int main()
{
    //place your own initialization codes here.
    iInitialize(1350, 900, "demo");
    return 0;
}
