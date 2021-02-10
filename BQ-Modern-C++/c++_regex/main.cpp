/*

modern c++ review

@ZL, 20210210

*/

#include <iostream>
#include <regex>
#include <string>

int main()
{
    {
        /*

        + regex
            - P(attern)
                meta: abstract characters
                >> \d,  \D
                >> \w,  \W
                >> \s,  \S

                meta: quantitifier
                >> (), a group of charaters
                >> [], a set of characters
                >> {}, number of characters

                meta: quantitifier
                >> +, 1~inf
                >> *, 0~inf
                >> ?, 0 or 1
                >> ., anything
                >> |, or
                >> \\, escape

                meta: constraints
                >> ^, must start with
                >> $, must end with

            - S(earch)
            - R(esult)

        */

        std::string raw_str;
        std::string p = "abc[de]*";
        std::regex  e;
        bool match;

        std::cout << "pattern: " << p << std::endl;
        while(true)
        {
            std::cin >> raw_str;
            e = std::regex{p};
            match = std::regex_match(raw_str, e);
            std::cout << (match? "matched" : "unmatched") << std::endl << std::endl;
        }
    }


    return 0;
}
