#include <iostream>
using namespace std;

struct Rect
{
	double x, y, w, h;
};

double overlap(Rect* pr1, Rect* pr2)
{

	double x1, x2, y1, y2;

	Rect r1 = *pr1;
	Rect r2 = *pr2;

	if (r2.x < r1.x)
		x1 = r1.x;
	else if (r2.x > r1.x + r1.w)
		x1 = r1.x + r1.w;
	else
		x1 = r2.x;

	if (r2.x + r2.w < r1.x)
		x2 = r1.x;
	else if (r2.x + r2.w > r1.x + r1.w)
		x2 = r1.x + r1.w;
	else
		x2 = r2.x + r2.w;

	if (r2.y > r1.y)
		y1 = r1.y;
	else if (r2.y < r2.y - r2.h)
		y1 = r1.y - r1.h;
	else
		y1 = r2.y;

	if (r2.y - r2.h > r1.y)
		y2 = r1.y;
	else if (r2.y - r2.h < r1.y - r1.h)
		y2 = r1.y - r1.h;
	else
		y2 = r2.y - r2.h;

	double w, h;
	w = x2 - x1;
	h = y1 - y2;

	return w * h;
}
