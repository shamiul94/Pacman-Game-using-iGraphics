# include "iGraphics.h"

int x = 300, y = 300, r = 20 , tem=0 , i=0  , bound_idx = 0 ;
double mx=0 , my=0 ,enemydx=0 , enemydy=0 ,left=60 , bottom=20 , a[3], b[3];
int  food_idx = 0 ;
double pacman_x=120 , pacman_y=120 ;
double initial_x  = 70 , initial_y = 50 ;
double food_x[10]= {120 , 360 , 600 , 750 , 900 , 1000 , 1200 ,450 , 360 ,460 };
double food_y[10]= {120 , 450 , 520 , 340 ,260 , 570 , 70 , 300 , 400 , 200 };
double eat_x , eat_y ;
double enemy_x , enemy_y  ;
int bdr_idx = 0 ;


int flag = 1 ;


struct point
{
    double x ;
    double y ;
} border[800];

typedef struct point bdr ;

void bound_horizontal() ;
void bound_vertical() ;
void bound_small_horizontal() ;
void bound_small_vertical() ;
void boundary() ;
void food();
void maze_4_horizontal() ;


void bound_horizontal()
{
    int bx1 , bx2 , by1  , by2 ;

    int i , j ;
    double rshift = 0 , upshift = 0 ;

    for(i=0 ; i<2 ; i++)
    {
        rshift = 0 ;
        iFilledRectangle(left+rshift ,bottom+upshift , 1215 , 15);

        border[bdr_idx].x = (left+rshift)+i*1215 ;
        border[bdr_idx].y = (bottom+upshift)+7.5 ;

        upshift=750 ;
        bdr_idx++ ;

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

            border[bdr_idx].x = left+rshift+ j*240 ;
            border[bdr_idx].y = bottom+upshift +7.5 ;

            rshift=720+240+15 ;
            bdr_idx ++ ;
        }
        upshift = upshift+updiff ;
    }
}


void middle_horizontal()
{
    int j ;
    double mid_x , mid_y , x=0 , y=0;
    for(j=0 ; j<2 ; j++)
    {
        iFilledRectangle( 480+x ,320 +y , 350 , 15);

        border[bdr_idx].x = 480+x + j*350 ;
        border[bdr_idx].y = 320+y +7.5 ;
        y+=125;

        bdr_idx++ ;
    }
}

void maze_4_horizontal()
{
    int i , j ;
    double maze_left = 180 , maze_bottom = 0 ;

    double rshift = 0 , upshift = 140 , updiff ;
    for(i=1 ; i<=2 ; i++)
    {
        rshift = 0 ;
        updiff = 500 ;
        for(j=0 ; j<2 ; j++)
        {
            iFilledRectangle(maze_left+rshift ,maze_bottom+upshift , 350 , 15);

            border[bdr_idx].x = maze_left+rshift + j*350  ;
            border[bdr_idx].y = maze_bottom+upshift  + 7.5 ;

            rshift=600 ;

            bdr_idx++ ;
        }
        upshift = upshift+updiff ;
    }
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

            border[bdr_idx].x = left+rshift +  7.5 ;
            border[bdr_idx].y = bottom+upshift + j * 240 ;

            rshift=1200 ;

            bdr_idx++ ;
        }
        upshift=510 ;
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

            border[bdr_idx].x = left+rshift  + 7.5 ;
            border[bdr_idx].y = bottom+upshift + j*105 ;

            rshift=rshift+720+15 ;


            bdr_idx++ ;
        }
        upshift = upshift+updiff ;
    }
}

void middle_vertical()
{
    int i , j  , m = 0;
    double upshift=0 ;
    for(i=0 ; i<4 ; i++)
    {
        iFilledRectangle(652.5 , bottom+upshift , 15 , 85 );

        border[bdr_idx].x = 652.5 + 7.5 ;
        border[bdr_idx].y = bottom+upshift + m*85 ;

        if(m==1)
            m=0 ;

        m++ ;

        bdr_idx++ ;

        if(i==1||i==3)
            upshift=upshift+85+70 ;
        else if(i==2)
            upshift=upshift+85+270 ;
    }
}








void boundary()
{
    bound_horizontal();
    bound_small_horizontal();
    bound_small_vertical();
    bound_vertical();
    maze_4_horizontal();
    middle_horizontal();
}



void food()
{
    iSetColor(10 , 134 , 233);


    if(food_idx==10)
    {
        food_idx=0 ;
    }
    food_idx++ ;

}


void pacman(double mx , double my ,int tem)
{
    /*int mxx , myy ;
    mxx=mx ;
    myy=my ;*/
    int x  , y ;
    y=pacman_y ;

    pacman_x = (initial_x+mx) ;
    x=pacman_x ;


    if(y<430 && y>370)

    {if(x>0)
    {
        x= x%1275 ;
    }
    if(x < 0 )
    {
        x = (x%1275+1275)%1275;
            //x= 1275+x;
        //x= (x)%1275 ;
    }


    }
    pacman_y = y ;
     pacman_x = x ;
   pacman_y = (initial_y+my) ;


    /*///if( pacman_x < 60 && pacman_y >= 370 && pacman_y <= 430 )
    {
        initial_x = 1275 ;
        mx = 0  ;
        my = 0  ;

    }
    ///else if( pacman_x > 1275 && pacman_y >=370 && pacman_y <= 430 )
    {
        initial_x = 60 ;
        mx = 0  ;
        my = 0  ;

    }*/
    /* pacman_x = initial_x+mx ;
     pacman_y = initial_y+my ;*/



    eat_x = 70+mx ;
    eat_y = 50+my ;

    iSetColor(0 , 0 ,0 );
    if(tem%2)
    {
        iFilledPolygon(a,b,3);
    }
    tem++ ;
}

int sign = 1 ;



void enemy()
{

    enemy_x=40+enemydx  * sign ;
    enemy_y=40+enemydy ;

    sign = (enemy_x >=1275)? (-1):1 ;

    sign = (enemy_x<=40) ? (1):(-1) ;


    iSetColor(232,232,232);
    iFilledCircle(enemy_x , enemy_y , 20 , 6 );
    iSetColor(0,0,0);
    iFilledCircle(enemy_x+8, enemy_y+2 , 3 , 50);
    iFilledCircle(enemy_x-8 , enemy_y+2 , 3 , 50);
    iFilledEllipse(enemy_x , enemy_y-8 , 5 , 2 ,  100 );

    if(i%5)
    {
        enemydx+=.5 ;
    }
    else
    {
        enemydy+=0 ;
    }
    i++ ;
}

int enemy_terminator(int flag)
{

}


/*int transfer(int eat_x , int eat_y)
{
    if(eat_x<=60&&eat_y>=410&&eat_y<=480)
    {
        eat_x = 1275 ;
    }
    else if(eat_x>=1275&&eat_y>=410&&eat_y<=480)
    {
        eat_x = 410 ;
    }
}*/

void iDraw()
{
    iClear();

    pacman( mx , my ,tem );

    iSetColor(20, 200, 200);
    iFilledCircle(pacman_x , pacman_y , 20 , 2000 );
    iSetColor(18 , 0 , 200);
    enemy();
    iSetColor(20, 200, 0);
    boundary();
    middle_vertical();

    ///food start
    iSetColor(123, 45 , 67);
    iFilledCircle(food_x[food_idx], food_y[food_idx] , 10 , 50 );

    if((((eat_x <= food_x[food_idx]+30) && (eat_x>= food_x[food_idx]-20))
            &&((eat_y <= food_y[food_idx]+30)&&(eat_y>=food_y[food_idx]-20))))
    {
        ///iSetColor(0,0,0);
        ///iFilledCircle(food_x[food_idx], food_y[food_idx] , 10 , 50 );
        food_idx++ ;
        if(food_idx==9)
            food_idx=0 ;
    }
    ///food end

    if(!(((eat_x <= enemy_x+25) && (eat_x>= enemy_x-25) ) &&((eat_y <= enemy_x+25)&&(eat_x>=enemy_y-25))))
    {
        enemy() ;
    }

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
    int cnt ;
    bdr_idx = 0 ;

    /*for(cnt =bdr_idx ; cnt <= bdr_idx+1 ; cnt++ )

   {

    if ((pacman_x+25) > (border[bdr_idx].x ) && (pacman_x +25 < border[bdr_idx+1].x)&&

       (pacman_y > border[bdr_idx].y)||(pacman_y < border[bdr_idx+1].y))
    {
        flag = 0 ;
    }
    bdr_idx ++ ;

   }*/
    //if(flag==0)
    {if (key == GLUT_KEY_UP)
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
    }}

    if(key==GLUT_KEY_END)
    {
        exit(1);
    }
    pacman(mx , my  ,tem );
}


int main()
{
    //place your own initialization codes here.
    iSetTimer(12000 , food);
    iInitialize(1350, 900, "demo");
    return 0;
}
