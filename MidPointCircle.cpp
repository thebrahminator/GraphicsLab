#include<iostream>
#include<graphics.h>
#include<stdio.h>
#include<math.h>

using namespace std;

void drawCircle(int x,int y,int xCircle,int yCircle)
{
	putpixel(xCircle+x, yCircle+y,WHITE);
	putpixel(xCircle+x, yCircle-y,WHITE);
	putpixel(xCircle-x, yCircle+y,WHITE);
	putpixel(xCircle-x, yCircle-y,WHITE);

	putpixel(xCircle+y, yCircle+x,WHITE);
	putpixel(xCircle-y, yCircle+x,WHITE);
	putpixel(xCircle+y, yCircle-x,WHITE);
	putpixel(xCircle-y, yCircle-x,WHITE);
}

void MidPointCircle(int xCircle, int yCircle, int radius)
{
	int p,x,y;

	p = 1 - radius;
	x = 0;
	y = radius;

	drawCircle(x,y,xCircle,yCircle);
	while(x<=y)
	{	
		x++;
		if(p<0)
		{
			p = p + 2*x + 1;
		}
		else
		{
			p = p + 2 * (x-y) + 1;
			y--;
		}
		delay(10);
		drawCircle(x,y,xCircle,yCircle);
	}
}

int main(int argc, char const *argv[])
{
	int xCircle, yCircle, radius;

	cout<<"Enter the Mid Point of Circle (x and y): "<<endl;
	cin>>xCircle>>yCircle;

	cout<<"Enter the radius of the circle"<<endl;
	cin>>radius;

	initwindow(800,800);
	MidPointCircle(xCircle,yCircle,radius);

	while(!kbhit())
	{
		delay(200);
	}
	return 0;
}