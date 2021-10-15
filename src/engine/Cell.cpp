# include "Cell.h"

Cell::Cell()
{
    Cell(0,0,0);
}

Cell::~Cell() 
{

}

Cell::Cell(int inX,int inY,int inT) 
{
	x=inX;
	y=inY;
	type=inT;
}

void Cell::setType(int t) 
{
	type=t;
}

void Cell::getxy(int *mx,int *my) 
{
	*mx=x;
	*my=y;
}