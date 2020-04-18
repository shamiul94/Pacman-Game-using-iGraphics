# include "iGraphics.h"

int x = 300, y = 300, r = 20 , tem=0 , i=0  , bound_idx = 0 ;
double mx=0 , my=0 ,enemydx=0 , enemydy=0 ,left=60 , bottom=20 , a[3], b[3];
int  food_idx = 0 ;
double pacman_x=70 , pacman_y=50 ;
double initial_x  = 120 , initial_y = 150 ;
double food_x[10]= {120 , 360 , 600 , 750 , 900 , 1000 , 1200 ,450 , 360 ,460 };
double food_y[10]= {120 , 450 , 520 , 340 ,260 , 570 , 70 , 300 , 400 , 200 };
double eat_x , eat_y ;
double enemy_x , enemy_y  ;


int bdr_idx = 0 ;


struct point
{
    double x1 , y1  ;
    double x2 , y2  ;
} border[800]= {};

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
    int i , j ;
    double rshift = 0 , upshift = 0 ;

    for(i=0 ; i<2 ; i++)
    {
        rshift = 0 ;
        iFilledRectangle(left+rshift ,bottom+upshift , 1215 , 15);

        border[bdr_idx].x1 = (left+rshift) ;
        border[bdr_idx].x2 = (left+rshift)+1215 ;
        border[bdr_idx].y1 = (bottom+upshift)+7.5 ;
        border[bdr_idx].y2 = (bottom+upshift)+7.5 ;

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

            border[bdr_idx].x1 = left+rshift ;
            border[bdr_idx].x2 = left+rshift+240 ;
            border[bdr_idx].y1 = bottom+upshift +7.5 ;
            border[bdr_idx].y2 = bottom+upshift +7.5 ;

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

        border[bdr_idx].x1 = 480+x  ;
        border[bdr_idx].x2 = 480+x+350  ;
        border[bdr_idx].y1 = 320+y +7.5 ;
        border[bdr_idx].y2 = 320+y +7.5 ;
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

            border[bdr_idx].x1 = maze_left+rshift  ;
            border[bdr_idx].x2 = maze_left+rshift+350  ;
            border[bdr_idx].y1 = maze_bottom+upshift  + 7.5 ;
            border[bdr_idx].y2 = maze_bottom+upshift  + 7.5 ;

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

            border[bdr_idx].x1 = left+rshift + 7.5 ;
            border[bdr_idx].x2 = left+rshift + 7.5 ;
            border[bdr_idx].y1 = bottom+upshift;
            border[bdr_idx].y2 = bottom+upshift+240;

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

            border[bdr_idx].x1 = left+rshift + 7.5 ;
            border[bdr_idx].x2 = left+rshift + 7.5 ;
            border[bdr_idx].y1 = bottom+upshift ;
            border[bdr_idx].y2 = bottom+upshift+90+15 ;

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
    for(i=1 ; i<=4 ; i++)
    {
        iFilledRectangle(652.5 , bottom+upshift , 15 , 85 );

        border[bdr_idx].x1 = 652.5 + 7.5 ;
        border[bdr_idx].x2 = 652.5 + 7.5 ;
        border[bdr_idx].y1 = bottom+upshift ;
        border[bdr_idx].y2 = bottom+upshift+85 ;


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
int dummy=0 ;
void boundary()
{

    bound_horizontal();
    bound_small_horizontal();
    middle_horizontal();
    maze_4_horizontal();
    bound_vertical();
    bound_small_vertical();
    middle_vertical();
    if(dummy==0)
    {
        printf("%d\n",bdr_idx);
        dummy=1 ;
    }
    bdr_idx = 0 ;
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
    int x  ;
    pacman_x = (initial_x+mx) ;
    x=pacman_x ;
    if(x>0)
        {
            x= x%1275 ;
        }
    if(x < 0 )
        {
            x = (x%1275+1275)%1275;
        }
    pacman_x = x ;
    pacman_y = (initial_y+my) ;

    eat_x = 70+mx ;
    eat_y = 50+my ;


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


int up_collision_detector(double pax , double pay)
{
    int flag =0 ;
    int c = 0 ;

    for(c=0 ; c<28 ; c++)
    {
        /*printf("\n\n%lf %lf\n\n",pax , pay);
        if((((pax>=border[c].x1)&&(pax<=border[c].x2))
                && ((pay+20>=border[c].y1)||(pay-20<=border[c].y1)))

                ||(((pay>=border[c].y1)&&(pay<=border[c].y2))
                   && ((pax-5<=border[c].x1)||(pax+5>=border[c].x1))))
        {
            flag=0 ;
            break ;
        }*/
//        printf("%lf %lf     %lf %lf     %lf %lf",pax , pay , border[c].x1 , border[c].y1 , border[c].x2 ,
//               border[c].y2 );
//        ///up
//        if( (border[c].x1 <= pax && pax <= border[c].x2) && (border[c].y1 <= pay+20 && pay+20 <= border[c].y2) )
//            {
//                flag=1;
//                break;
//            }
//            ///down
//        if( (border[c].x1 <= pax && pax <= border[c].x2) && (border[c].y1 <= pay-25 && pay-25 <= border[c].y2) )
//            {
//                flag=2;
//                break;
//            }
//            ///left
//        if( (border[c].x1 <= pax-25 && pax-25 <= border[c].x2) && (border[c].y1 <= pay && pay <= border[c].y2) )
//            {
//                flag=3;
//                break;
//            }
//            ///right
//        if( (border[c].x1 <= pax+25 && pax+25 <= border[c].x2) && (border[c].y1 <= pay && pay <= border[c].y2) )
//            {
//                flag=4;
//                break;
//            }




        if(((pax>border[c].x1)&&(pax<border[c].x2))&&(pay+5>border[c].y1))
            {flag=1;break;}


    }
    return flag ;
}


int down_collision_detector(double pax , double pay)
{
    int flag =0 ;
    int c = 0 ;

    for(c=0 ; c<28 ; c++)
    {
        /*printf("\n\n%lf %lf\n\n",pax , pay);
        if((((pax>=border[c].x1)&&(pax<=border[c].x2))
                && ((pay+20>=border[c].y1)||(pay-20<=border[c].y1)))

                ||(((pay>=border[c].y1)&&(pay<=border[c].y2))
                   && ((pax-5<=border[c].x1)||(pax+5>=border[c].x1))))
        {
            flag=0 ;
            break ;
        }*/
//        printf("%lf %lf     %lf %lf     %lf %lf",pax , pay , border[c].x1 , border[c].y1 , border[c].x2 ,
//               border[c].y2 );
//        ///up
//        if( (border[c].x1 <= pax && pax <= border[c].x2) && (border[c].y1 <= pay+20 && pay+20 <= border[c].y2) )
//            {
//                flag=1;
//                break;
//            }
//            ///down
//        if( (border[c].x1 <= pax && pax <= border[c].x2) && (border[c].y1 <= pay-25 && pay-25 <= border[c].y2) )
//            {
//                flag=2;
//                break;
//            }
//            ///left
//        if( (border[c].x1 <= pax-25 && pax-25 <= border[c].x2) && (border[c].y1 <= pay && pay <= border[c].y2) )
//            {
//                flag=3;
//                break;
//            }
//            ///right
//        if( (border[c].x1 <= pax+25 && pax+25 <= border[c].x2) && (border[c].y1 <= pay && pay <= border[c].y2) )
//            {
//                flag=4;
//                break;
//            }




            if((pax>border[c].x1&&pax<border[c].x2)&&(pay-5<border[c].y1))
            {flag=2;break;}


    }
    return flag ;
}


int right_collision_detector(double pax , double pay)
{
    int flag =0 ;
    int c = 0 ;

    for(c=0 ; c<28 ; c++)
    {
        /*printf("\n\n%lf %lf\n\n",pax , pay);
        if((((pax>=border[c].x1)&&(pax<=border[c].x2))
                && ((pay+20>=border[c].y1)||(pay-20<=border[c].y1)))

                ||(((pay>=border[c].y1)&&(pay<=border[c].y2))
                   && ((pax-5<=border[c].x1)||(pax+5>=border[c].x1))))
        {
            flag=0 ;
            break ;
        }*/
//        printf("%lf %lf     %lf %lf     %lf %lf",pax , pay , border[c].x1 , border[c].y1 , border[c].x2 ,
//               border[c].y2 );
//        ///up
//        if( (border[c].x1 <= pax && pax <= border[c].x2) && (border[c].y1 <= pay+20 && pay+20 <= border[c].y2) )
//            {
//                flag=1;
//                break;
//            }
//            ///down
//        if( (border[c].x1 <= pax && pax <= border[c].x2) && (border[c].y1 <= pay-25 && pay-25 <= border[c].y2) )
//            {
//                flag=2;
//                break;
//            }
//            ///left
//        if( (border[c].x1 <= pax-25 && pax-25 <= border[c].x2) && (border[c].y1 <= pay && pay <= border[c].y2) )
//            {
//                flag=3;
//                break;
//            }
//            ///right
//        if( (border[c].x1 <= pax+25 && pax+25 <= border[c].x2) && (border[c].y1 <= pay && pay <= border[c].y2) )
//            {
//                flag=4;
//                break;
//            }





        if((pay>border[c].y1&&pay<border[c].y2)&&(pax+5>border[c].x1))
            {flag=3;break;}


    }
    return flag ;
}


int left_collision_detector(double pax , double pay)
{
    int flag =0 ;
    int c = 0 ;

    for(c=0 ; c<28 ; c++)
    {
        /*printf("\n\n%lf %lf\n\n",pax , pay);
        if((((pax>=border[c].x1)&&(pax<=border[c].x2))
                && ((pay+20>=border[c].y1)||(pay-20<=border[c].y1)))

                ||(((pay>=border[c].y1)&&(pay<=border[c].y2))
                   && ((pax-5<=border[c].x1)||(pax+5>=border[c].x1))))
        {
            flag=0 ;
            break ;
        }*/
//        printf("%lf %lf     %lf %lf     %lf %lf",pax , pay , border[c].x1 , border[c].y1 , border[c].x2 ,
//               border[c].y2 );
//        ///up
//        if( (border[c].x1 <= pax && pax <= border[c].x2) && (border[c].y1 <= pay+20 && pay+20 <= border[c].y2) )
//            {
//                flag=1;
//                break;
//            }
//            ///down
//        if( (border[c].x1 <= pax && pax <= border[c].x2) && (border[c].y1 <= pay-25 && pay-25 <= border[c].y2) )
//            {
//                flag=2;
//                break;
//            }
//            ///left
//        if( (border[c].x1 <= pax-25 && pax-25 <= border[c].x2) && (border[c].y1 <= pay && pay <= border[c].y2) )
//            {
//                flag=3;
//                break;
//            }
//            ///right
//        if( (border[c].x1 <= pax+25 && pax+25 <= border[c].x2) && (border[c].y1 <= pay && pay <= border[c].y2) )
//            {
//                flag=4;
//                break;
//            }





        if((pay>border[c].y1&&pay<border[c].y2)&&(pax-5<border[c].x1))
            {flag=4;break;}


    }
    return flag ;
}


int dum = 0 ;
void iDraw()
{
    iClear();

    pacman( mx , my ,tem );
    iSetColor(20, 200, 200);

    iFilledCircle(pacman_x , pacman_y , 20 , 2000 );

    iSetColor(0 , 0,0 );
    if(tem%2)
    {
        iFilledPolygon(a,b,3);
    }
    iSetColor(18 , 0 , 200);
    enemy();
    iSetColor(20, 200, 0);
    boundary();

    if(!dum)
    {
        ///int k ;
        ///FILE *fp ;
        ///fp=fopen("gamefile2.txt","w");
        bdr_idx= 0 ;
        while(bdr_idx<28)
        {
            printf("(%lf , %lf) ; (%lf , %lf)\n",border[bdr_idx].x1,border[bdr_idx].y1,
                   border[bdr_idx].x2,border[bdr_idx].y2);

            bdr_idx++ ;
        }
        bdr_idx = 0 ;
        ///fclose(fp);
        dum=1 ;
    }


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

    printf("Mouse == %d %d",mx,my);

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
	function iSpecialKeyboard() is called whenever user hits special keys like-
	function keys, home, end, pg up, pg down, arrows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
	*/
void iSpecialKeyboard(unsigned char key)
{
    int temp ;
    int dx , dy ;
    dx=mx ;
    dy = my ;
    double temp_x , temp_y;
    if (key == GLUT_KEY_UP)
    {
        dy = my + 21 ;
        temp_x = pacman_x     ;
        temp_y = pacman_y +dy ;
        temp = up_collision_detector(temp_x , temp_y);
        if(temp!=1)
        {
            my+=21 ;
            /*a[0]= 60+mx ;
            b[0]= 70+my  ;
            a[1]= 70+mx ;
            b[1]= 50+my ;
            a[2]= 80+mx ;
            b[2]= 70+my  ;*/
            tem++ ;
        }
    }
    if (key == GLUT_KEY_DOWN)
    {
        dy = my - 21 ;
        temp_x = pacman_x     ;
        temp_y = pacman_y +dy ;
        temp = down_collision_detector(temp_x , temp_y);
        if(temp!=2)
        {
            my-=21 ;
            /*a[0]= 60+mx ;
            b[0]= 30+my ;
            a[1]= 70+mx ;
            b[1]= 50+my ;
            a[2]= 80+mx;
            b[2]= 30+my;*/
            tem++ ;
        }
    }
    if (key == GLUT_KEY_RIGHT)
    {
        dx = mx + 21 ;
        temp_x = pacman_x + dx;
        temp_y = pacman_y     ;
        temp = right_collision_detector(temp_x , temp_y);
        if(temp!=3)
        {
            mx+=21 ;
            /*a[0]= 90+mx ;
            b[0]= 60+my ;
            a[1]= 70+mx ;
            b[1]= 50+my ;
            a[2]= 90+mx;
            b[2]= 40+my;*/
            tem++ ;
        }
    }
    if (key == GLUT_KEY_LEFT)
    {
        dx = mx + 21 ;
        temp_x = pacman_x - dx ;
        temp_y = pacman_y ;
        temp = left_collision_detector(temp_x , temp_y);
        if(temp!=4)
        {
            mx-=21 ;
            /*a[0]= 50+mx ;
            b[0]= 60+my ;
            a[1]= 70+mx ;
            b[1]= 50+my ;
            a[2]= 50+mx ;
            b[2]= 40+my ;*/
            tem++ ;
        }
    }
    printf("\n\n\n%d\n\n",temp );

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
    iInitialize(1300, 800, "demo");

    return 0;
}
