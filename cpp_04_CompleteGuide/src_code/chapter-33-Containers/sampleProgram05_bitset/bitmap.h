#ifndef BITMAP_H_INCLUDED
#define BITMAP_H_INCLUDED

#include <bitset>
#include <stdexcept>
using std::bitset;
using std::invalid_argument;

template<int N>
class Bitmap:public bitset<N>
{
private:
    int lines, cols;
    int ax, ay;
    int ai;
public:
    Bitmap(int l, int c);
    void move(int x, int y);
    void draw(int x, int y);
};


template<int N>
Bitmap<N>::Bitmap(int l, int c)
{
    if(l*c < N)
    {
        reset();
        lines = l; cols = c;
        ax = 0; ay = 0; ai = 0;
    }
    else throw invalid_argument("Invalid argument\n");
}

template<int N>
void Bitmap<N>::move(int x, int y)
{
    if(x>=0 && x < lines && y>=0 && y < cols)
    {
        ax = x; ay = y; ai = x*cols + y;
    }
    else throw invalid_argument("Invalid argument\n");
}

template<int N>
void Bitmap<N>::draw(int x, int y)
{
    if(x >=0 && x < lines && y>=0 && y < cols)
    {
        int savex = x, savey = y;
        if(ax > x)
        {
            int temp = ax; ax = x; x = temp;
            temp = ay; ay = y; y = temp;
        }
        int dx = x - ax, dy = y - ay;
        int xinc = 1, yinc;

        if(dy < 0)
        {
            yinc = -1; dy = -dy;
        }
        else yinc = 1;

        int count = dx + dy;
        int d = (dx - dy) / 2;

        while(count-- > 0)
        {
            ai = ax * cols + ay;
            set(ai);

            if( d < 0)
            {
                ay += yinc; d += dx;
            }
            else
            {
                ax += xinc; d -= dy;
            }
        }
        ax = savex; ay = savey;
        ai = ax * cols + ay;
    }
    else throw invalid_argument("Invalid argument\n");
}


#endif // BITMAP_H_INCLUDED
