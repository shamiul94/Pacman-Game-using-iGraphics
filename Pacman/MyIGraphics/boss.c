

# include "iGraphics.h"

int x = 300, y = 300, r = 20 , tem=0 , i=0  , bound_idx = 0 ;
int gvar=0;
double mx=0 , my=0 ,enemydx1=0 , enemydy1=0 ,left=60 , bottom=20 ;
double  a[3], b[3];
int food_idx2 = 0 ;
int  food_idx = 0 ;
double pacman_x=120 , pacman_y=120 ;
double initial_x  = 70 , initial_y = 50 ;
double food_x[10]= {120 , 360 , 600 , 750 , 900 , 1000 , 1200 ,450 , 360 ,460 };
double food_y[10]= {120 , 450 , 520 , 340 ,260 , 570 , 70 , 300 , 400 , 200 };
double food2_x[10]= {400 , 120 , 345 , 140 , 700 , 560 , 560 , 450 , 300 , 360  };
double food2_y[10]= {240 , 400 , 500 ,150 , 570 ,320 ,300 ,700 ,560 ,330  };
double eat_x , eat_y ;
double enemy1_x , enemy1_y  ;
char str[10];

int life = 3 ;

int score=0 ;
int eneatkill = 0;

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

void food()
{
    iSetColor(10 , 134 , 233);


    if(food_idx==10)
    {
        food_idx=0 ;
    }
    food_idx++ ;

}
void food2()
{
    iSetColor(23 , 234  , 155);


    if(food_idx2==10)
    {
        food_idx2=0 ;
    }
    food_idx2++ ;

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
int col =0 ;
int tem1 = 0,tem2 = 0 ,tem3=0 , tem4=0 , tem5=0 , tem6=0 , tem7=0 ,tem8=0 ,tem9=0 ,tem10=0 ,tem11=0 ;

void enemy_1()
{
    //printf("%d %d %d %d %d %d %d %d %d %d %d",tem1 , tem2 , tem3 , tem4 , tem5 , tem6 , tem7 , tem8 , tem9 , tem10 , tem11);
    if(enemy1_x>=1300)
    {
        col++ ;
        enemydx1=0 ;
        enemydy1=0 ;
        tem1 = 0,tem2 = 0 ,tem3=0 , tem4=0 , tem5=0 , tem6=0 , tem7=0 ,tem8=0 ,tem9=0 ,tem10=0 ,tem11=0 ;
    }



    enemy1_x=40+enemydx1 ;
    enemy1_y=760+enemydy1 ;
    if(col%2==0)
    {
        iSetColor(232,89,232);
    }
    else
    {
        iSetColor(255 , 0 , 0);
    }
    iFilledCircle(enemy1_x , enemy1_y , 20 , 6 );
    iSetColor(0,0,0);
    iFilledCircle(enemy1_x+8, enemy1_y+2 , 3 , 50);
    iFilledCircle(enemy1_x-8 , enemy1_y+2 , 3 , 50);
    iFilledEllipse(enemy1_x , enemy1_y-8 , 5 , 2 , 100 );

    if((enemy1_x+30<400&&enemy1_y<800&&enemy1_y>273)&&!tem1)
    {
        enemydx1+=.5;
        if(enemy1_x>380)
            tem1=1 ;
    }
    else if(!(enemy1_y+40<273&&enemy1_x<=420)&&!tem2)
    {
        enemydy1-=.5 ;
        if(enemy1_y+30<=273)
            tem2=1 ;
    }

    else if((enemy1_x+30<600&&enemy1_x+30>220&&enemy1_y>233&&enemy1_y<273)&&!tem3)
    {
        enemydx1+=.5 ;
        if(enemy1_x>610)
            tem3=1 ;
    }
    else if((enemy1_y<670&&enemy1_y>0&&enemy1_x+30<=600&& enemy1_x+30>=220)&&!tem4)
    {
        enemydy1+=.5;
        if(enemy1_y-30>610)
            tem4=1 ;
    }
    else if((enemy1_y>610 &&enemy1_y<800&&enemy1_x>460&&enemy1_x+30<800)&&!tem5)
    {
        enemydx1+=.5;
        if(enemy1_y+30>800)
            tem5=1 ;
    }
    else if((!(enemy1_y+40<273&&enemy1_x<=820)&&!tem6))
    {
        enemydy1-=.5 ;
        if(enemy1_x+30>800)
            tem6=1 ;
    }
    else if((enemy1_x>=750&&enemy1_x+30<=1000&&enemy1_y>=223&&enemy1_y<=273)&&!tem7)
    {
        enemydx1+=.5 ;
        if(enemy1_x+30>1000)
            tem7=1 ;
    }
    else if((enemy1_y<670&&enemy1_y>210&&enemy1_x<=1000&& enemy1_x+30>=820)&&!tem8)
    {
        enemydy1+=.5;
        if(enemy1_y-30>610)
            tem8=1 ;
    }
    else if((enemy1_y>610 &&enemy1_y<800&&enemy1_x>660&&enemy1_x+30<1200)&&!tem9)
    {
        enemydx1+=.5;
        if(enemy1_y+30>1200)
            tem9=1 ;
    }
    else if((!(enemy1_y+40<273&&enemy1_x<=1220)&&!tem10))
    {
        enemydy1-=.5 ;
        if(enemy1_x+30>1220)
            tem10=1 ;
    }
    else if(!tem11)
    {
        enemydx1+=.5;
        if(enemy1_x>=1300)
            tem11=0 ;
    }

}
int var1=0 , var2=0 , var3=0 , var4=0 ;
double enemy2_x , enemy2_y , enemydx2=0 , enemydy2=0 ;
int col2=0  ;
void enemy_2()
{
    if(enemy2_y<=0)
    {
        col2++ ;
        enemydx2=0 ;
        enemydy2=0 ;
        var1 = 0,var2 = 0 ,var3=0 , var4=0  ;
    }

    enemy2_x = 500+enemydx2 ;
    enemy2_y = 1+enemydy2 ;

    if(col2%2==0)
    {
        iSetColor(32,43,45);
    }
    else
    {
        iSetColor(0 , 0 , 255);
    }
    iFilledCircle(enemy2_x,enemy2_y , 25 , 4);
    iSetColor(0,255,0);
    iFilledCircle(enemy2_x-8,enemy2_y+4 ,4 ,  40 );
    iFilledCircle(enemy2_x+8,enemy2_y+4 ,4 ,  40 );
    iFilledEllipse(enemy2_x,enemy2_y-8 ,8 ,  2 );



    if((enemy2_x&&enemy2_y)&&!var1)
    {
        enemydy2+=10;
        if(enemy2_y>=700)
            var1=1 ;
    }
    else if((enemy2_x&&enemy2_y)&&!var2)
    {
        enemydx2+=2 ;
        if(enemy2_x>=700)
            var2=1 ;
    }

    else if((enemy2_x&&enemy2_y)&&!var3)
    {
        enemydy2-=2 ;
        if(enemy2_y<=0)
            var3=1 ;
    }
}


int vari1=0 , vari2=0 , vari3=0 , vari4=0 ;
double enemy3_x =1, enemy3_y=1 , enemydx3=0 , enemydy3=0 ;
int col3=0  ;
void enemy_3()
{
    if(enemy3_y<=0)
    {
        col3++ ;
        enemydx3=0 ;
        enemydy3=0 ;
        vari1 = 0,vari2 = 0 ,vari3=0 , vari4=0  ;
    }

    enemy3_x = 120+enemydx3 ;
    enemy3_y = 1+enemydy3 ;

    if(col3%2==0)
    {
        iSetColor(32,43,45);
    }
    else
    {
        iSetColor(0 , 0 , 255);
    }
    iFilledCircle(enemy3_x,enemy3_y , 25 , 4);
    iSetColor(0,255,0);
    iFilledCircle(enemy3_x-8,enemy3_y+4 ,4 ,  40 );
    iFilledCircle(enemy3_x+8,enemy3_y+4 ,4 ,  40 );
    iFilledEllipse(enemy3_x,enemy3_y-8 ,8 ,  2 );



    if((enemy3_x&&enemy3_y)&&!vari1)
    {
        enemydy3+=1;
        if(enemy3_y>=800)
            vari1=1 ;
    }
    else if((enemy3_x&&enemy3_y)&&!vari2)
    {
        enemydx3+=2 ;
        if(enemy3_x>=300)
            vari2=1 ;
    }

    else if((enemy3_x&&enemy3_y)&&!vari3)
    {
        enemydy3-=2 ;
        if(enemy3_y<=0)
            vari3=1 ;
    }

}


int vary1=0 , vary2=0 , vary3=0 , vary4=0 ;
double enemy4_x =1, enemy4_y=1 , enemydx4=0 , enemydy4=0 ;
int col4=0  ;
void enemy_4()
{
    if(enemy4_y<=0)
    {
        col4++ ;
        enemydx4=0 ;
        enemydy4=0 ;
        vary1 = 0,vary2 = 0 ,vary3=0   ;
    }

    enemy4_x = 900+enemydx4 ;
    enemy4_y = 1+enemydy4 ;

    if(col4%2==0)
    {
        iSetColor(32,43,45);
    }
    else
    {
        iSetColor(0 , 0 , 255);
    }
    iFilledCircle(enemy4_x,enemy4_y , 25 , 4);
    iSetColor(0,255,0);
    iFilledCircle(enemy4_x-8,enemy4_y+4 ,4 ,  40 );
    iFilledCircle(enemy4_x+8,enemy4_y+4 ,4 ,  40 );
    iFilledEllipse(enemy4_x,enemy4_y-8 ,8 ,  2 );



    if((enemy4_x&&enemy4_y)&&!vary1)
    {
        enemydy4+=1;
        if(enemy4_y>=800)
            vary1=1 ;
    }
    else if((enemy4_x&&enemy4_y)&&!vary2)
    {
        enemydx4+=2 ;
        if(enemy4_x>=1100)
            vary2=1 ;
    }

    else if((enemy4_x&&enemy4_y)&&!vary3)
    {
        enemydy4-=2 ;
        if(enemy4_y<=0)
            vary3=1 ;
    }

}

char str2[10];

void score_show()
{
    int num , n ;

    FILE *fp ;
    fp=fopen("gamescore.txt","r");
    while(!feof(fp))
    {
        fscanf(fp,"%d",&num);
    }
    fclose(fp);

    if(score>=num)
    {
        fp=fopen("gamescore.txt","w");
        fprintf(fp,"%d",score);
        fclose(fp);
    }
    itoa( num , str , 10 );
    itoa(score,str2 ,10);

    iSetColor(0 , 0 , 0);
    iText(950,950,"Your Score" , GLUT_BITMAP_TIMES_ROMAN_24);
    iText( 150 , 950 , "Highest Score" , GLUT_BITMAP_TIMES_ROMAN_24 );
    iText( 1000 , 900 , str2 , GLUT_BITMAP_TIMES_ROMAN_24 );
    iText( 200 , 900 , str , GLUT_BITMAP_TIMES_ROMAN_24 );

}


///int dum = 0 ;


double check_x(double pax)
{
    int x ;
    x=pax ;
    if(x>=0)
    {
       pax = x ;
    }
    else
        pax=(x%1300+1300)%1300 ;
    return pax ;
}

double check_y(double pay)
{
    int y ;
    y=pay ;
    if(y>=0)
    {
       pay = y ;
    }
    else
        pay=(y%1000+1000)%1000 ;
    return pay ;
}





void lifeshow(int life)
{
    int j ;
    double chng=0 ;
    for(j=1;j<=life ; j++)
    {
        iSetColor(255,0,0);
        iFilledCircle(570+chng , 950 , 10 , 50);
        chng+=40;
    }
}

void game()
{
    if(life>0)
    {iSetColor(0,255,0);
    iFilledRectangle(0 , 884 , 1300 , 120);
    iSetColor(255,255,255);
    iFilledRectangle(0,0,1300 ,884);

    lifeshow(life);

    pacman( mx , my ,tem );
    iSetColor(255, 255, 0);

    iFilledCircle(pacman_x , pacman_y , 20 , 2000 );
    iSetColor(230 , 45 , 9 );
    iFilledRectangle(200 , 0 , 20 , 610);
    iFilledRectangle(400 , 273 , 20 , 610);
    iFilledRectangle(600 , 0 , 20 , 610);
    iFilledRectangle(800 , 273 , 20 , 610);
    iFilledRectangle(1000 , 0 , 20 , 610);
    iFilledRectangle(1200 , 273 , 20 , 610);


    enemy_1();
    enemy_2();
    enemy_3();
    enemy_4();
    iSetColor(255 , 255,255 );
    if(tem%2)
    {
        iFilledPolygon(a,b,3);
    }
    iSetColor(18 , 0 , 200);

    iSetColor(20, 200, 0);




    ///food start
    iSetColor(123, 45 , 67);
    iFilledCircle(food_x[food_idx], food_y[food_idx] , 10 , 50 );
    iSetColor(23 , 234  , 155) ;
    iFilledCircle(food2_x[food_idx2],food2_y[food_idx2],10 , 50);



    if((((eat_x <= food_x[food_idx]+30) && (eat_x>= food_x[food_idx]-20))
            &&((eat_y <= food_y[food_idx]+30)&&(eat_y>=food_y[food_idx]-20))))
    {
        food_idx++ ;
        score+=50 ;
        if(food_idx==9)
            food_idx=0 ;

    }
    if((((eat_x <= food2_x[food_idx2]+30) && (eat_x>= food2_x[food_idx2]-20))
            &&((eat_y <= food2_y[food_idx2]+30)&&(eat_y>=food2_y[food_idx2]-20))))
    {
        food_idx2++ ;
        score+=100 ;
        if(food_idx2==9)
            food_idx2=0 ;
    }
    ///food end

    ///enemy eat or kill

    if((((pacman_x <= enemy1_x+30) && (pacman_x>= enemy1_x-20))
            &&((pacman_y <= enemy1_y+30)&&(pacman_y>=enemy1_y-20))))
    {
        enemy1_x=1500;
        if(col%2==0)
            score+=500 ;
        else
            {score-=500;
            life-- ;}

    }
    if((((pacman_x <= enemy2_x+30) && (pacman_x>= enemy2_x-20))
            &&((pacman_y <= enemy2_y+30)&&(pacman_y>=enemy2_y-20))))
    {
        enemy2_y=-5;
        if(col2%2==0)
            {score+=1000 ;
            if(life<3)
            {
                life++;
            }}
        else
            score-=1000;

    }
    if((((pacman_x <= enemy3_x+30) && (pacman_x>= enemy3_x-20))
            &&((pacman_y <= enemy3_y+30)&&(pacman_y>=enemy3_y-20))))
    {
        enemy3_y=-5;
        if(col3%2==0)
            score+=400 ;
        else
            {score-=400;
            life--;}

    }
    if((((pacman_x <= enemy4_x+30) && (pacman_x>= enemy4_x-20))
            &&((pacman_y <= enemy4_y+30)&&(pacman_y>=enemy4_y-20))))
    {
        enemy4_y=-2;
        if(col4%2==0)
            score+=400 ;
        else
            {score-=400;
            life-- ;}

    }




    score_show();}
    else
    {
        iSetColor(255,255,0);
        iFilledRectangle(0 , 0 , 1300 , 1000);
        iSetColor(255 , 0 , 0);
        iText(500 , 850 , "GAME OVER",GLUT_BITMAP_TIMES_ROMAN_24);

        iSetColor(0,0,0);
        iText(450 , 700 , "HIGH SCORE:",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(450 , 500 , "YOUR SCORE:",GLUT_BITMAP_TIMES_ROMAN_24);

        iText(650 , 700 , str , GLUT_BITMAP_TIMES_ROMAN_24);
        iText(650 , 500 , str2 , GLUT_BITMAP_TIMES_ROMAN_24);

    }

}

void top()
 {
     iSetcolor(255,255,255);
     iFilledRectangle(0,0,1285,725);
     iText(100,500,"Pacman");
     iText(100,450,"Welcome");
     iText(100,350,"Enter 's' for starting the game" );
     iText(100,250,"Enter 'h' for Showing highscores");

 }

void iDraw()
{

    iClear();

    if(!gvar)
        top();
    else
        game();

//    if(!(((eat_x <= enemy_x+25) && (eat_x>= enemy_x-25) ) &&((eat_y <= enemy_x+25)&&(eat_x>=enemy_y-25))))
//    {
//        enemy_1() ;
//    }

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
    if (key == 's')
    {
        gvar = 1 ;
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
    {if(!(((pacman_x>=400-10&&pacman_x<=420+10)&&(pacman_y-30>=273-70))||
             ((pacman_x>=800-10&&pacman_x<=820+10)&&(pacman_y-30>=273-70))||
             ((pacman_x>=1200-10&&pacman_x<=1220+10)&&(pacman_y-30>=273-70))))
    {


            my+=21 ;
            a[0]= check_x(60+mx) ;
            b[0]= check_y(70+my) ;
            a[1]= check_x(70+mx) ;
            b[1]= check_y(50+my) ;
            a[2]= check_x(80+mx);
            b[2]= check_y(70+my);
            tem++ ;

    }}
    if (key == GLUT_KEY_DOWN)
    {
        if(!(
             ((pacman_x>=200-10&&pacman_x<=220+10)&&(pacman_y-30<=610))||
                ((pacman_x>=600-10&&pacman_x<=620+10)&&(pacman_y-30<=610))||
                ((pacman_x>=1000-10&&pacman_x<=1020+10)&&(pacman_y-30<=610))))

        {
            my-=10 ;
            a[0]= check_x(60+mx) ;
            b[0]= check_y(30+my) ;
            a[1]= check_x(70+mx) ;
            b[1]= check_y(50+my) ;
            a[2]= check_x(80+mx);
            b[2]= check_y(30+my);
            tem++ ;
        }
    }
    if (key == GLUT_KEY_RIGHT)
    {

        if(!((pacman_x+30>200&&pacman_x+30<220)&&(pacman_y+30>0&&pacman_y-20<=600)||
                ((pacman_x+30>400&&pacman_x+30<420)&&(pacman_y+30>300&&pacman_y-20<900))||
                ((pacman_x+30>600&&pacman_x+30<620)&&(pacman_y+30>0&&pacman_y-20<=600))||
                ((pacman_x+30>800&&pacman_x+30<820)&&(pacman_y+30>300&&pacman_y-20<900))||
                ((pacman_x+30>1000&&pacman_x+30<1020)&&(pacman_y+30>0&&pacman_y-20<=600))||
                ((pacman_x+30>1200&&pacman_x+30<1220)&&(pacman_y+30>300&&pacman_y-20<900))))
        {
            mx+=10 ;
            a[0]= check_x(90+mx) ;
            b[0]= check_y(60+my) ;
            a[1]= check_x(70+mx) ;
            b[1]= check_y(50+my) ;
            a[2]= check_x(90+mx);
            b[2]= check_y(40+my);
            tem++ ;
        }
    }
    if (key == GLUT_KEY_LEFT)
    {
        if(!((pacman_x-30>200&&pacman_x-30<220)&&(pacman_y+30>0&&pacman_y-20<=600)||
                ((pacman_x-30>400&&pacman_x-30<420)&&(pacman_y+30>300&&pacman_y-20<900))||
                ((pacman_x-30>600&&pacman_x-30<620)&&(pacman_y+30>0&&pacman_y-20<=600))||
                ((pacman_x-30>800&&pacman_x-30<820)&&(pacman_y+30>300&&pacman_y-20<900))||
                ((pacman_x-30>1000&&pacman_x-30<1020)&&(pacman_y+30>0&&pacman_y-20<=600))||
                ((pacman_x-30>1200&&pacman_x-30<1220)&&(pacman_y+30>300&&pacman_y-20<900))))
        {
            mx-=10 ;
            a[0]= check_x(50+mx) ;
            b[0]= check_y(60+my) ;
            a[1]= check_x(70+mx) ;
            b[1]= check_y(50+my) ;
            a[2]= check_x(50+mx);
            b[2]= check_y(40+my);
            tem++ ;
        }
        printf("%s",str);
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
    iSetTimer(8000 , food2);
    iSetTimer(100,enemy_1);
    tem1 = 0,tem2 = 0 ,tem3=0 , tem4=0 , tem5=0 , tem6=0 , tem7=0 ,tem8=0 ,tem9=0 ,tem10=0 ,tem11=0 ;

    iInitialize(1300, 1000, "demo");

    return 0;
}
