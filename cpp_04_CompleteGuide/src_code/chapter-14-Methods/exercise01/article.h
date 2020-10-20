#ifndef ARTICLE_H_INCLUDED
#define ARTICLE_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

int cnt = 0; // global variable thou..

class Article
{
    private:// data members
        long articleNumber;
        string articleName;
        double salesPrice;
        // static int cnt = 0; // exception.. in C++
    public:
        // constructor, destructor
        Article(long, const string&, double);
        ~Article(void);
        // repr
        void print(void);
        // getter
        long getNumber()  const { return articleNumber; }
        string getName()  const { return articleName; }
        double getPrice() const { return salesPrice; }
        // setter
        void setNumber(long n)  { articleNumber = n; }
        void setName(string s)  { articleName = s; }
        void setPrice(double p) { salesPrice = p; }

};

inline Article::Article(long n = 111111,
                        const string& s = "hello world",
                        double p = 0.0)
{

    this->articleNumber = n;
    this->articleName   = s;
    if(!(p < 0))
        this->salesPrice = p;
    else
        this->salesPrice = 0;
    ++cnt;

    cout << "\nAn object of type Article " << this->articleName << " is created." << endl
         << "this is the " << cnt  << " Article." << endl;
}

inline Article::~Article()
{
    --cnt;
    cout << "\nthe object of type Article " << this->articleName << " is destroyed." << endl
         << "there are still " << cnt << " articles." << endl;
}

inline void Article::print()
{
    cout << "\nArticle Number: " << articleNumber << endl
         << "Article Name:   " << articleName   << endl
         << "Sales price :   " << salesPrice    << endl;
}

#endif // ARTICLE_H_INCLUDED
