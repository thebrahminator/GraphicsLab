#include<iostream>
#include<stdio.h>
#include<graphics.h>
#include<math.h>

using namespace std;

class point{
	public:
		float x;
		float y;
};

void lineBresenham(point FirstPoint, point SecondPoint)
{
	float dx,dy;
	int p,x,y;

	dx = SecondPoint.x - FirstPoint.x;
	dy = SecondPoint.y - FirstPoint.y;

	p = (int)(2*dy-dx);
	x = (int)FirstPoint.x;
	y = (int)FirstPoint.y;
	while(x<SecondPoint.x)
	{
		if(p>=0)
		{	
			delay(10);
			putpixel(x,y,WHITE);
			y = y+1;
			p = p + 2*(dy-dx);
		}
		else
		{	
			delay(10);
			putpixel(x,y,WHITE);
			p = p + 2 * dy;

		}
		x++;
	}
}

 int main(int argc, char const *argv[])
 {
 	point FirstPoint, SecondPoint;
 	cout<<"Enter x and y for first point"<<endl;
 	cin>>FirstPoint.x>>FirstPoint.y;

 	cout<<"Enter x and y for second point"<<endl;
 	cin>>SecondPoint.x>>SecondPoint.y;

 	int gd=DETECT, gm;
 	initwindow(800,800);
 	lineBresenham(FirstPoint,SecondPoint);

 	while(!kbhit())
 	{
 		delay(200);
 	}
 	return 0;
 }