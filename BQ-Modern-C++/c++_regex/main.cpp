/*

modern c++ review

@ZL, 20210210

*/

#include <iostream>
#include <regex>
#include <string>

int main()
{
    // regex
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

//        std::string raw_str;
//        std::string p = "abc[de]*";
//        std::regex  e;
//        bool match;
//
//        std::cout << "pattern: " << p << std::endl;
//        while(true)
//        {
//            std::cin >> raw_str;
//            e = std::regex{p};
//            match = std::regex_match(raw_str, e);
//            std::cout << (match? "matched" : "unmatched") << std::endl << std::endl;
//        }
    }


    // regex_iterator, pointing to match results
    {
        std::string raw_text = "ZL@gmail.com; ZhangLiang@live.com; XY123@163.com";
        std::regex e("([[:w:]]+)@([[:w:]]+)\.com");

        // using ordinary regex grammer, not work well
//        std::smatch m;
//        bool found = std::regex_search(raw_text, m, e);
//        for(int i=0; i<m.size(); ++i)
//            std::cout << "m[" << i << "]: str()=" << m[i].str() << std::endl;

        // using regex_iterator

        std::sregex_iterator pos(raw_text.cbegin(), raw_text.cend(), e);
        std::sregex_iterator end_;
        for(; pos != end_; ++pos)
        {
            std::cout << "Matched   : " << pos->str(0) << std::endl;
            std::cout << "user name : " << pos->str(1) << std::endl;
            std::cout << "domain    : " << pos->str(2) << std::endl;
            std::cout << std::endl;
        }

        std::cout << "================\n\n";
    }

    // regex_token_iterator, pointing to submatch(each iterator contains exact one submatch)
    {
        std::string raw_text = "ZL@gmail.com; ZhangLiang@live.com; XY123@163.com";
        std::regex e("([[:w:]]+)@([[:w:]]+)\.com");

        // std::sregex_token_iterator pos(raw_text.cbegin(), raw_text.cend(), e);
        std::sregex_token_iterator pos(raw_text.cbegin(), raw_text.cend(), e, 1);   // <-- the last arg specifies what to extract, -1(not match), 0(by default), 1(grp1), 2(grp2), ...;
        std::sregex_token_iterator end_;
        for(; pos != end_; ++pos)
        {
            std::cout << "Matched   : " << pos->str() << std::endl;
            std::cout << std::endl;
        }

        std::cout << "================\n\n";


    }

    // regex_replace
    {
        std::string raw_text = "ZL@gmail.com; ZhangLiang@live.com; XY123@163.com";
        std::regex e("([[:w:]]+)@([[:w:]]+)\.com", std::regex_constants::icase);

        std::cout << std::regex_replace(raw_text, e, "$1 is on $2", std::regex_constants::format_no_copy | std::regex_constants::format_first_only);

        std::cout << "\n\n================\n\n";
    }


    return 0;
}
