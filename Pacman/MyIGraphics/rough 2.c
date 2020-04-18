# include "iGraphics.h"

int x = 300, y = 300, r = 20;
double mx , my ;

/*
	function iDraw() is called again and again by the system.

	*/
void boundary()
{
    iFilledRectangle(40, 200, 10, 300);
    iFilledRectangle(40, 20, 10, 90);
    iFilledRectangle(1290, 20, 10, 800);
    iFilledRectangle(40, 20, 1250, 15);
    iFilledRectangle(40, 810, 1250, 12);
    iFilledRectangle(120, 340, 200, 15);
    iFilledRectangle(500, 300, 15, 240);
    iFilledRectangle(400, 200, 150, 15);
}

void pacman(double mx , double my)
{
    double a[3]= {152+mx , 120+mx , 152+mx } , b[3]= {135+my  , 120+my , 105+my } ;
    int mxx , myy ;
    mxx=mx ;
    myy=my ;
    iSetColor(20, 200, 200);
    iFilledCircle(120+mx , 120+my , 18 , 20 );
    iSetColor(0 , 0 ,0 );
    if((mxx%2==0&&myy%2==0)||(mxx%2&&myy%2))
    iFilledPolygon( a, b , 3) ;
}

void iDraw()
{
    double x1=20 , y1=20 , x2 =300, y2=300 ;

    //place your drawing codes here
    iClear();

    ///iRectangle(double left, double bottom, double dx, double dy);

    ////iLine( x1,  y1,  x2,  y2);
    boundary();
    pacman( mx , my  );
    //iFilledRectangle(10, 30, 20, 20);
    iSetColor(20, 200, 0);
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
        x += 10;
        y += 10;
    }
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        //place your codes here
        x -= 10;
        y -= 10;
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

    }
    if (key == GLUT_KEY_DOWN)
    {
        my-=21 ;
    }
    if (key == GLUT_KEY_RIGHT)
    {
        mx+=21 ;
    }
    if (key == GLUT_KEY_LEFT)
    {
        mx-=21 ;
    }

    if(key==GLUT_KEY_END)
    {
        exit(1);
    }
    pacman(mx , my );

    //place your codes for other keys here
}


int main()
{
    //place your own initialization codes here.
    iInitialize(1350, 900, "demo");
    return 0;
}
