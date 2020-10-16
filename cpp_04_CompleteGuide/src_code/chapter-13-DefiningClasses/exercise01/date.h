#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

class Date
{
    private:
        int month, day, year;
    public:
        void init(int, int, int);
        void init(void);
        void print(void);
};


#endif // DATE_H_INCLUDED
