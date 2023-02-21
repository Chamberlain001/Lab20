#include<iostream>
using namespace std;

struct Rect{
	double x,y,w,h;
};

double overlap(Rect *R1, Rect *R2){
	Rect out;
	double area;
	if(R1->x + R1->w < R2->x + R2->w && R1->x + R1->w > R2->x){
		out.w = min(R1->w, R2->w) - abs(R1->x - R2->x);
	}if(R1->x + R1->w > R2->x + R2->w){
		out.w = R2->w;
	}if(R1->x + R1->w < R2->x){
		out.w = 0;
	}if(R1->y + R1->h < R2->y + R2->h){
		out.h = max(R1->h, R2->h) - abs(R1->y - R2->y);
	}if(R1->y + R1->h > R2->y + R2->h){
		out.h = R2->h;
	}if(R1->y + R1->h < R2->y){
		out.h = 0;
	}
	area = out.w * out.h;
	return area;
}