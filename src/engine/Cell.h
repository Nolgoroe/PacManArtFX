#ifndef CELL_H
#define CELL_H


class Cell {
   public:
    Cell();
    Cell(int, int, int);
    ~Cell();

    int getType() 
	{
		return type;
	}

    int getX() 
	{
		return x;
	}

    int getY()
    {
        return y;
    }

    void getxy(int *, int*);
	void setType(int);

   private:
   int type;
   int x;
   int y;
};

#endif
