#ifndef ARTICLE_H_INCLUDED
#define ARTICLE_H_INCLUDED

#include <iostream>
#include <string>

class Article
{
    private:
        long nr;
        std::string name;
        double salesPrice;
        static int countObj; // static data members can not be initialized through member initializers
    public:
        // constructors
        Article(long, const std::string&, double);
        // copy constructor
        Article(const Article&);
        // destructor
        ~Article();
        // getter
        long getNumber(void)       const { return nr; }
        std::string getName(void)  const { return name; } // const means return_value can not be modified. this is thus cannot return reference of name..
        double getSalesPrice(void) const { return salesPrice; }
        static int getCount(void)        { return countObj; }
        // setter
        void setNumber(long n)             { nr = n; }
        void setName(const std::string& s) { name = (s.size() > 0)? s : "no name"; }
        void setSalesPrice(double sp)      { salesPrice = (sp > 0.0)? sp : 0.0; }
        // print
        void print(void) const;
};

#endif // ARTICLE_H_INCLUDED
