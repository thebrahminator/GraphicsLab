#include<iostream>
#include<graphics.h>
#include<math.h>
#include<conio.h>

using namespace std;

class point{
      public:
      	float x;
      	float y;
      };

void lineDDA(point FirstPoint, point SecondPoint)
{
	float dx = SecondPoint.x - FirstPoint.x;
	float dy = SecondPoint.y - FirstPoint.y;
	int x, steps, y, xInc, yInc;
	if(fabs(dx) < fabs(dy))
	{
		steps = fabs(dy);
	}
	else
	{
		steps = fabs(dx);
	}

	xInc = steps/dx;
	yInc = steps/dy;

	x = floor(FirstPoint.x);
	y = floor(FirstPoint.y);
	putpixel(x,y,WHITE);
	for(int i=0;i<steps;i++)
	{	
		delay(10);
		x = x + xInc;
		y = y + yInc;
		putpixel(x,y,WHITE);
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
 	lineDDA(FirstPoint,SecondPoint);

 	while(!kbhit())
 	{
 		delay(200);
 	}
 	return 0;
 }
