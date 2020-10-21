#include <iostream>
#include <string>
#include "article.h"

// data members
int Article::countObj = 0;

// constructors
Article::Article(long n, const std::string& s, double sp)
: nr(n), name(s), salesPrice(sp)
{
    //nr = n; name = s; salesPrice = sp;
    ++countObj;
    std::cout << "An article \"" << name
              << "\" is created. \n"
              << "This is the " << countObj << ". article!"
              << std::endl;
}
// copy constructor
Article::Article(const Article& anArticle)
: nr(anArticle.nr), name(anArticle.name), salesPrice(anArticle.salesPrice)
{
    ++countObj;
    std::cout << "A copy of the article \"" << name
              << "\" is generated.\n"
              << "This is the " << countObj << ". article!"
              << std::endl;
}
// destructor
Article::~Article()
{
    std::cout << "The article \"" << name
              << "\" is destroyed.\n"
              << "There are still " << --countObj << " articles!"
              << std::endl;
}

// other method
void Article::print() const
{
    std::cout << "article number: " << nr         << '\n'
              << "article name  : " << name       << '\n'
              << "sales price   : " << salesPrice << std::endl;
}
